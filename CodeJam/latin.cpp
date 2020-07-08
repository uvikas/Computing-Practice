#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compute_trace(vector<vector <int> > vec) {
    int trace = 0;
    for(int i=0; i<vec.size(); i++) {
        trace += vec[i][i];
    }
    return trace;
}



int main() {
    int T, k=0;
    cin >> T;
    while(T--) {
        k++;
        int N;
        cin >> N;

        int trace = 0;
        int rowrep = 0, colrep = 0;

        vector<vector<int> > matrix;

        for(int i=0; i<N; i++) {
            vector<int> row;
            for(int j=0; j<N; j++) {
                int temp;
                cin >> temp;
                trace += temp;
                row.push_back(temp);
            }
            matrix.push_back(row);
        }



        for(int i=0; i<N; i++) {
            bool rep = false;
            int currPos = 0;
            int end=N;
            int start =1;
            while(currPos < N-1) {
                for(int q=start; q<N; q++) {
                    if(matrix[i][currPos] == matrix[i][q]) {
                        rep = true;
                    }
                }
                end--; start++; currPos++;
            }
            if (rep) rowrep++;
        }

        for(int i=0; i<N; i++) {
            bool rep = false;
            int currPos = 0;
            int end=N;
            int start =1;
            while(currPos < N-1) {
                for(int q=start; q<N; q++) {
                    //cout << matrix[currPos][i] << " " << matrix[q][i] << endl;
                    if(matrix[currPos][i] == matrix[q][i]) {
                        rep = true;
                        break;
                        //cout << matrix[currPos][i] << endl;
                    }
                    if(rep) break;
                }
                end--; start++; currPos++;
            }
            if (rep) colrep++;
        }

        
        cout << "Case #" << k << ": " <<  compute_trace(matrix) << " " << rowrep << " "  << colrep <<  endl;

    }

}