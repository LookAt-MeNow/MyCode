#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//试探数组
int dx[4] = {0,-1,0,1};//右下左上
int dy[4] = {1,0,-1,0};
const char n=30,m=60;
int a[n][m];
int bfs(int x,int y){
    int cnt=1;
    for(int k =0;k<4;k++){
        x+=dx[k];
        y+=dy[k];
        if(x<=n&&y<=m&&x>=0&&y>=0 && a[x][y]==1){
            cnt+=bfs(x,y);
        }
    }
    return cnt;
}

int main(){
    int cnt=0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j]==1){
                cnt=max(cnt,bfs(i,j));
            }
        }
    }
    cout <<cnt;
    return 0;
}