#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../Math/Matrix.hpp"
#include "../Math/Modint.hpp"

int main() {

    int N, M, K; cin >> N >> M >> K;
    Matrix<Modint998244353> A(N, M), B(M, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long a; cin >> a;
            A[i][j] = a;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            long long b; cin >> b;
            B[i][j] = b;
        }
    }

    Matrix<Modint998244353> C = A * B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << C[i][j] << " \n"[j == K - 1];
        }
    }
}
