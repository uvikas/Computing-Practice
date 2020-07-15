/*
ID: ummadis1
TASK: milk
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

#define USACO
#define FILEIN "milk.in"
#define FILEOUT "milk.out"

struct Farmer{
	int price;
	int amount;
};

bool compFarmer(Farmer a1, Farmer a2){
	return a1.price < a2.price;
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	vector<Farmer> f;

	int tAmount, tFarmer;
	cin >> tAmount >> tFarmer;

	for (int i = 0; i < tFarmer; i++){
		int p, a;
		cin >> p >> a;

		Farmer w;
		w.price = p;
		w.amount = a;

		f.push_back(w);
	}

	sort(f.begin(), f.end(), compFarmer);

	int totalPrice = 0;

	while (tAmount > 0){
		Farmer pref = f[0];

		if (pref.amount <= tAmount){
			totalPrice += pref.amount * pref.price;
			tAmount -= pref.amount;
		}
		else {
			totalPrice += tAmount * pref.price;
			tAmount = 0;
		}


		f.erase(f.begin());
	}

	cout << totalPrice << endl;

}
/*
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    map<int, int> l;

    int n, m;
    int cost = 0;
    fin >> n >> m;


    loop(i, m) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        l.insert(pair<int, int>(temp1, temp2));
    }

    for(auto it=l.begin(); it!=l.end(); ++it) {
        if(it->second > n) {
            cost += n * it->first;
            n = 0;
        }
        else {
            cost += it->second * it->first;
            n -= it->second;
        }
        if(n <= 0) break;
    }

    fout << cost << endl;
    
    return 0;
}

*/