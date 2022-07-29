template<class T> struct Enumeration{
  public:
    Enumeration(int sz = 0) { update(sz); }

    T fact(int k) {
        update(k);
        return _fact[k];
    }

    T finv(int k) {
        update(k);
        return _finv[k];
    }

    T inv(int k) {
        update(k);
        return _inv[k];
    }

    T nPk(int n, int k) {
        if(k < 0 || n < k) return 0;
        return fact(n) * finv(n - k);
    }

    T nCk(int n, int k) {
        if(k < 0 || n < k) return 0;
        return fact(n) * finv(k) * finv(n - k);
    }

    T nHk(int n, int k) {
        if(n < 0 || k < 0) return 0;
        if(n == 0) return 1;
        else return nCk(n + k - 1, k);
    }

  private:
    vector<T> _fact, _finv, _inv;

    void update(int sz) {
        if(_fact.size() < sz + 1){
            int pre_sz = max(1, (int)_fact.size());
            _fact.resize(sz + 1, T(1));
            _finv.resize(sz + 1, T(1));
            _inv.resize(sz + 1, T(1));
            for(int i = pre_sz; i <= (int)sz; i++) {
                _fact[i] = _fact[i - 1] * T(i);
            }
            _finv[sz] = T(1) / _fact[sz];
            for(int i = (int)sz - 1; i >= pre_sz; i--) {
                _finv[i] = _finv[i + 1] * T(i + 1);
            }
            for(int i = pre_sz; i <= (int)sz; i++) {
                _inv[i] = _finv[i] * _fact[i - 1];
            }
        }
    }

};
