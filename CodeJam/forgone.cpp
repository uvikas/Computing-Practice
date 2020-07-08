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

        string N;
        cin >> N;

        string A = "", B = "";

        for(int i=0; i<N.length(); i++) {
            if(N[i] != '4') {
                A += N[i];
                B += '0';                
            }
            else {
                A += '2';
                B += '2';
            }
        }

        string cleanB = "";
        bool b = false;
        for(int i=0; i<B.length(); i++) {
            if(B[i] == '0' && !b) {
            }
            else {
                cleanB += B[i];
                b = true;
            }
        }

        cout << "Case #" << t - T << ": " << A << " " << cleanB << endl;

    }

}