//构造函数
#include <iostream>
#include <string>
using namespace std;

void test(){
    //默认构造
    string str1;
    //字符串初始化
    const char* str = "hello world";
    string str2(str);
    cout <<"str2="<<str2<<endl;
    //拷贝构造函数
    string str3(str2);
    cout<<"str3="<<str3<<endl;
    //n个字符初始化
    string str4(10,'a');
    cout<<"str4="<<str4<<endl;
}

int main(){
    test();
    return 0;
}