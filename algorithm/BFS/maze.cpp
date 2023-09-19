//迷宫问题
#include<iostream>
#include<queue>
using namespace std;

int a[100][100],v[100][100]={0};//a数组用来存数据，v数组用来判断当前路是否是通路

struct point{
    int x;
    int y;
    int step;
};//定义一个结构体其中包括坐标点的信息和当前已走的步数


queue<point> r;//定义一个队列，用来保存当前的坐标步数信息

int dx[4]={0,1,0,-1};//右下左上
int dy[4]={1,0,-1,0};//定义运动的坐标变化

void test(){
    int flag = 0;//用来判断迷宫是否可以成功走出
    int n,m,startx,starty,endx,endy;
    cout<<"请分别输入迷宫的行列"<<endl;
    cin>>n>>m;
    cout<<"请输入迷宫"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    cout<<"请输入分别输入起始坐标的x,y与终点坐标的x,y"<<endl;
    cin>>startx>>starty>>endx>>endy;
    
    point start;//定义刚开始位置的结构体

    start.x = startx;
    start.y = starty;
    start.step = 0;
    v[startx][starty] = 1;//把当前位置的设置为通路

    r.push(start);//将第一个点入队

    while (!r.empty())
    {
        int tmpx,tmpy;
        tmpx = r.front().x;
        tmpy = r.front().y;//如果当前队头的坐标点等于终点坐标的位置
        if(tmpx == endx && tmpy == endy){
            flag = 1;
            cout<<"最少的步数为"<<r.front().step;
            break;
        }
        
        //开始试探四个方向
        for(int k=0;k<4;k++){
            int x,y;
            x = r.front().x + dx[k];
            y = r.front().y + dy[k];

            //如果试探当前的坐标点是通路且没有走过的
            if(a[x][y] == 1 && v[x][y] == 0){
                point tmpe;
                tmpe.x = x;
                tmpe.y = y;
                tmpe.step = r.front().step+1;
                //将数据保存在临时结构体并入队
                r.push(tmpe);
                v[x][y] = 1;
            }
        }
        //一个循环结束后，将队头出队
        r.pop();
    }

    if(flag!=1){
        cout<<"查找最短路径失败";
    }
}

int main(){
    test();
    return 0;
}