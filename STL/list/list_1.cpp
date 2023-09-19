/* - list lst; //list采用采用模板类实现,对象的默认构造形式：
-  list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身
-  list(n,elem); //构造函数将n个elem拷贝给本身
-  list(const list &lst); //拷贝构造函数
 */
#include<iostream>
#include<list>
using namespace std;
void printList(const list<int>& t){
    for(list<int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
void test(){
    
    list<int>a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout<<"list采用采用模板类实现,对象的默认构造形式："<<endl;
    printList(a);
    a.pop_front();
    a.pop_back();
    cout <<"构造函数将[beg, end)区间中的元素拷贝给本身"<<endl;
    list<int>b(a.begin(),a.end());
    printList(b);
    cout <<"构造函数将n个elem拷贝给本身"<<endl;
    list<int>c(5,10);
    printList(c);
    c.pop_back();
    c.pop_front();
    cout <<"拷贝构造函数"<<endl;
    list<int>d(c);
    printList(d);
}
int main(){
    test();
    return 0;
}