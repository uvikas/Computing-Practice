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
    ofstream fout ("convention.out");
    ifstream fin ("convention.in");

    int N, M, C;
    vector<int> cows;
    vector<int> wait_times;

    fin >> N >> M >> C;

    for(int i=0; i<N; i++) {
        int tempt;
        fin >> tempt;
        cows.push_back(tempt);
    }

    sort(cows.begin(), cows.end());

    int idx = 0;

    for(int i=0; i<M; i++) {
        int startTime = cows[idx];
        for(int j=0; j<C; j++) {
            
            wait_times.push_back(cows[idx] - startTime);
            idx++;
            if(idx == N) break;
        }
        if(idx == N) break;
    }

    fout << *max_element(wait_times.begin(), wait_times.end()) << endl;


}