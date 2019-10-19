#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int N,M;
char maze[105][105];
int searched[105][105];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

//s: start, g:goal
int sy,sx,gy,gx;
void bfs(int fy,int fx);

int main(){
  cin >> N >> M;

  //初期化
  for(int y=0;y<N;y++){
    for(int x=0;x<M;x++){
      searched[y][x] = INF;
    }
  }

  for(int y=0;y<N;y++){
    for(int x=0;x<M;x++){
      cin >> maze[y][x];
    }
  }
  for(int y=0;y<N;y++){
    for(int x=0;x<M;x++){
      //初期地点
      if(maze[y][x]=='S'){
        sy = y;
        sx = x;
      }
      if(maze[y][x]=='G'){
        maze[y][x] = '.';
        gy = y;
        gx = x;
      }
    }
  }
  bfs(sy, sx);
  cout << searched[gy][gx] << endl;
}

void bfs(int fy,int fx){
  searched[fy][fx] = 0;
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(fy,fx,0));

  while(!q.empty()){
    tuple<int,int,int> tmp = q.front(); q.pop();
    int beforeY = get<0>(tmp);
    int beforeX = get<1>(tmp);

    for(int i=0;i<4;i++){
      int y = beforeY + dy[i];
      int x = beforeX + dx[i];
      if(0<=y && y<N && 0<=x && x<M && searched[y][x]==INF && (maze[y][x]=='.')){
        searched[y][x] = min(searched[y][x], searched[beforeY][beforeX]+1);
        if(y==gy && x==gx){
          return;
        }
        q.push(make_tuple(y,x,get<2>(tmp)+1));
      }
    }
  }
}
