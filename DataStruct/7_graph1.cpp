#include<bits/stdc++.h>
/* 1. 输入节点数，和边数
2. 输入节点信息，存入一个数组中
3. 初始化邻接矩阵，如果是图初始化为0，如果是网，初始化无穷大
4. 依次输入每条边依附的两个节点，如果有权值，还要输入权值 */
//两个数组一个用来存顶点表，一个用来存邻接矩阵
using namespace std;
#define min 0 //初始化值
#define MAXNum 100
typedef char vre;//顶点的数据类型
typedef int arc;//边的权值

typedef struct{
    vre v[MAXNum];//创建顶点表
    arc a[MAXNum][MAXNum];//创建邻接矩阵
    int spot,side;//顶点数和边数
}AMGraph;

int LocateVex(AMGraph G,int v1){
    for(int i =0;i<G.spot;i++){
        if(G.v[i] == v1){
            return i;
        }
    }
    return 0;
}


//创建无向网
void Creat_UDN(AMGraph& G){
    char v1,v2;
    int w;
    cout<<"分别输入节点和边的数量"<<endl;
    cin>>G.spot>>G.side;//输入边和点
    cout<<"输入节点信息"<<endl;
    for(int i =0;i<G.spot;i++){
        cin>>G.v[i];//输入点的信息
    }
    for(int i =0;i<G.spot;i++){
        for(int j =0;j<G.spot;j++){
            G.a[i][j] = min;//设置边的权值
        }
    }//初始化边

    cout<<"输入每条边依附的节点以及权值"<<endl;
    for(int k =0;k<G.side;k++){    
        cin>>v1>>v2>>w;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.a[i][j] = w;
        //cout<<G.a[i][j]<<" ";
        G.a[j][i] = G.a[i][j]  ;
        //cout<<G.a[j][i]<<endl;
    }
    cout<<"图的邻接矩阵为:"<<endl;
    for (int i = 0; i < G.spot; i++)
    {
        for(int j=0;j<G.spot;j++){
            cout<<G.a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    AMGraph G;
    Creat_UDN(G);
    return 0;
}