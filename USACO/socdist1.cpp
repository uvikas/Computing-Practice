#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("socdist1.out");
    ifstream fin ("socdist1.in");

    int N;
    fin >> N;

    string s;
    vector<int> gaps;
    fin >> s;

    cout << s << endl;

    int counter = 0;

    for(int i=0; i<N; i++) {
        if(i > 0) {
            if(s.substr(i-1,2).compare("11") == 0) {
                fout << 1 << endl;
                return 0;
            }
        }
        if(s.substr(i, 1).compare("0") == 0) {
            counter++;
        }
        else {
            gaps.push_back(counter);
            counter = 0;
        }
    }

    if(counter) gaps.push_back(counter);
    if(gaps[0] == 0) gaps.erase(gaps.begin());

    int begin = gaps[0];
    int end = gaps[gaps.size()-1];


    sort(gaps.begin(), gaps.end());

    


    if(gaps[gaps.size()-1] > gaps[gaps.size()-2] * 3 + 2) {
        int max_gap = (gaps[gaps.size()-1] - 2) / 3;
        gaps.pop_back();
        gaps.push_back(max_gap);
        sort(gaps.begin(), gaps.end());
        fout << gaps[0] + 1 << endl;
        cout << gaps[0] + 1 << endl;
    }
    else {
        if(gaps[gaps.size()-1] % 2 == 0) {
            int highest = gaps[gaps.size()-1];
            gaps.pop_back(); 
            gaps.push_back(highest / 2);
            gaps.push_back(highest / 2 - 1);
            
        }
        else {
            int highest = gaps[gaps.size()-1];
            gaps.pop_back();
            gaps.push_back(highest / 2);
            gaps.push_back(highest / 2);
        }

        sort(gaps.begin(), gaps.end());

        if(gaps[gaps.size()-1] % 2 == 0) {
            int highest = gaps[gaps.size()-1];
            gaps.pop_back(); 
            gaps.push_back(highest / 2);
            gaps.push_back(highest / 2 - 1);
            
        }
        else {
            int highest = gaps[gaps.size()-1];
            gaps.pop_back();
            gaps.push_back(highest / 2);
            gaps.push_back(highest / 2);
        }

    /*
        for(int i=0; i<gaps.size(); i++) {
            cout << gaps[i] << " ";
        }
        */

        sort(gaps.begin(), gaps.end());

        fout << gaps[0]+1;
        cout << gaps[0]+1 << endl;
    }

    


    



}
/*
for(int i=0; i<N; i++) {
        if(s.substr(i, 1).compare("1") == 0) {
            occupied.push_back(i);
        }
    }

    for(int i=1; i<occupied.size(); i++) {
        diff.push_back(occupied.at(i) - occupied.at(i-1));
        cout << diff[i-1] << endl;
    }

    sort(diff.begin(), diff.end());

    diff[diff.size() - 1] = diff[diff.size() - 1] / 2;
    diff[diff.size() - 2] = diff[diff.size() - 2] / 2;

    sort(diff.begin(), diff.end());

    fout << diff[0] << endl;
    */