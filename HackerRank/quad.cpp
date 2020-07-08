#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

#define sp ' '

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;



int main() {
    
    int N; cin >> N;
    vector<int> quads;
    while(N--) {
        int a, b;
        cin >> a >> b;
        if(a < 0) {
            if(b < 0) quads.push_back(3);
            else quads.push_back(2);
        }
        else {
            if(b < 0) quads.push_back(4);
            else quads.push_back(1);
        }
    }

    int queries;
    cin >> queries;

    while(queries--) {
        string req; int r1, r2;
        cin >> req >> r1 >> r2;

        if(req == "C") {
            cout << count(quads.begin()+r1-1, quads.begin()+r2, 1) << sp << count(quads.begin()+r1-1, quads.begin()+r2, 2) << sp << count(quads.begin()+r1-1, quads.begin()+r2, 3) << sp << count(quads.begin()+r1-1, quads.begin()+r2, 4) << endl;
        }
        else if(req == "X") {
            for(int i=r1-1; i<r2; i++) {
                quads[i] = 5 - quads[i];
            }
        }
        else {
            for(int i=r1-1; i<r2; i++) {
                if(quads[i] == 1) quads[i] = 2;
                else if(quads[i] == 2) quads[i] = 1;
                else if(quads[i] == 3) quads[i] = 4;
                else if(quads[i] == 4) quads[i] = 3;

            }

        }

    }

}