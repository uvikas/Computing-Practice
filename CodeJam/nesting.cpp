#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string group(string str, char key) {
    vector<int> inst;
    int orig_len = str.length();

    bool homo = true;

    for(int i=0; i<str.length(); i++) {
        if(str[i] == key) {
            inst.push_back(i);
        }
        if(i > 0 && str[i] != str[i-1]) {
            homo = false;
        }
    }

    if(homo) {
        if(str[0] == '1') {
            str.insert(0, "(");
            str.append(")");
            return str;
        }
        return str;
    }

    int offset = 0;

    if(inst[0] != 0) {
        str.insert(0, "(");
        offset++;
        str.insert(inst[0]+1, ")");
        offset++;
    }


    
    for(int i=0; i<inst.size(); i++) {

        if(inst[i] == inst[i+1] - 1) {
            continue;
        }
        if(inst[i] == orig_len-1) break;


        str.insert(inst[i]+1+offset, "(");
        offset++;
        if(i == inst.size()-1) {
            str.append(")");
            break;
        }
        else {
            str.insert(inst[i+1]+offset, ")" );
            offset++;
        }
        
    }

    return str;
}

int main() {
    int T, k=0;
    cin >> T;
    while(T--) {
        k++;

        string S;

        cin >> S;
        
        int m = 0;
        for(int i=0; i<S.length(); i++) {
            int a = S[i];
            m = max(m, a);
        }

        string res = group(S, '0');
        res = group(res, '1');


        cout << "Case #" << k << ": " << res << endl;

    }

}