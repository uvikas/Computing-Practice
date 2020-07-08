#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


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

vector<int> freq(string inp) {
    vector<int> freqvec(26, 0);
    loop(i, inp.length()) {
        if(inp[i] >= 'a' && inp[i] <= 'z') {
            freqvec[inp[i]-'a']++;
        }
    }
    return freqvec;
}

bool compareVec(vector<int> x, vector<int> y) {
    bool same = true;
    loop(i, 26) {
        if(x[i] != y[i]) {
            same = false; 
            break;
        }
    }
    return same;
}

int main() {
    
    int t; cin >> t;
    while(t--) {
        string s = get_str();

        string a, b;
        a = s.substr(0, floor(s.length()/2));
        b = s.substr(ceil(s.length()/2.0));

        if(compareVec(freq(a), freq(b))) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}