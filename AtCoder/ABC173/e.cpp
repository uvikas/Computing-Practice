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

int n, k;
ll a[200000];

bool tmp (ll a, ll b) {
    return abs(a) > abs(b);
}

void solve() {

    cin >> n >> k;

    loop(i, n) {
        cin >> a[i];
    }

    if(n == k) {
        ll prod = 1;
        loop(i, n) {
            prod = (prod * a[i]) % MOD;
        }
        cout << prod<< endl;
    }

    else {
        sort(a, a+n, tmp);
        ll init = 1;
        loop(i, k) {
            init *= a[i];
            init = init % MOD;
        }
        if(init >= 0) cout << init << endl;
        else {
            ll ans1, ans2;
            bool bans1 = false, bans2 = false;

            ll swap1 = a[k-1];

            bool bswap2 = false;
            ll swap2;

            for(int i=k-1; i>=0; i--) {
                if(swap1 >= 0 && a[i] <= 0) {
                    swap2 = a[i];
                    bswap2 = true;
                    break;
                }
                else if(swap1 <= 0 && a[i] >= 0) {
                    swap2 = a[i];
                    bswap2 = true;
                    break;
                }
            }

            for(int i=k; i<n; i++) {
                if(a[i] >= 0) {
                    if(!bans1 && swap1 <= 0) {
                        // find ans1
                        bans1 = true;
                    }
                    else if(!bans2 && bswap2 && swap2 <= 0) {
                        // find ans2
                        bans2 = true;
                    }
                }
                else if(a[i] <= 0) {
                    if(!bans1 && swap1 >= 0) {
                        //find ans1
                        bans1 = true;
                    }
                    else if(!bans2 && bswap2 && swap2 >= 0) {
                        //find ans2
                        bans2 = true;
                    }
                }

                if(bans1 && (bans2 || !bswap2)) break;
            }

            if(ans1 > init) {
                cout << ans1 << endl;
            }
            
        }

    }




}

int main() {
    
    solve();

}