#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    int t = T;
    while(T--) {
        int N;
        string P;
        cin >> N >> P;
        string res="";

        for(int i=0; i<P.length(); i++) {
            if(P[i] == 'E') res += 'S';
            else res+='E';
        }
        cout << "Case #" << t - T << ": " << res << endl;

    }

}