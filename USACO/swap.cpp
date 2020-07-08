/*
ID: vikasu
TASK: lineup
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findNum(vector<int> l, int num) {
    for(int i=0; i<l.size(); i++){
        if(l[i] == num) return i;
    }
}


vector<int> play(vector<int> l, int i1, int i2) {
    vector<int> result;

    int idx_i1 = findNum(l, i1);
    int idx_i2 = findNum(l, i2);

    for(int ii = idx_i1; ii < idx_i2 + 1; ii++) {
        
    }

    int i=0;

    while(i < l.size()) {

    }    

    for(int i=0; i<l.size(); i++) {
        if(!(i > idx_i1 && i < idx_i2)) {
            result.push_back(l[i]);
        }
        else {

        }
    }
}


int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");

    int N, M, K;

    fin >> N >> M >> K;

    vector<int> list;
    for( int i = 1; i <= N; i++ )
        list.push_back(i);

    vector<vector<int> > pairs;

    for(int i=0; i<M; i++) {
        int a, b;
        fin >> a >> b;

        vector<int> temp;
        temp.push_back(a); temp.push_back(b); pairs.push_back(temp);

        list = play(list, a, b);

    }




    return 0;
}