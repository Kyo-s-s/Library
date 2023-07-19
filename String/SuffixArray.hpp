vector<int> SuffixArray(const string& s) {
    int n = s.size(), k;
    vector<int> sa(n + 1);
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rank[i] = i < n ? (int)s[i] : -1;
    }

    auto compare = [&](int a, int b) {
        if (rank[a] != rank[b]) return rank[a] < rank[b];
        auto rank_ak = a + k <= n ? rank[a + k] : -1;
        auto rank_bk = b + k <= n ? rank[b + k] : -1;
        return rank_ak < rank_bk;
    };

    for (k = 1; k <= n; k *= 2) {
        sort(sa.begin(), sa.end(), compare);
        vector<int> tmp(n + 1);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; i++) {
            rank[i] = tmp[i];
        }
    }
    return sa;
}
