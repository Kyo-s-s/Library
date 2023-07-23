template <class M, class O, auto fn> struct LazySegtree {
    using S = typename M::T;
    using F = typename O::T;
    static_assert(is_convertible_v<decltype(fn), std::function<S(F, S)>>);

  public:
    LazySegtree() : LazySegtree(0) {}
    LazySegtree(int n) : LazySegtree(std::vector<S>(n, M::e())) {}
    LazySegtree(const std::vector<S>& v) : n(int(v.size())) {
        while ((1 << log) < n) log++;
        size = 1 << log;
        d = vector<S>(2 * size, M::e());
        lz = vector<F>(size, O::e());
        for (int i = 0; i < n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return M::e();
        l += size; r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }
        S sml = M::e(), smr = M::e();
        while (l < r) {
            if (l & 1) sml = M::op(sml, d[l++]);
            if (r & 1) smr = M::op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return M::op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = fn(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        l += size; r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1; r >>= 1;
            }
            l = l2; r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

  private:
    int n, size, log = 0;
    vector<S> d;
    vector<F> lz;

    void update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = fn(f, d[k]);
        if (k < size) lz[k] = O::op(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = O::e();
    }
};
