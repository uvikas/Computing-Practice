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




int main() {
    
    ll n; 
    cin >> n;

    char a[50];
    a[1] = 'a';
    int b[50];

    loop(i, 25) {
        a[i+2] = a[i+1] + 1;
        b[i] = 0;
    }

    for(int i=0; n>0; i++) {
        b[i] = n % 26;
        if(b[i] == 0) b[i] = 26;
        n = (n-1) / 26;
    }

    for(int i=20; i>= 0; --i) {
        if(b[i] != 0) cout << a[b[i]];
    } 

    cout << endl;

}