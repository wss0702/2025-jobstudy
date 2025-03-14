#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#include<string>
#include<tuple>
using namespace std;
//tuple사용법 어렵네;;

int board[102][102][102];


int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int vis[102][102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, H;
  cin >> N >> M >> H;
  queue<tuple<int,int,int>>Q;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < M; j++){
      for(int k = 0; k < N; k++){
        cin >> board[i][j][k];
        if(board[i][j][k] == 1){
          Q.push({i,j,k});
      }
      if(board[i][j][k] == 0){
        vis[i][j][k] = -1;
        }
      }
    }
  }
    
    
  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();
		int cursorX, cursorY, cursorZ;
		tie(cursorX, cursorY, cursorZ) = cur;
    for(int i = 0; i < 6; i++){
      int nh,nm,nn;
      nh = cursorX + dx[i];
      nm = cursorY + dy[i];
      nn = cursorZ+ dz[i];
      if(nh < 0 || nh >= H || nm < 0 || nm >= M || nn < 0 || nn >= N ) continue;
      if(vis[nh][nm][nn] >= 0 || board[nh][nm][nn] == -1) continue;
      vis[nh][nm][nn] = vis[cursorX][cursorY][cursorZ] + 1;
      Q.push({ nh,nm,nn });
    }
  }
  int ans = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < M; j++){
      for(int k = 0; k < N; k++){
        if(vis[i][j][k] == -1){
          cout << -1;
          return 0;
        }
        ans = max(ans,vis[i][j][k]);
      }
    }
  }
  cout << ans;
  return 0;
}