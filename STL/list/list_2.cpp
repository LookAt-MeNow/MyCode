/* assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
list& operator=(const list &lst); //重载等号操作符
swap(lst); //将lst与本身的元素互换。 */
#include <iostream>
#include <list>
using namespace std;
void printList(const list<int>& t){
    for(list<int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<*it <<" ";
    }
    cout << endl;
}
void test(){
    list<int>a;
    for(int i = 0;i<10;i++){
        a.push_back(i);
    }
    cout <<"将[beg, end)区间中的数据拷贝赋值给本身。"<<endl;
    list<int>b;
    b.assign(a.begin(),a.end());
    printList(b);
    cout <<"将n个elem拷贝赋值给本身。"<<endl;
    list<int>c(10,5);
    printList(c);
    cout <<"重载等号操作符"<<endl;
    a.pop_back();
    a.pop_front();
    list<int>d;
    d=a;
    printList(d);
    cout <<"将lst与本身的元素互换"<<endl;
    d.swap(b);
    printList(d);
}
int main()
{
    test();
    return 0;
}