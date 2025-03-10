#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#include<string>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }
  int art_cnt = 0;
  int art_size = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 0 || vis[i][j] == 1)continue;
      art_cnt++;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({i,j});
      int size = 0;
      while(!Q.empty()){
        size++;
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
      art_size = max(art_size, size);
    }
  }
  cout << art_cnt << "\n" << art_size;
  return 0;
}