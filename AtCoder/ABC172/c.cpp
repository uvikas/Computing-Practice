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
ll get_int() {
    ll temp;
    cin >> temp;
    return temp;
}



int n, m; 
vector<ll> a, b;
ll k;

int main() {
    
    cin >> n >> m >> k;

    loop(i, n) a.pb(get_int());
    loop(i, m) b.pb(get_int());

    int t = 0, num=0;

    while(t < k) {

        if(a.size() == 0 && b.size() == 0) break;
        
        if(a.size() != 0 && a[0] < b[0] && t + a[0] <= k) {
            t += a[0];
            cout << a[0] << endl;
            a.erase(a.begin());
            num++;
        }
        else if(b.size() != 0 && b[0] < a[0] && t + b[0] <= k) {
            t += b[0];
            cout << b[0] << endl;
            b.erase(b.begin());
            num++;
        }
        else {
            break;
        }
        
    }  

    cout << num << endl;





}