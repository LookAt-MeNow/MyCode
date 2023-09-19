/* - size(); //返回容器中元素的数目 
- empty(); //判断容器是否为空 
- swap(st); //交换两个集合容器 */
#include <iostream>
#include <map>
using namespace std;
void printMap(const map<int,int>& t ){
    for(map<int,int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<it->first<<" "<<it->second<<"|";
    }       
    cout << endl;
}
void if_empty(const map<int,int>& t ){
    if(t.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout <<"这个容器不是空的,大小为"<<t.size()<<endl;
    }
}
void test(){
    map<int,int>m;
    map<int,int>n;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(5,50));
    if_empty(m);
    if_empty(n);
    map<int,int>s;
    s.insert(pair<int,int>(1,22));
    s.insert(pair<int,int>(2,32));
    cout <<"交换前"<<endl;
    printMap(m);
    printMap(s);
    cout <<"交换后"<<endl;
    m.swap(s);
    printMap(m);
    printMap(s);
}
int main(){
    test();
    return 0;
}