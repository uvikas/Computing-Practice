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

const int N = 7;
char ar[N][N];
 
void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  for(int i = 0; i < r; i++) cin >> ar[i];
  int ans = 0;
  for(int i = 0; i < (1<<r); i++) {
      for(int j = 0; j < (1<<c); j++) {
          int black = 0;
          for(int m = 0; m < r; m++) {
              for(int n = 0; n < c; n++) {
                  if(((i>>m) & 1) == 0 && ((j>>n) & 1) == 0 && ar[m][n] == '#') {
                      black++;
                  }
              }
          }
          if(black == k) ans++;
      }
  }
  cout << ans;

  
}

int main() {
    
    solve();

}