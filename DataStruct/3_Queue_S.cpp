//顺序存储实现的队列
#include <iostream>
using namespace std;
#define MaxSize 10
//队列的定义
typedef struct{
    int data[MaxSize];//用静态数组存放队列,一块连续的的储存空间
    int front,rear;//队头指针和队尾指针,队尾指针是指向下一个要插入元素的位置,而不是最后一个元素
    int size;//记录队列长度
}SQueue;

//初始化一个顺序队列
SQueue InitSQueue(){
    SQueue SQ;
    SQ.front=SQ.rear=0;//开始的时候队头和队尾指针都指向,起始位置
    SQ.size=0;
    return SQ;
}
//判断队列是否为空
bool If_empty(SQueue SQ){
    if(SQ.front==SQ.rear&&SQ.size==0){//当两个指针指向同一块位置时判断为空
        return true;
    }else{
        return false;
    }
}
//判断队列是否已满
bool If_full(SQueue SQ){
    if(SQ.size==MaxSize){
        return true;
    }else{
        return false;
    }
}
//入队操作
bool In_queue(SQueue& SQ,int e){
    bool ret = If_full(SQ);
    if(ret){
        cout<<"这个队列已满,入队失败"<<endl;
        return false;
    }
    SQ.data[SQ.rear]=e;//将数据入队
    SQ.rear=(SQ.rear+1)%MaxSize;//实现循环队列
    SQ.size++;//队列长度加1
    return true;
}
//出队操作，并返回出队的值
int Out_queue(SQueue& SQ,int& x){
    if(If_empty(SQ)){
        cout <<"出队失败"<<endl;//判读队列是否为空
        return 0;
    }
    x=SQ.data[SQ.front];
    SQ.front=(SQ.front+1)%MaxSize;
    SQ.size--;
    return x;
}
int main(){
    int m;
    SQueue SQ = InitSQueue();
    for(int i = 0;i<10;i++){
        In_queue(SQ,i);
    }
    for(int i = 0;i<10;i++){
        Out_queue(SQ,m);
        cout <<m<<" ";
    }
    return 0;
}
