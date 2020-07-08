#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

//#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define loop(x,n) for(int x = 0; x < n; ++x)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;

string get_str() {
    string temp;
    cin >> temp;
    return temp;
}
int get_int() {
    int temp;
    cin >> temp;
    return temp;
}

/*
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
    first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}
*/


vector<int> getBad(vector<int> inp, vector<int> sorted) {
    vector<int> res;
    for(int i=0; i<inp.size(); i++) {
        if(inp[i] != sorted[i]) res.pb(i);
    }
    return res;
}

int getInd(vector<int> searching, int key) {
    loop(j, searching.size()) {
        if(searching[j] == key) return j;
    }
    return -1;
}

int main() {
    
    int t = get_int();

    int n, k, tot;


    while(t--) {

        cin >> n >> k;
        tot = 0;
        int c = 0;

        vector<int> orig, rr;

        vector<vector<int> > changes(200000);
        vector<vector<int> > steps;

        loop(i, n) {
            orig.pb(get_int());
        }
        
        for(int i=0; i<orig.size(); i++) {
            if(i+1 != orig[i]) {
                vector<int> temp = {orig[i], i, orig[i]-1};
                changes[orig[i]] = temp;
                rr.pb(orig[i]);
            }
        }

        if(rr.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        if(rr.size() % 3 != 0 && rr.size() < 3) {
            cout << -1 << endl;
            continue;
        }

        //cout << rr.size() << endl;

        int i0, i1, i2, v0, v1, v2;
        while(true) {
            c++;
            i0 = changes[rr[0]][1];
            i1 = changes[rr[0]][2];
            if(orig[i1]-1 == i0) {
                if(changes[rr[1]][1] == i1) {
                    i2 = changes[rr[2]][1];
                }
                else {
                    i2 = changes[rr[1]][1];
                }
            }
            else {
                i2 = orig[i1] - 1;
            }

            //cout << "i0: " << i0 << " i1: " << i1 << " i2: " << i2 << endl;

            

            if(i2 < i1) {

                swap(i1, i2);

                v0 = orig[i0];
                v1 = orig[i1];
                v2 = orig[i2];

                orig[i0] = v2; 
                orig[i1] = v0;
                orig[i2] = v1;

                changes[orig[i0]][1] = i0;
                changes[orig[i1]][1] = i1;
                changes[orig[i2]][1] = i2;

                v0 = orig[i0];
                v1 = orig[i1];
                v2 = orig[i2];

                orig[i0] = v2; 
                orig[i1] = v0;
                orig[i2] = v1;

                changes[orig[i0]][1] = i0;
                changes[orig[i1]][1] = i1;
                changes[orig[i2]][1] = i2;

                vector<int> lst = {i0, i1, i2};
                sort(lst.begin(), lst.end());
                steps.pb(lst);
                steps.pb(lst);
                //cout << lst[0] << " "  << lst[1] << " " << lst[2] << endl; 
                //cout << lst[0] << " "  << lst[1] << " " << lst[2] << endl;   
            }
            else {

                int arr[3] = {i0, i1, i2};
                sort(arr, arr+3);
                i0 = arr[0];
                i1 = arr[1];
                i2 = arr[2];

                v0 = orig[i0];
                v1 = orig[i1];
                v2 = orig[i2];

                orig[i0] = v2; 
                orig[i1] = v0;
                orig[i2] = v1;

                changes[orig[i0]][1] = i0;
                changes[orig[i1]][1] = i1;
                changes[orig[i2]][1] = i2;

                vector<int> lst = {i0, i1, i2};
                sort(lst.begin(), lst.end());
                steps.pb(lst);
                //cout << lst[0] << " "  << lst[1] << " " << lst[2] << endl; 
            }
            

            if(orig[i0] - 1 == i0) {
                rr.erase(remove(rr.begin(), rr.end(), orig[i0]), rr.end());
            }
            if(orig[i1] - 1 == i1) {
                rr.erase(remove(rr.begin(), rr.end(), orig[i1]), rr.end());
            }
            if(orig[i2] - 1 == i2) {
                rr.erase(remove(rr.begin(), rr.end(), orig[i2]), rr.end());
            }
/*
            cout << rr.size() << endl;

            for(auto elem : rr) {
                cout << elem << " ";
            }
            cout << endl;
*/
            if(rr.size()==0) {
                break;
            }
            else if(rr.size() < 3 && rr.size() % 3 != 0) {
                tot = -1;
                break;
            }

        }
        
        //cout << endl << endl;


        if(tot == -1 || steps.size() > k) {
            cout << -1 << endl;
            continue;
        }
        else {
            cout << steps.size() << endl;
            for(int i=0; i<steps.size(); i++) {
                cout << steps[i][0]+1 << " " << steps[i][1]+1 << " " << steps[i][2]+1 << endl;
            }
        }

    }

}

/*

cin >> n >> k;
        tot = 0;

        vector<int> orig, sorted;

        vector<vector<int> > changes;

        loop(i, n) {
            orig.pb(get_int());
        }
        
        

        for(int i=0; i<orig.size(); i++) {
            if(i+1 != orig[i]) {
                vector<int> temp = {orig[i], i, orig[i]-1};
                changes.pb(temp);
            }
        }

        if(changes.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        if(changes.size() % 3 != 0 && changes.size() < 3) {
            cout << -1 << endl;
            continue;
        }

        int i0, i1, i2;
        while(true) {
            i0 = changes[0][1];
            i1 = changes[0][2];
            if(orig[i0] == orig[i1]) {
                if(changes[1][1] == i1) {
                    i2 = changes[2][1];
                }
                else {
                    i2 = changes[1][1];
                }
            }
            else {
                i2 = orig[i1] - 1;
            }
        }

*/