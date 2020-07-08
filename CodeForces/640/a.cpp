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
    
    int t = get_int();

    while(t--) {
        string c = get_str();
        vector<int> val;
        for(int i=0; i<c.length(); i++) {
            if(c[i] != '0') {
                float temp = c[i] - '0';
                temp *= pow(10, (c.length() - i - 1));
                temp = ceil(temp);
                val.pb(temp);
            }
        }
        cout << val.size() << endl;
        for(int v : val) {
            cout << v << " ";
        }
        cout << endl;

    }

}

/*
int c = get_int();
        vector<int> l;
        int layer = 1;
        while(c>0) {
            if(c % 10 != 0) {
                l.pb((c % 10) * layer);
            }
            c = c % 10;
            layer *= 10;
            
        }
        cout << l.size() << endl;
        loop(i, l.size()) {
            cout << l[i] << " ";
        }
        cout << endl;

        */