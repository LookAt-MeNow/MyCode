#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void test(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator it = adjacent_find(v.begin(),v.end());
    if(it == v.end()){
        cout <<"没有找重复的数"<<endl;
    }else{
        cout<<"找到了重复的数字:"<<*it<<endl;
    }
}
int main(){
    test();
    return 0;
}
