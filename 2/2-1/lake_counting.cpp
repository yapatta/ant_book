#include <iostream>
using namespace std;
typedef long long ll;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
bool field[105][105];
bool visited[105][105];
int cnt = 0;

void dfs(int u,int v){
  visited[u][v] = true;

  for(int i=0;i<8;i++){
    int x = u + dx[i];
    int y = v + dy[i];

    if(0<=x && x<n && 0<=y && y<m && !visited[x][y] && field[x][y]){
      dfs(x,y);
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      visited[i][j] = false;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char a;
      cin >> a;
      if(a=='W') {
        field[i][j] = 1;
      }else {
        field[i][j] = 0;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(field[i][j] && visited[i][j]==false) {
        dfs(i,j);
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}
