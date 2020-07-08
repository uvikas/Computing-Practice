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


bool comp(int a, int b) {
    return a < b;
}


int main() {
    
    int t = get_int();

    while(t--) {
        
        int n, a[10], b[10];
        cin >> n;
        loop(i, n) {
            cin >> a[i];
        }
        loop(i, n) {
            
            int c=1;
            int j=i;

            while(true) {
                if(j-1 < 0) break;
                if((a[j] - a[j-1]) <= 2) c++;
                else break;
                j--;
            }

            j=i;

            while(true) {
                if(j+1 >= n) break;
                if((a[j+1] - a[j]) <= 2) c++;
                else break;
                j++;
            }

            b[i] = c;
            

        }

        cout << *min_element(b, b+n) << " " << *max_element(b, b+n) << endl;
        //for(int i=0; i<n; i++) cout << b[i] << " ";


    }

}

/*

loop(i, n) {
            if(i==0) {
                int c=1;
                int j = 0;
                while(true) {
                    if(j+1 >= n) break;
                    if((a[j+1] - a[0]) <= 2) c++;
                    else break;
                    j++;
                }
                b[0] = c;
            }
            else if(i == n-1) {
                int c=1;
                int j = n-1;
                while(true) {
                    if(j-1 < 0) break;
                    if((a[n-1] - a[j-1]) <= 2) c++;
                    else break;
                    j++;
                }
                b[n-1] = c;
            }
            else {
                int c=1;

                int j=i;
                int org=i;

                while(true) {
                    if(j-1 < 0) break;
                    if((a[org] - a[j-1]) <= 2) c++;
                    else break;
                    j++;
                }

                j=i;

                while(true) {
                    if(j+1 >= n) break;
                    if((a[j+1] - a[org]) <= 2) c++;
                    else break;
                    j++;
                }

                b[i] = c;
            }

        }

        */