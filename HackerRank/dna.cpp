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

//#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define loop(x,n) for(int x = 0; x < n; ++x)
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

int findOcc(string data, string kw)
{
    int c = 0;

    for(int subs=0; subs<data.length()-kw.length()+1; subs++) {
        //cout << kw << " vs. " << data.substr(subs, kw.length()) << endl;
        if(kw == data.substr(subs, kw.length())) {
            c++;
        }
    }

    return c;
 	
}


int main() {
    
    int n; cin >> n;

    vector<string> genes;
    vector<int> health;

    loop(i, n) {
        genes.push_back(get_str());
    }    
    loop(i, n) {
        health.push_back(get_int());
    } 
    
    int k;
    cin >> k;
    vector<int> vals;

    loop(i, k) {
        int start = get_int(), end = get_int(), dna_health=0;
        string dna = get_str();
        for(int j=start; j<end+1; j++) {
            dna_health += health[j] * findOcc(dna, genes[j]);
        }
        vals.push_back(dna_health);
    }

    cout << *min_element(vals.begin(), vals.end()) << " " << *max_element(vals.begin(), vals.end()) << endl;

}