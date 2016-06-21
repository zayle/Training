#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct Coord {
    int x;
    int y;
};

bool operator<(Coord a, Coord b) {
    if (a.x == b.x) {
        return (a.y > b.y);
    } else {
        return (a.x < b.x);
    }
}

const int mx = 3000;
const int lmt = -100000001;
Coord coords[mx];
int n;

int CountToRight() {
    int i, j, count = 0;
    Coord top, bot, aux;
    for (i = 0; i < n; i++) {
        top = coords[i];
        bot.y = lmt;
        for (j = i+1; j < n; j++) {
            aux = coords[j];
            if (aux.x == top.x) {
                if (bot.y == lmt) {
                    bot = aux;
                }
            } else {
                if ((bot.y < aux.y) && (aux.y < top.y)) {
                    count++;
                    bot = aux;
                }
            }
        }
    }
    return count;
}

int CountToLeft() {
    int i, j, count = 0;
    Coord top, bot, aux;
    for (i = n-1; i > -1; i--) {
        top = coords[i];
        bot.y = lmt;
        for (j = i-1; j > -1; j--) {
            aux = coords[j];
            if (aux.x == top.x) {
                if (bot.y == lmt) {
                    bot = top;
                    top = aux;
                }
            } else {
                if ((bot.y < aux.y) && (aux.y < top.y)) {
                    count++;
                    bot = aux;
                }
            }
        }
    }
    return count;
}

void Solve() {
    int i, answer;
    while (cin >> n) {
        for (i = 0; i < n; i++) {
            cin >> coords[i].x;
            cin >> coords[i].y;
        }
        sort(coords, coords+n);
        answer = CountToRight();
        answer += CountToLeft();
        cout << answer << '\n';
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// ========== //
	Solve();
	return 0;
}
