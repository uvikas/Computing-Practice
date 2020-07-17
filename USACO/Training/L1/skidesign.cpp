/*
ID: ummadis1
TASK: skidesign
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <set>

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

int n;
multiset<int> height;


int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    fin >> n;
    loop(i, n) {
        int t;
        fin >> t;
        height.insert(t);
    }

    if(*next(height.begin(), height.size()-1) - *height.begin() <= 17) {
        cout << *height.begin() << " " << *next(height.begin(), height.size()-1) << endl;
        fout << 0 << endl;
    }
    else {
        int mincost = 1000000000;
        for(int start=0; start <= 83; start++) {
            int tcost = 0;
            for(auto it=height.begin(); it!=height.end(); ++it) {
                if(*it < start) {
                    tcost += (start - *it) * (start - *it);
                }
                else if(*it > start+17) {
                    tcost += (start+17-*it) * (start+17-*it);
                }
            }
            mincost = min(tcost, mincost);
            //cout << tcost << endl;

        } 
        fout << mincost << endl;
    }


    return 0;
}