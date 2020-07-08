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

int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");

    int N, K;
    fin >> N >> K;

    vector<int> b; 
    vector<int> sorted;
    for(int i=0; i<N; i++) {
        int temp;
        fin >> temp;
        b.push_back(temp);
        sorted.push_back(temp);
    }

    sort(sorted.begin(),sorted.end());

    if(K == 2) {
        fout << sorted[1] << endl;
        return 0;
    }


    vector<int> baskets;

    for(int i=0; i<K; i++) {
        
    }
    
    int pos = 0;

    while(true) {
        if(sorted[pos] / K > sorted[pos+1]) {
            for(int i=0; i<K; i++) {
                baskets.push_back(sorted[pos] / K);
            }
            break;
        }
        pos++;
    }



    return 0;
}