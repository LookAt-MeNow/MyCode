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
    v.push_back(4);
    v.push_back(5);
    bool ret = binary_search(v.begin(),v.end(),3);
    if(ret){
        cout<<"找到了"<<endl;
    }else{
        cout<<"没有找到"<<endl;
    }
}
int main(){
    test();
    return 0;
}
