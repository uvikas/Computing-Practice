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
        long long k; int x;
        cin >> k >> x;

        if(k == 0 && x == 0) {
            cout << 1 << endl;
            continue;
        }
        else if (k == 0 && x == 1) {
            cout << 0 << endl;
            continue;
        }

        int sumfacts = 0;

        int d = 0;
        while(k % 2 == 0) {
            k = k/2;
            d++;
            //cout << "2 ";
        }
        if(d) {
            sumfacts += d;
        }
        for(int i=3; i<= sqrt(k) && k>1; i=i+2) {
            d = 0;
            while(k % i == 0) {
                k = k/i;
                d++;
                //cout << i << " ";
            }
            if(d) {
                sumfacts += d;
            }
        }
        if(k > 2) {
            sumfacts += 1;
            //cout << k << endl;
        }

        //cout << endl;
        //cout << "Total Factors: " << sumfacts << endl;
        if(sumfacts / x >= 1) {
            cout << 1 << endl;
        }
        else cout << 0 << endl;




    }

}