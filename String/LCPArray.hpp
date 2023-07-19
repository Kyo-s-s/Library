vector<int> LCPArray(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++) {
        rank[sa[i]] = i;
    }
    vector<int> lcp(n, 0);
    int h = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rank[i] - 1];
        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}
