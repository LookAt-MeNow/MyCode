/* - 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值 
- 函数对象超出普通函数的概念，函数对象可以有自己的状态 
- 函数对象可以作为参数传递 */
#include <iostream>
#include <string>
using namespace std;
class Myadd{
public:
    int operator()(int a,int b){
        return a + b;
    }
};
class Myprint{
public:
    Myprint(){
        count = 0;
    }
    void operator()(string a){
        cout << a << endl;
        count++;
    }
    int count;
};

void doPrint(Myprint& t,string p){
    t(p);
}

void test(){
   cout <<"函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值"<<endl;
    Myadd myadd;
    cout <<"myadd(10,30)="<<myadd(10,30)<<endl;
    cout <<"函数对象超出普通函数的概念，函数对象可以有自己的状态"<<endl;
    Myprint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout <<"一共打印了"<<myprint.count<<"次"<<endl;
    cout <<"函数对象可以作为参数传递"<<endl;
    doPrint(myprint,"hello C++");
}
int main(){
    test();
    return 0;
}