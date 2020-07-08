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

int n, minset, minset_ind, offset;
ll ans;

int main() {
    
    int t = get_int();

    while(t--) {
        cin >> n;
        vector<int> caps;
        minset = MOD;
        offset = 1;
        ans = 0;
        loop(i, n) {
            caps.pb(get_int());
            if(caps[i] < minset) {
                minset_ind = i;
                minset = caps[i];
            }
        }

        ans += minset * n;
        caps.erase(caps.begin()+minset_ind, caps.end());

        while(caps.size()>0) {
            auto temp = min_element(caps.begin(), caps.end());
            minset = *temp;
            minset_ind = temp - caps.begin();

            ans += (minset-offset) * caps.size();

            caps.erase(caps.begin() + minset_ind, caps.end());
            offset++;
        }

        cout << ans << endl;

    }

}