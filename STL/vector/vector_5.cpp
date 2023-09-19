#include <iostream>
#include <vector>
using namespace std;
void test(){
    vector<int>v;
    for(int i;i<10;i++){
        v.push_back(i);
    }
    //返回索引idx所指的数据
    for(int i = 0; i<v.size();i++){
        cout <<v.at(i)<< " ";
    }
    cout << endl;
    //返回索引idx所指的数据
    for(int i = 0; i<v.size();i++){
        cout <<v[i]<< " ";
    } 
    cout << endl;
    //返回容器中第一个数据元素
    cout <<"df "<<v.front()<<endl;
    //返回容器中最后一个数据元素
    cout <<"fdg "<<v.back()<<endl;
}

int main(){
    test();
    return 0;
}