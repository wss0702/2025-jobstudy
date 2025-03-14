#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int dist[103][103][103];
int board[103][103][103];
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int M, N, H;
queue<tuple<int, int, int>>Q;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int tomato;
				cin >> tomato;
				board[j][k][i] = tomato;
				if (tomato == 1) {
					Q.push({ j,k,i });
				}
				if (tomato == 0) {
					dist[j][k][i] = -1;
				}
			}
		}
	}
	while (!Q.empty()) {
		auto cursor = Q.front(); 
		Q.pop();
		int cursorX, cursorY, cursorZ;
		tie(cursorX, cursorY, cursorZ) = cursor;
		for (int dir = 0; dir < 6; dir++) {
			int nx = cursorX + dx[dir];
			int ny = cursorY + dy[dir];
			int nz = cursorZ + dz[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[cursorX][cursorY][cursorZ] + 1;
			Q.push({ nx,ny,nz });
		}
	}
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans;
	return 0;
	
}