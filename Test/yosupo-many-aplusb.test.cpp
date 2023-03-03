#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "../Template/Template.hpp"

int main() {

    INT(T);
    vll Ans;

    while (T--) {
        LL(A, B);
        Ans.pb(A + B);
    }

    fore (a, Ans) {
        OUT(a);
    }

}
