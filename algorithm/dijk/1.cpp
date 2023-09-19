#include<iostream>
#define V 20 //顶点的最大个数
#define INFINITY 65535
typedef struct{
    int vexs[V];    // 储存图中的顶点数据
    int arcs[V][V]; //二维数组记录顶点之间的关系
    int vexnum,arcnum;  // 记录图的顶点数和弧数
}MGraph;

//根据顶点本身的数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph* G,int v){
    int i=0;
    for(;i<G->vexnum;i++){
        if(v == G->vexs[i]){ 
            break;//遍历数组找到位置
        }
    }
    if(i>G->vexnum){
        std::cout<<"not find"<<std::endl;
        return -1;
    }
    return i;
}


//构造无向有权图

void Init_GM(MGraph* G){
    std::cout<<"set spot and side"<<std::endl;
    std::cin>>G->vexnum>>G->arcnum;
    std::cout<<"set spot info"<<std::endl;

    for(int i=0;i<G->vexnum;i++){
        std::cin>>G->vexs[i];
    }

    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            G->arcs[i][j] = INFINITY; // 初始化一开始的距离
        }
    }

    std::cout<<"set side data"<<std::endl;
    for(int i=0;i<G->arcnum;i++){
        int v1,v2,w;//边关联的两个顶点和权值
        std::cin>>v1>>v2>>w;
        int n=LocateVex(G,v1);//查找位置
        int m=LocateVex(G,v2);
        if(n==-1 || m==-1) return;
        G->arcs[n][m] = w;
        G->arcs[m][n] = w;
    }
}

//迪杰斯特拉算法
void Dijkstra_minTree(MGraph G,int v0,int p[V],int d[V]){ // v0代表其实坐标点的数组下标
    int find_min[V]; // 判断各个顶点是否已经是最短路径
    for(int i=0;i<G.vexnum;i++){
        find_min[i] = 0;//最小状态数组
        d[i] = G.arcs[v0][i];
        p[i] = 0;
    }//初始化

    d[v0] = 0;
    find_min[v0] = 1;
    int k = 0;
    for(int i=0;i<G.vexnum;i++){
        int min = INFINITY;
        for(int w=0;w<G.vexnum;w++){
            if(!find_min[w]){
                if(d[w]<min){//比较每个节点
                    k = w;
                    min = d[w];
                }
            }
        }
        find_min[k] = 1;
        for(int w=0;w<G.vexnum;w++){
            if(!find_min[w] && (min+G.arcs[k][w] < d[w])){
                d[w] = min + G.arcs[k][w];//刷新最短路径
                p[w] = k;
            }
        }
    }
    for (int i = 0; i < G.vexnum ; i++) { std::cout << "Distance from 0 to " << i << " is " <<d[i] << std::endl; }
}

int main(){
    MGraph G;
    Init_GM(&G);
    int p[V];
    int d[V];
    Dijkstra_minTree(G,0,p,d);
    return 0;
}