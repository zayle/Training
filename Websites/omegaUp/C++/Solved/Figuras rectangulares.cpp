#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
typedef long double ld;
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 10000;//1000000000;
vector<int> primes;

bool isPrime(int a) {
    int sr, i;
    sr = sqrt(mx);
    for (i = 0; i < primes.size(); i++) {
        if (primes[i] <= sr) {
            if ((a%primes[i]) == 0) {
                if (a == primes[i]) {
                    break;
                } else {
                    return false;
                }
            }
        } else {
            break;
        }
    }
    return true;
}

void CreatePrimes() {
    int sr, i;
    sr = sqrt(mx);
    primes.push_back(2);
    for (i = 3; i <= sr; i += 2) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
}

void Solve() {
    int n;
    CreatePrimes();
    cin >> n;
    if (isPrime(n)) {
        cout << "ninguno" << '\n';
    } else {
        if (sqrt(n) == int(sqrt(n))) {
            if (isPrime(sqrt(n))) {
                cout << "cuadrado" << '\n';
            } else {
                cout << "ambos" << '\n';
            }
        } else {
            cout << "rectangulo" << '\n';
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
