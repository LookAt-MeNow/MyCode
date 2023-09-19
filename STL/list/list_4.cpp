/* - push_back(elem);//在容器尾部加入一个元素 
- pop_back();//删除容器中最后一个元素 
- push_front(elem);//在容器开头插入一个元素 
- pop_front();//从容器开头移除第一个元素 
- insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置
- insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
-  insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
- clear();//移除容器的所有数据
-  erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
-  erase(pos);//删除pos位置的数据，返回下一个数据的位置
-  remove(elem);//删除容器中所有与elem值匹配的元素 */
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
    cout <<"在a容器尾部加入一个元素 "<<endl;
    printList(a);
    cout <<"删除a容器中最后一个元素 "<<endl;
    a.pop_back();
    printList(a);
    b.push_front(10);
    b.push_front(20);
    b.push_front(30);
    b.push_front(40);
    b.push_front(50);
    cout <<"在容器b开头插入一个元素 "<<endl;
    printList(b);
    cout <<"删除容器b中第一个元素"<<endl;
    b.pop_front();
    printList(b);
    cout <<"在pos位置插elem元素的拷贝"<<endl;
    list<int>::iterator it = a.begin();
    a.insert(++it,114514);
    printList(a);
    cout <<"删除容器中所有与elem值匹配的元素"<<endl;
    b.remove(30);
    printList(b);
    cout <<"输入想删除pos位置的数据"<<endl;
    int n;
    cin>>n;
    it=a.begin();
    for(int i=0;i<n-1;i++){
        it++;
    }
    a.erase(it);
    printList(a);
}
int main()
{
    test();
    return 0;
}