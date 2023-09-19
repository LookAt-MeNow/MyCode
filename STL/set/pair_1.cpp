#include <iostream>
#include <string>
using namespace std;
int main(){
    pair<string,int>a("张三",18);
    pair<string,int> b = make_pair("李四",20);
    cout <<"第一个人叫"<<a.first<<"年龄是"<<a.second<<endl;
    cout <<"第二个人叫"<<b.first<<"年龄是"<<b.second<<endl;
    return 0;
}
