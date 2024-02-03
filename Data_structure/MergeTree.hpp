template<typename T> 
concept Monoid = requires {
    typename T::T;
    { T::op(std::declval<typename T::T>(), std::declval<typename T::T>()) } -> std::same_as<typename T::T>;
    { T::e() } -> std::same_as<typename T::T>;
};

template<class T, Monoid M>
struct MergeTree {
    using S = typename M::T;
  public:

    MergeTree(int n, std::function<T(int, int)> f) : n(n) {
        while((1 << log) < n) log++;
        size = 1 << log;
        d = vector<T> (2 * size, T());
        auto init = [&](auto &&init, int l, int r, int k) -> void {
            d[k] = f(l, min(r, n));
            if(d.size() <= 2 * k) return;
            int m = (l + r) / 2;
            init(init, l, m, 2 * k);
            init(init, m, r, 2 * k + 1);
        };
        init(init, 0, size, 1);
    }

    S prod(int l, int r, std::function<S(const T&)> g) {
        assert(0 <= l && l <= r && r <= n);
        S sml = M::e(), smr = M::e();
        l += size; r += size;
        while (l < r) {
            if (l & 1) sml = M::op(sml, g(d[l++]));
            if (r & 1) smr = M::op(g(d[--r]), smr);
            l >>= 1; r >>= 1;
        }
        return M::op(sml, smr);
    }

  private:
    int n, size, log = 0;
    vector<T> d;
};
