#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#include<string>
using namespace std;
#define X first
#define Y second
int board[502][502] = { 0 };
bool vis[502][502] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int mx = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			num++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });
			int artsize = 0;
			while (!Q.empty()) {
				artsize++;
				pair<int, int> cursor = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cursor.X + dx[dir];
					int ny = cursor.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			mx = max(mx, artsize);
		}
	}
	cout << num << "\n" << mx;
}