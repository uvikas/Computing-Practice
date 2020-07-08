#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
 

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

        int n;
        cin >> n;

        if(n == 1) {
            cout << 1 << endl << 1 << " " << 1 << endl;
            continue;
        }
        else if(n == 2) {
            cout << 1 << endl << 2 << " " << 1 << " " << 2 << endl;
            continue;
        }
        else if(n == 3) {
            cout << 1 << endl << 3 << " " << 1 << " " << 2 << " " << 3 << endl;
            continue;
        }
        else {
            
            printf("%d\n", (int)floor(n/2.0));
            printf("3 1 2 3\n");
            
            for(int i=4; i<=n; i++) {
                if(i%2 == 0) {
                    if(i == n) {
                        printf("1 %d\n", n);
                        break;
                    }
                    printf("2 %d", i);
                }
                else {
                    printf(" %d\n", i);
                }
            }
            
            
            /*
            cout << floor(n/2.0) << endl;
            cout << 3 << " " << 1 << " " << 2 << " " << 3 << endl;

            for(int i=4; i<=n; i++) {
                if(i%2 == 0) {
                    if(i == n) {
                        cout << 1 << " " << n << endl;
                        break;
                    }
                    cout << 2 << " " << i;
                }
                else {
                    cout << " " << i << endl;
                }
            }
            
            */
            
        }
            
    }
        

}