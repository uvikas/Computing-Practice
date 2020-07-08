#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>


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

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

bool checkGCD(vector<int> vec, int num) {
    loop(ii, vec.size()) {
        if(gcd(vec[ii], num) != 1) {
            return false;
        }
    }
    return true;
}

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 

set<int> primeFactors(int n)  
{  
    set<int> res;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        res.insert(2);  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            res.insert(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        res.insert(n);  
    
    return res;
}  

bool checkFacts(set<int> vec, int jj) {
    for(auto elem : vec) {
        if(jj % elem == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int t = get_int();

    while(t--) {
        int n = get_int();

        if(n == 1) {
            cout << 1 << endl << 1 << " " << 1 << endl;
            continue;
        }
        else if(n == 2) {
            cout << 1 << endl << 2 << " " << 1 << " " << 2 << endl;
            continue;
        }

        vector<vector<int> > pgs;

        vector<set<int> > facts;

        for(int i=1; i <= n/2; i++) {
            vector<int> temp;
            set<int> temp1 = primeFactors(i*2);
            temp.push_back(i * 2);
            facts.push_back(temp1);
            pgs.push_back(temp);
        }

        pgs[0].insert(pgs[0].begin(), 1);

        for(int i=3; i<=n; i=i+2) {
            bool checked = false;
            if(isPrime(i)) {
                pgs[0].push_back(i);
                continue;
            }
            else if(isPerfectSquare(i) && isPrime(sqrt(i))) {
                pgs[1].push_back(i);
                continue;
            }
            for(int j=2; j<pgs.size(); j++) {
                if(checkFacts(facts[j], i)) {
                    pgs[j].push_back(i);
                    set<int> primefacts = primeFactors(i);
                    facts[j].insert(primefacts.begin(), primefacts.end());
                    checked = true;
                    break;
                }
            }

            if(!checked) {
                vector<int> temp (1, i);
                pgs.push_back(temp);
                set<int> temp1; temp1.insert(i);
                facts.push_back(temp1);
            }
        }
        cout << pgs.size() << endl;
        loop(i, pgs.size()) {
            cout << pgs[i].size() << " ";
            loop(j, pgs[i].size()) {
                cout << pgs[i][j] << " ";
            }
            cout << endl;
        }
        /*
        cout << "FACTORS" << endl;
        loop(i, facts.size()) {
            for(auto j : facts[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        */

    }

}