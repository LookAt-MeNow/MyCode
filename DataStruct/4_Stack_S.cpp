#include <iostream>
using namespace std;
#define MaxSize 10
//定义顺序栈
typedef struct{
    int data[MaxSize];//静态数组存放元素
    int top;//栈顶指针
}SStack;

//初始化栈
SStack InitSStack(){
    SStack SS;
    SS.top=-1;//栈顶指针指向-1
    return SS;
}
//判断栈是否为空
bool If_empty(SStack SS){
    return SS.top==-1;
}
//判断栈是否已满
bool If_full(SStack SS){
    return SS.top==MaxSize-1;
}
//进栈
bool Push(SStack& SS,int x){
    if(SS.top==MaxSize-1){
        cout <<"入栈失败"<<endl;
        return false;
    }
    SS.data[++SS.top] = x;
    return true;
}
//出栈并返回值
int pop(SStack& SS){
    if(If_empty(SS)){
        cout<<"出栈失败"<<endl;
        return false;
    }
    int item;
    item  = SS.data[SS.top];
    SS.top--;
    return item;
}
int main(){
    SStack SS=InitSStack();
    for(int i=0;i<10;i++){
        Push(SS,i);
    }
    int item;
    for(int i=0;i<10;i++){
        item=pop(SS);
        cout <<item<<" ";
    }
    return 0;
}