#include<bits/stdc++.h>
#define Elemtype int
#define max 100
using namespace std;

//哈曼树定义
typedef struct HuffCode{
    Elemtype weight;//权重
    int lchild;
    int rchild;
    int parent;//定义左右孩子，双亲节点
}codeNode,Huffmancode[max];


typedef char** cd;
//第一个参数是传入数组，第二个值是数组遍历的终点值，用s1,s2返回两个最小值
void select(Huffmancode HC,int n,int& s1,int& s2){
    for(int i = 1;i<n;i++){
        if(HC[i].parent==0){
            s1 = i;
            break;
        }
    }

    for(int i = 1;i<n;i++){
        if(HC[i].parent==0 && HC[s1].weight>HC[i].weight){
            s1 = i;
        }
    }
    for(int j = 1;j<n;j++){
        if(HC[j].parent==0 && j!=s1){
            s2 = j;
            break;
        }
    }

    for(int j = 1;j<n;j++){
        if(HC[j].parent==0 && HC[s2].weight>HC[j].weight && j!=s1){
            s2 = j;
        }
    }
}

//哈夫曼树的构建
void Creat_Huff(Huffmancode& HC,int n){//n为节点数量
    int m = 2*n-1;//需要m大小的数组存数据
    int i,s1,s2;//s1,s2用来返回最小的两个值
    for(i=1;i<=n;i++){//初始化
        HC[i].parent = 0;
        HC[i].lchild = 0;
        HC[i].rchild = 0;
        cin>>HC[i].weight;
    }
    //处理后面的节点
    for(i=n+1;i<=m;i++){
        HC[i].parent = 0;
        HC[i].lchild = 0;
        HC[i].rchild = 0;
        HC[i].weight = 0;
    }
    //选出数组中最小的两个树，构建哈夫曼树
    for(i=n+1;i<=m;i++){
        select(HC,i,s1,s2);
        HC[i].weight = HC[s1].weight+HC[s2].weight;
        HC[i].lchild = s1;
        HC[i].rchild = s2;
        HC[s1].parent = i;
        HC[s2].parent = i;
    }
    cout<<"n"<<"     "<<"w"<<"      "<<"p"<<"      "<<"l"<<"       "<<"r"<<endl;
    for(int i = 1;i<=m;i++){
        cout<<i<<"     "<<HC[i].weight<<"      "<<HC[i].parent<<"     "<<HC[i].lchild<<"      "<<HC[i].rchild<<endl;
        cout<<left;
    }

}

//----------------------------------------------------以上是哈夫曼树的实现在上一节已经实现

//哈夫曼编码实现
void Creat_code(Huffmancode& HC,cd& code,int n){
    code = new char*[n+1]; //分配n个字符编码的头指针矢量
    char* a = new char[n];//分配临时变量用来存编码
    a[n-1] = '\0';//编码结束符
    for(int i =1;i<=n;i++){//逐个字符求哈夫曼编码
        int start = n-1;//开始存放的位置，因为n-1位放的是\0，起始设置在\0
        int c = i;//要找的节点c
        int f = HC[i].parent;//设置双亲节点的初始值
        while(f!=0){//从叶子节点开始回溯，寻找双亲节点为0的位置，也就是根节点
            --start;//初始strar指向\0
            if(HC[f].lchild == c){
                a[start]='0';//双亲节点的左孩子为c则设置为0
            }else{
                a[start]='1';
            }
            c = f;//将这个双亲节点变为孩子节点
            f = HC[f].parent;//下一个要找的双亲节点位置
        }
        code[i] = new char [n-start];
        strcpy(code[i],&a[start]);
    }
    delete a;
}

int main(){
    Huffmancode HC;//创建哈夫曼树
    int n;
    cin>>n;
    cd code;
    Creat_Huff(HC,n);
    Creat_code(HC,code, n);
    for(int i =1;i<=n;i++){
        cout<<code[i]<<" ";
    }
    return 0;
}