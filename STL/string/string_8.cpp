
//string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串#include<iostream>
#include<string>
#include<iostream>
using namespace std;
//截取用户名
void test(){
    string emil = "zhangfsdf@qq.com";
    int pos=emil.find("@");
    string emilUser = emil.substr(0,pos);
    cout <<"emilUser is "<<emilUser<<endl;
}

int main(){
    test();
    return 0;
}