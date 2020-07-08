/*
ID: vikasu           
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    while(N--) {
        int a, b;
        cin >> a >> b;
        int mod = a%b;
        if(mod == 0) cout << 0 << endl;
        else cout << b-mod << endl;
    }
}