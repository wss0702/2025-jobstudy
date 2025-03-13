#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define X first
#define Y second
int dist[100002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, K;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	dist[N] = 0;
	queue<int>Q;
	Q.push(N);
	while (dist[K] == -1) {
		int cursor = Q.front();
		Q.pop();
		for (int nxt : {cursor - 1, cursor + 1, 2 * cursor}) {
			if (nxt < 0 || nxt >100000)continue;
			if (dist[nxt] != -1)continue;
			dist[nxt] = dist[cursor] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[K];
}