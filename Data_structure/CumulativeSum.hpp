template<class T> struct CumlativeSum {
    int n;
    vector<T> data; 
    bool builded = false;
    CumlativeSum(int n) : n(n), data(n + 1) {}
    CumlativeSum(const vector<T> &v) : n(v.size()), data(n + 1) {
        for (int i = 0; i < n; i++) {
            data[i + 1] = v[i];
        }
    }

    void build() {
        for (int i = 0; i < n; i++) {
            data[i + 1] += data[i];
        }
        builded = true;
    }

    T sum(int r) {
        if (!builded) build();
        assert(0 <= r && r <= n);
        return data[r];
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }

};
