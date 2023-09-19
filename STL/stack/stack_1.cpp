#include<iostream>
#include<stack>
using namespace std;
void test(){
    //构造函数创建
    stack<int>a;
    //数据存取
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    cout <<"这个栈的大小是:"<<a.size()<<endl;
    //栈是不能遍历的
    while(!a.empty()){
        //查看栈顶数据
        cout <<"栈顶数据是:"<<a.top()<<endl;
        //出栈
        a.pop();
    }
    cout <<"这个栈的大小是:"<<a.size()<<endl;
}
int main(){
    test();
    return 0;
}