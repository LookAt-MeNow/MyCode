/* - set st; //默认构造函数
-  set(const set &st); //拷贝构造函数
- set& operator=(const set &st); //重载等号操作符 */
#include <iostream>
#include <set>
using namespace std;
void printSet(const set<int>& t){
    for(set<int>::const_iterator it = t.begin();it!=t.end();it++){
        cout<<*it<<" ";
    }
    cout << endl;
}
void test(){
    set<int>a;
    a.insert(20);
    a.insert(50);
    a.insert(30);
    a.insert(10);
    a.insert(40);
    cout <<"默认构造函数"<<endl;
    printSet(a);
    cout <<"拷贝构造函数"<<endl;
    set<int>b(a);
    printSet(b);
    cout <<"重载等号操作符"<<endl;
    set<int>c;
    c=a;
    printSet(c);
}   
int main(){
    test();
    return 0;
}