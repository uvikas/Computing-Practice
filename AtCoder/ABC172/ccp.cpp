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
ll A[200000], B[200000];
vector<ll> a, b;
ll k;

int main() {
    
    cin >> n >> m >> k;

    a.pb(0); b.pb(0);


    loop(i, n) {
        cin >> A[i];
        a.pb(a[i] + A[i]);
    }
    loop(i, m) {
        cin >> B[i];
        b.pb(b[i] + B[i]);
    }

    int num = 0, j = m;

    loop(i, n+1) {
        if(a[i] > k) break;
        while(b[j] > k - a[i]) {
            j--;
        }
        num = max(num, i+j);
    }

    cout << num << endl;
}