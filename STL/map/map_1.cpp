#include <iostream>
#include <map>
using namespace std;
void printMap(const map<int,int>& t ){
    for(map<int,int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<it->first<<" "<<it->second<<" ";
        cout << endl;
    }       
    cout << endl;
}
void test(){
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(5,50));
    cout <<"默认构造"<<endl;
    printMap(m);
    map<int,int>n(m);
    cout <<"拷贝构造"<<endl;
    printMap(n);
    map<int,int>s;
    s=m;
    cout <<"赋值"<<endl;
    printMap(s);
}
int main(){
    test();
    return 0;
}