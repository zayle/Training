#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

struct State {
	short pr;
	short pc;
	short qr;
	short qc;
};

const short mx = 100;
short rows, cols, k;
char mp[mx][mx];
short xr, xc;
queue<State> pq;
bool used[mx][mx][mx][mx];

void LoadData() {
	short r, c;
	State stt;
	cin >> rows >> cols >> k;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			cin >> mp[r][c];
			if (mp[r][c] == 'p') {
				stt.pr = r;
				stt.pc = c;
			} else if (mp[r][c] == 'q') {
				stt.qr = r;
				stt.qc = c;
			} else if (mp[r][c] == 'x') {
				xr = r;
				xc = c;
			}
		}
	}
	pq.push(stt);
}

void AddState(short pr, short pc, short qr, short qc) {
	if (!used[pr][pc][qr][qc]) {
		if ((mp[pr][pc] != '#') && (mp[qr][qc] != '#')) {
			if ((abs(pr - qr) + abs(pc - qc)) <= k) {
				State stt;
				stt.pr = pr;
				stt.pc = pc;
				stt.qr = qr;
				stt.qc = qc;
				pq.push(stt);
			}
		}
	}
}

void Solve() {
	int i;
	int size;
	int steps = 0;
	State stt;
	while(!pq.empty()) {
		size = pq.size();
		for (i = 0; i < size; i++) {
			stt = pq.front();
			if (!used[stt.pr][stt.pc][stt.qr][stt.qc]) {
				used[stt.pr][stt.pc][stt.qr][stt.qc] = true;
				if ((stt.pr == xr) && (stt.pc == xc) && (stt.qr == xr) && (stt.qc == xc)) {
					cout << steps << '\n';
					return;
				}
				AddState(stt.pr, stt.pc-1, stt.qr, stt.qc);
				AddState(stt.pr, stt.pc+1, stt.qr, stt.qc);
				AddState(stt.pr-1, stt.pc, stt.qr, stt.qc);
				AddState(stt.pr+1, stt.pc, stt.qr, stt.qc);
				AddState(stt.pr, stt.pc, stt.qr, stt.qc-1);
				AddState(stt.pr, stt.pc, stt.qr, stt.qc+1);
				AddState(stt.pr, stt.pc, stt.qr-1, stt.qc);
				AddState(stt.pr, stt.pc, stt.qr+1, stt.qc);
			}
			pq.pop();
		}
		steps++;
	}
	cout << -1 << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadData();
	Solve();
	return 0;
}