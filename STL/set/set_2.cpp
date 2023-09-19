/* - size(); //返回容器中元素的数目
- empty(); //判断容器是否为空 
- swap(st); //交换两个集合容器 */
#include <iostream>
#include <set>
using namespace std;
void printSet(const set<int>& t){
    for(set<int>::const_iterator it = t.begin();it!=t.end();it++){
        cout<<*it<<" ";
    }
    cout << endl;
}
void if_empty(const set<int>& t){
    if(t.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout<<"这个容器不是空的,并且容器大小为:"<<t.size()<<endl;
    }
}
void test(){
    set<int>a;
    a.insert(20);
    a.insert(50);
    a.insert(30);
    a.insert(10);
    a.insert(40);
    set<int>b;
    b.insert(1);
    b.insert(5);
    b.insert(2);
    b.insert(4);
    b.insert(3);
    set<int>c;
    if_empty(a);
    if_empty(c);
    cout <<"交换前"<<endl;
    printSet(a);
    printSet(b);
    cout <<"交换后"<<endl;
    a.swap(b);
    printSet(a);
    printSet(b);
}   
int main(){
    test();
    return 0;
}