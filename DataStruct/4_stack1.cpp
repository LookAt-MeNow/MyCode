#include <iostream>
using namespace std;
#define MaxSize 10
//定义顺序栈
typedef struct{
    char data[MaxSize];//静态数组存放元素
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
bool Push(SStack& SS,char x){
    if(SS.top==MaxSize-1){
        cout <<"入栈失败"<<endl;
        return false;
    }
    SS.data[++SS.top] = x;
    return true;
}
//出栈并返回值
char pop(SStack& SS){
    if(If_empty(SS)){
        cout<<"出栈失败"<<endl;
        return false;
    }
    char item;
    item  = SS.data[SS.top];
    SS.top--;
    return item;
}

bool BraceMatch(char* str,int len){
    SStack SS = InitSStack();//初始化栈
    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            Push(SS,str[i]);//扫描到左括号入栈
        }else{
            if(If_empty(SS))
                return false;//如果没有扫描到左括号并且栈为空返回false
            //这个时候左括号扫描完了，可以出栈左括号了
            char item = pop(SS);//用item接受出栈的值进行匹配
            if(str[i]==')' && item!='('){
                return false;//括号不匹配
            }
            if(str[i]==']' && item!='['){
                return false;//括号不匹配
            }
            if(str[i]=='}' && item!='{'){
                return false;//括号不匹配
            }
        }
    }
    return If_empty(SS);//如果全部成功出栈返回true
}

int main(){
    char* str;
    int len = 6;
    for(int i = 0;i<len;i++){
        cin>>str[i];
    }
    if(BraceMatch(str,len)){
        cout <<"匹配成功";
    }else{
        cout <<"匹配失败";
    }
    return 0;
}