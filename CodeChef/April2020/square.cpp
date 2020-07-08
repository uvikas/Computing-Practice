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

long long findSubsets(long long arr[], int ind, long long n) {
    int cnt = 0, start_ind=ind, end_ind=ind;
    bool start_end = false, end_end = false;
    while(!start_end || !end_end) {
        if(start_ind - 1 >= 0) {
            if(arr[start_ind-1] == 1) {
                start_ind--;
            }
            else start_end = true;
        }
        else start_end = true;
        if(end_ind + 1 <= n-1) {
            if(arr[end_ind+1] == 1) {
                end_ind++;
            }
            else end_end = true;
        }
        else end_end = true;
    }

    //cout << start_ind << " " << end_ind << endl;

    cnt = ((ind - start_ind + 1) * (end_ind - ind + 1)) % MOD;

    return cnt;
}

int main() {
    
    int t = get_int();

    while(t--) {
        long long n;
        cin >> n;
        long long b[n], c = 0;
        vector<int> twos;

        loop(i, n) {
            long long temp;
            cin >> temp;
            temp = abs(temp);
            temp = temp % MOD;
            if (temp % 2 == 0 && temp % 4 != 0) {
                b[i] = 2;
                twos.push_back(i);
            }
            else if(temp % 2 != 0) {
                b[i] = 1;
            }
            else if(temp % 4 == 0) {
                b[i] = 4;
            }
        }

        for(auto elem : twos) {
            c += findSubsets(b, elem, n) % MOD;
        }

        int total = ((n+1) * n / 2) % MOD;
        c = c % MOD;

        cout << total - c << endl;
    }

}
