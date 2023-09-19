/* - deque& operator=(const deque &deq); //重载等号操作符 
- assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身
- assign(n, elem); //将n个elem拷贝赋值给本身 */
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int>& t){
    for(deque<int>::const_iterator it = t.begin(); it!=t.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
void test(){
    deque<int>a;
    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }
    printDeque(a);
    //重载等号操作符 
    deque<int>b;
    b=a;
    printDeque(b);
    //将[beg, end)区间中的数据拷贝赋值给本身
    deque<int>c;
    c.assign(b.begin()+5,b.end()-2);
    printDeque(c);
    //将n个elem拷贝赋值给本身
    deque<int>d;
    d.assign(10,100);
    printDeque(d);
}
int main(){
    test();
    return 0;
}
