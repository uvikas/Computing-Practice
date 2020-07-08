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

    int n, k, temp, tot;
    vector<int> orig, sorted, bads;
    vector<vector<int> > ops;


    while(t--) {

        cin >> n >> k;

        loop(i,n) {
            cin >> temp;
            orig.pb(temp);
        }
        
        sorted = orig;
        sort(sorted.begin(), sorted.end());

        tot = 0;

        while(true) {

            if(tot > k) {
                tot = -1;
                break;
            }

            bads = getBad(orig, sorted);
            if(bads.size() == 0) break;
            else if(bads.size() == 1 || bads.size() == 2) {
                tot = -1;
                break;
            }

            int i0 = bads[0];
            int i2 = getInd(orig, sorted[i0]);
            int i1 = getInd(sorted, orig[i0]);
            
            vector<int> op;
            op.pb(i0); op.pb(i1); op.pb(i2);
            ops.pb(op);
            tot++;

            int v0 = orig[i0], v1 = orig[i1], v2 = orig[i2];
            orig[i0] = v2; orig[i1] = v0; orig[i2] = v1;

        }

        cout << tot << endl;

        if(tot != -1) {
            for(int i=0; i<tot; i++) {
                cout << ops[i][0]+1 << " " << ops[i][1]+1 << " " << ops[i][2]+1 << endl;
            }
        }
        




        
    }

}