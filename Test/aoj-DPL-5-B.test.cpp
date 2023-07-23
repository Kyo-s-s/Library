#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"

#include "../Math/Modint.hpp"

#include "../Math/Enumeration.hpp"


int main() {

    int N, K;
    cin >> N >> K;

    Enumeration<Modint1000000007> enu;

    cout << enu.nPk(K, N) << endl;
}
