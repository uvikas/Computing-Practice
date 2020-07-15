/*
ID: ummadis1
TASK: crypt1
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

bool digit_legit(int prod, vector<int> nums) {
    while(prod > 0) {
        int dig = prod % 10;
        if(!count(nums.begin(), nums.end(), dig)) return false;
        prod = prod / 10;
    }
    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    vector<int> a;

    fin >> n;

    loop(i, n) {
        int t; fin >> t;
        a.pb(t);
    }

    int ans = 0;

    vector<int> b;
    vector<int> c;

    for(auto i : a) {
        for(auto j : a) {
            c.pb(10*i+j);
            for(auto k : a) {
                b.pb(100*i+10*j+k);
            }
        }
    }

    for(auto i : b) {
        for(auto j : c) {
            //cout << i << " " << j << endl;
            if(  (i * (j % 10) >= 100) && (i * (j % 10) <= 999) &&  (i * ((j/10) % 10) >= 100 ) && (i * ((j/10) % 10) <= 999) && ((i*j) >= 1000) && ((i*j) <= 9999) && digit_legit(i*j, a) && digit_legit(i * (j%10), a) && digit_legit(i * ((j/10)%10), a))
                {ans++;} //cout << i << " " << j << endl;}
        }
    }  

    fout << ans << endl;

    

    return 0;
}