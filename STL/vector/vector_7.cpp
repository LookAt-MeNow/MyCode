#include <iostream>
#include <vector>
using namespace std;
//不预留空间，看看空间开辟次数
void test01(){
    vector<int>a;
    int num=0;
    int *p = NULL;
    for(int i = 0;i<100000;i++){
        a.push_back(i);
        if(p!=&a[0]){
            p=&a[0];
            num++;
        }
    }
    cout <<"开辟次数:"<<num<<endl;
}
//预留空间
void test02(){
    vector<int>a;
    a.reserve(100000);
    int num=0;
    int *p = NULL;
    for(int i = 0;i<100000;i++){
        a.push_back(i);
        if(p!=&a[0]){
            p=&a[0];
            num++;
        }
    }
    cout <<"开辟次数:"<<num<<endl;
}
int main(){
    test01();
    test02();
    return 0;
}