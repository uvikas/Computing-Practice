#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <map>

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

void solve() {
    int n, m;
    ll a[200000], b[200000];
    cin >> n >> m;

    map<int, pair<int, int> > c;

    bool flag = false;

    loop(i, n) {
        cin >> a[i]; 
        //cout << "a" << endl;
    }
    loop(i, m) {
        cin >> b[i];
        loop(j, n) {
            if(c.size() == (n + m - 1)) {flag = true; break;} 
            pair<int, int> temp (j, i);
            c.insert(pair<int, pair<int, int> >(b[i] + a[j], temp));
        }
        if(flag) break;
    }

    for(auto it = c.begin(); it != c.end(); ++it) {
        cout << it->second.first << " " << it->second.second << endl;
    }


}

int main() {
    
    solve();

}