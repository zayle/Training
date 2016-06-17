#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

void Move(long long side, long long r, long long c, long long beans) {
    if (beans <= side) {
        c += beans;
    } else {
        c += side;
        beans -= side;
        if (beans <= side) {
            r += beans;
        } else {
            r += side;
            beans -= side;
            if (beans <= side) {
                c -= beans;
            } else {
                c -= side;
                beans -= side;
                r -= beans;
            }
        }
    }
    cout << r << ' ' << c << '\n';
}

void Solve() {
    long long n, b, area, sr, r, c, ring, residue;
    while (cin >> n >> b) {
        area = pow((long double)n, 2);
        sr = sqrt((long double)((long long)area-b));
        if ((n%2) == 0) {
            sr = sr-(sr%2);
            if (pow((long double)sr, 2) != (area-b)) {
                sr += 2;
            }
            r = ((n-sr)/2)+1;
            c = r;
            ring = area-pow((long double)sr, 2);
            residue = b-ring;
            Move(sr-1, r, c, residue-1);
        } else {
            sr = sr-((sr+1)%2);
            if (pow((long double)sr, 2) != (area-b)) {
                sr += 2;
            }
            r = ((n-sr)/2)+1;
            c = r;
            ring = area-pow((long double)sr, 2);
            residue = b-ring;
            Move(sr-1, r, c, residue-1);
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}
