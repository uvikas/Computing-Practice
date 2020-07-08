#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int T;
    cin >> T;
    int t = T;
    while(T--) {
        int N, L;
        vector<int> codes;

        cin >> N >> L;

        for(int i=0; i<L; i++) {
            int temp;
            cin >> temp;
            codes.push_back(temp);
        }

        

        cout << "Case #" << t - T << ": " << res << endl;

    }

}