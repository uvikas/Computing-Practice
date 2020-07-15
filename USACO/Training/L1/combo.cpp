/*
ID: ummadis1
TASK: combo
LANG: C++                 
*/

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
int n;

bool close(int a, int b) {
    if(abs(a-b) <= 2) return true;
    if(abs(a-b) >= n-2) return true;
    return false;
}

bool dist(int a, int b, int c, vector<int> vec) {
    return close(a, vec[0]) && close(b, vec[1]) && close(c, vec[2]);
}


int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    fin >> n;
    vector<int> master, john;

    loop(i, 3) {
        int temp; fin >> temp;
        john.pb(temp);
    }
    loop(i, 3) {
        int temp; fin >> temp;
        master.pb(temp);
    }

    int ans=0;

    loop(i, n) {
        loop(j, n) {
            loop(k, n) {
                if(dist(i, j, k, john) || dist(i, j, k, master)) ans++;
            }
        }
    }

    fout << ans << endl;


    

    return 0;
}