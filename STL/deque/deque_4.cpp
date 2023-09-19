/* push_back(elem); //在容器尾部添加一个数据
push_front(elem); //在容器头部插入一个数据
pop_back(); //删除容器最后一个数据
pop_front(); //删除容器第一个数据 */

/*  */
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int>& t){
    for(deque<int>::const_iterator it = t.begin(); it!=t.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
void test01(){
    //判断容器是否为空
    deque<int>a;
    deque<int>b;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout <<"在容器a尾部添加一个数据"<<endl;
    printDeque(a);
    b.push_front(10);
    b.push_front(20);
    b.push_front(30);
    b.push_front(40);
    b.push_front(50);
    cout <<"在容器b头部插入一个数据"<<endl;
    printDeque(b);
    cout <<"删除容器a最后一个数据"<<endl;
    a.pop_back();
    printDeque(a);
    cout <<"删除容器d第一个数据"<<endl;
    b.pop_front();
    printDeque(b);

}
/* insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos); //删除pos位置的数据，返回下一个数据的位置。
 */
void test02(){
    //判断容器是否为空
    deque<int>a;
    deque<int>b;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    b.push_front(1);
    b.push_front(2);
    b.push_front(3);
    b.push_front(4);
    b.push_front(5);
    cout <<"在pos位置插入一个elem元素的拷贝"<<endl;
    a.insert(a.begin(),100);
    printDeque(a);
    cout<<"在pos位置插入n个elem数据"<<endl;
    a.insert(a.begin(),3,10);
    printDeque(a);
    cout<<"在pos位置插入[beg,end)区间的数据"<<endl;
    a.insert(a.begin(),b.begin(),b.end());
    printDeque(a);
    cout<<"删除[beg,end)区间的数据"<<endl;
    a.erase(a.begin()+1,a.begin()+4);
    printDeque(a);
    cout <<"删除pos位置的数据"<<endl;
    a.erase(a.end());
    printDeque(a);
}
int main(){
    test01();
    test02();
    return 0;
}
