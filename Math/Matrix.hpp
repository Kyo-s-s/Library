template<class T> struct Matrix {
    int n, m;
    vector<vector<T>> M;

    Matrix() : n(0), m(0) { init(); }
    Matrix(int _n, int _m) : n(_n), m(_m) { init(); }
    Matrix(int _n) : n(_n), m(_n) { init(); }

    void init() {
        M.resize(n, vector<T>(m));
    }

    inline const vector<T> &operator[](int k) const { return (M.at(k)); }
    inline vector<T> &operator[](int k) { return (M.at(k)); }

    static Matrix I(int n) {
        Matrix mat(n);
        for(int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }

    Matrix operator+=(const Matrix &B) {
        assert(n == B.n && m == B.m);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
        return (*this);
    }

    Matrix operator-=(const Matrix &B) {
        assert(n == B.n && m == B.m);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
        return (*this);
    }

    Matrix operator*=(const Matrix &B) {
        assert(m == B.n);
        m = B.m;
        vector<vector<T>> C(n, vector<T>(B.m, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < B.m; j++) for(int k = 0; k < B.n; k++) C[i][j] += (*this)[i][k] * B[k][j];
        M.swap(C);
        return (*this);
    }

    Matrix pow(long long k) {
        assert(n == m);
        Matrix B = Matrix::I(n);
        while(k > 0) {
            if(k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        return B;
    }

    Matrix operator+(const Matrix &B) const { return (Matrix(*this) +=B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -=B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *=B); }

    friend ostream &operator<<(ostream &os, Matrix &p) {
        for(int i = 0; i < p.n; i++) {
            os << "[";
            for(int j = 0; j < p.m; j++){
                os << p[i][j] << (j == p.m - 1 ? "]\n" : ", ");
            }
        }
        return (os);
    }
};
