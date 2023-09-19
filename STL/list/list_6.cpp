/* reverse(); //反转链表
sort(); //链表排序 */
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
    list<int>b;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout<<"反转链表前"<<endl;
    printList(a);
    cout<<"反转链表后"<<endl;
    a.reverse();
    printList(a);
    b.push_front(23);
    b.push_front(43);
    b.push_front(34);
    b.push_front(9);
    b.push_front(12);
    cout <<"链表排序前"<<endl;
    printList(b);
    cout <<"链表排序后"<<endl;
    b.sort();
    printList(b);
}
int main()
{
    test();
    return 0;
}