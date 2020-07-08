#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <map>
#include <set>
#include <array>

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

int a[100000];

int main() {
    
    int t = get_int();

    while(t--) {
        int n, k;
        cin >> n >> k;

        map<int, int> last;

        loop(i, n) {
            cin >> a[i];
            last[a[i]] = -1;
        }

        if(last.size() < k) {
            cout << n << endl;
            continue;
        }

        set<array<int, 2> > s;

        for(auto p : last) {
            s.insert({p.second, p.first});
        }

        int ans = 0;

        loop(i, n) {
            s.erase({last[a[i]], a[i]});

            last[a[i]] = i;

            s.insert({last[a[i]], a[i]});

            ans = std::max(i-(*s.begin())[0], ans);
        }

        cout << ans << endl;
        
    }

}