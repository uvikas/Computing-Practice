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

int main() {
    
    int t = get_int();

    while(t--) {
        long long int n;
        cin >> n;
        long long int c = 0, d = 0;
        bool hit = false;
        long long total = 0;

        vector<int> twos;

        loop(i, n) {
            long long temp;
            cin >> temp;
            temp = abs(temp);

            if(temp % 2 == 0 && temp % 4 != 0 && !hit) {
                hit = true;
            }
            else if(temp % 2 == 1 && !hit) {
                c++;
            } 
            else if(temp % 2 == 1 && hit) {
                d++;
            }
            else if(temp % 4 == 0 && hit) {
                hit = false;
                total += ((c+1) * (d+1));
                c = 0;
                d = 0;
            }
            else if(temp % 4 == 0 && !hit) {
                c = 0;
                d = 0;
            }
            else if(temp % 2 == 0 && temp % 4 != 0 && hit) {
                total += ((c+1) * (d+1));
                hit = true;
                c = d;
                d = 0;
            }
        }

        if(hit) {
            total += ((c+1) * (d+1));
            c = 0; d = 0;
            hit = false;
        }

        long long grand = (((n+1) * n) / 2);

        cout << grand - total << endl;
    }

}
