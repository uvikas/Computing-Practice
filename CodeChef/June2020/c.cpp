#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;
using namespace std::chrono_literals;


 
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


int n, curr = 0;
bool doable;
int queue[1000];

bool rec(int ind, vector<int> cash) {
/*
    cout << ind << "   ";
    
    for(int elem : cash) {
        cout << elem << " ";
    }
    cout << endl;
*/

    if(ind >= n) {
        return true;
    }

    if(queue[ind] == 5) {
        cash[0]++;
        if(rec(++ind, cash)) return true;
    }
    else if(queue[ind] == 10) {
        if(cash[0] > 0) {
            cash[0]--;
            cash[1]++;
            if (rec(++ind, cash)) return true;
        }
        else return false;
    }
    else {
        if(cash[1] > 0) {
            cash[1]--;
            if(rec(++ind, cash)) return true;
            cash[1]++;
        }
        if(cash[0]>1) {
            cash[0] -= 2;
            if(rec(++ind, cash)) return true;
            cash[0] += 2;
        }
        else {
            return false;
        }
    }
    return false;
}


int main() {
    
    int t = get_int();

    while(t--) {
        cin >> n;

        bool skip = false;

        vector<int> change(2, 0);
        vector<int> freq(3, 0);

        loop(i, n) {
            cin >> queue[i];
            if(i==0 && queue[i] != 5) {
                skip = true;
            }

            if(queue[i] == 5) {
                freq[0]++;
            }
            else if(queue[i] == 10) {
                freq[1]++;
            }
            else {
                freq[2]++;
            }
        }



        if(!skip && (freq[0] >= freq[1])) doable = rec(0, change);
        else doable = false;

        if(doable) cout << "YES" << endl;
        else cout << "NO" << endl;

        fill_n(queue, n, 0);

    }

}


