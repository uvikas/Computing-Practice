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
        int act, num, denom;
        string orig, task;
        long long res = 0, total = 0;

        cin >> act >> orig;

        if(orig == "INDIAN") {
            denom = 200;
        }
        else {
            denom = 400;
        }

        loop(i, act) {
            cin >> task;
            if(task == "CONTEST_WON") {
                cin >> num;
                if(num <= 20) {
                    total += 300 + 20 - num;
                }
                else {
                    total += 300;
                }
                
            }
            else if(task == "BUG_FOUND") {
                cin >> num;
                total += num;
            }
            else if(task == "TOP_CONTRIBUTOR") {
                total += 300;
            }
            else{
                total += 50;
            }
        }

        res = total / denom;

        cout << res << endl;
    }

}
