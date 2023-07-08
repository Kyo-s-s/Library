template<class M> class DynamicSegtree {
  public:
    using S = typename M::T;

    DynamicSegtree() : DynamicSegtree(LONG_LONG_MAX / 2) {}
    DynamicSegtree(long long limit) : limit(limit), root(nullptr) {}

    void set(long long p, S x) {
        set(root, 0, limit, p, x);
    }

    S get(long long p) const {
        return get(root, 0, limit, p);
    }

    S prod(long long l, long long r) const {
        assert(l <= r);
        return prod(root, 0, limit, l, r);
    }

    S all_prod() const { return root ? root->product : M::e(); }

    void reset(long long l, long long r) {
        assert(l <= r);
        return reset(root, 0, limit, l, r);
    }

  private:
    struct node;
    using node_ptr = std::unique_ptr<node>;

    struct node {
        long long index;
        S value, product;
        node_ptr left, right;

        node(long long index, S value)
            : index(index),
              value(value),
              product(value),
              left(nullptr),
              right(nullptr) {}

        void update() {
            product = M::op(M::op(left ? left->product : M::e(), value),
                         right ? right->product : M::e());
        }
    };

    long long limit = LONG_LONG_MAX / 2;
    node_ptr root;

    void set(node_ptr& t, long long a, long long b, long long p, S x) const {
        if (!t) {
            t = std::make_unique<node>(p, x);
            return;
        }
        if (t->index == p) {
            t->value = x;
            t->update();
            return;
        }
        long long c = (a + b) >> 1;
        if (p < c) {
            if (t->index < p) std::swap(t->index, p), std::swap(t->value, x);
            set(t->left, a, c, p, x);
        } else {
            if (p < t->index) std::swap(p, t->index), std::swap(x, t->value);
            set(t->right, c, b, p, x);
        }
        t->update();
    }

    S get(const node_ptr& t, long long a, long long b, long long p) const {
        if (!t) return M::e();
        if (t->index == p) return t->value;
        long long c = (a + b) >> 1;
        if (p < c) return get(t->left, a, c, p);
        else return get(t->right, c, b, p);
    }

    S prod(const node_ptr& t, long long a, long long b, long long l, long long r) const {
        if (!t || b <= l || r <= a) return M::e();
        if (l <= a && b <= r) return t->product;
        long long c = (a + b) >> 1;
        S result = prod(t->left, a, c, l, r);
        if (l <= t->index && t->index < r) result = M::op(result, t->value);
        return M::op(result, prod(t->right, c, b, l, r));
    }

    void reset(node_ptr& t, long long a, long long b, long long l, long long r) const {
        if (!t || b <= l || r <= a) return;
        if (l <= a && b <= r) {
            t.reset();
            return;
        }
        long long c = (a + b) >> 1;
        reset(t->left, a, c, l, r);
        reset(t->right, c, b, l, r);
        t->update();
    }
};
