vector<int> Zalgorithm(const string &S) {
    vector<int> Z(S.size());
    Z[0] = (int)S.size();
    int i = 1, j = 0;
    while(i < S.size()) {
        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;
        Z[i] = j;

        if(j == 0) {
            i++;
            continue;
        }

        int k = 1;
        while(k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
}

template<class T>
vector<int> Zalgorithm(const vector<T> &S) {
    vector<int> Z(S.size());
    Z[0] = (int)S.size();
    int i = 1, j = 0;
    while(i < S.size()) {
        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;
        Z[i] = j;

        if(j == 0) {
            i++;
            continue;
        }

        int k = 1;
        while(k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
}
