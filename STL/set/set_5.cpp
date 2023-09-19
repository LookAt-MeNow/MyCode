#include <iostream>
#include <set>
using namespace std;
void test(){
    set<int>a;
    //判断是否插入成功 
    pair<set<int>::iterator,bool> ret = a.insert(10);
    if(ret.second){
        cout<<"插入成功"<<endl;
    }else{
        cout<<"插入失败"<<endl;
    }
    ret = a.insert(10);
    if(ret.second){
        cout<<"插入成功"<<endl;
    }else{
        cout<<"插入失败"<<endl;
    }
    multiset<int>b;
    b.insert(10);
    b.insert(10);
    b.insert(10);
    b.insert(10);
    for(multiset<int>::iterator it = b.begin();it!=b.end();it++){
        cout<<*it<<" ";
    }
    cout << endl;
}   
int main(){
    test();
    return 0;
}