#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
#define X first 
#define Y second
bool vis[50][50];
int board[50][50];
int num[51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int T,M,N,K;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}
		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
				num++;
				queue<pair<int, int>>Q;
				vis[i][j] = true;
				Q.push({ i, j });
				while (!Q.empty()) {
					auto cursor = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cursor.X + dx[dir];
						int ny = cursor.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = true;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << num << "\n";
		for (int i = 0; i < N; i++) {
			fill(board[i], board[i] + M, 0);
			fill(vis[i], vis[i] + M, 0);
		}
	}
	return 0;
}