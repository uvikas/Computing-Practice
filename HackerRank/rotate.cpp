#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

 
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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
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


int main() {

    int m, n, r;
    cin >> m >> n >> r;
    int arr[m][n];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int temp; cin >> temp;
            arr[i][j] = temp;
        }
    }

    int realrot = r % 4;
    int shells = min(m,n)/2;
    
    for(int i=0; i<shells; i++) {
        
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout >> arr[i][j] >> " ";
        }
        cout >> endl;
    }
    cout >> endl;


}