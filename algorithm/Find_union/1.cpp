//基本模板
#include<bits/stdc++.h>
using namespace std;

//初始化
void init_union(int* a,int N){
    for(int i=0;i<N;i++){
        a[i] = i;
    }
}

//查找  找到根结点  只有根节点的值和初始化值相等
int find(int* a,int& x){
    if(x!=a[x]){
        x = a[x];
    }
    return x;
}

//合并
void unionEle(int* a,int x,int y){
    int temp1 = find(a,x);
    int temp2 = find(a,y);
    if(temp1 == temp2){
        return;
    }
    a[temp1] = temp2;
}

int main(){
    int M;
    int N;
    cin>>N>>M;
    int op,x,y;
    int a[N];
    init_union(a,N);
    for(int i=0;i<M;i++){
        cin>>op;
        if(op == 1){
            cin>>x>>y;
            unionEle(a,x,y);
        }
        if(op == 2){
            cin>>x>>y;
            int tempx = find(a,x);
            int tempy = find(a,y);
            if(tempx == tempy){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}