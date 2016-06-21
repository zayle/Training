#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 1000001;
vector<int> primes;

bool IsPrime(int a) {
    int sr, i;
    sr = sqrt(a);
    for (i = 0; primes[i] <= sr; i++) {
        if ((a%primes[i]) == 0) {
            return false;
        }
    }
    return true;
}

void CreatePrimes() {
    int i;
    primes.push_back(2);
    for (i = 3; i < mx; i += 2) {
        if (IsPrime(i)) {
            primes.push_back(i);
        }
    }
}

void Solve() {
    ll n, answer, i;
    CreatePrimes();
    cin >> n;
    answer = 1;
    for (i = 0; i < primes.size(); i++) {
        if ((n%primes[i]) == 0) {
            answer *= primes[i];
            while ((n%primes[i]) == 0) {
                n /= primes[i];
            }
        }
    }
    answer *= n;
    cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
