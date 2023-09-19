/* - deque deqT; //默认构造形式 
- deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身
- deque(n, elem); //构造函数将n个elem拷贝给本身
-  deque(const deque &deq); //拷贝构造函数 */
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
    //默认构造形式
    deque<int>a;
    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }
    printDeque(a);
    //构造函数将[beg, end)区间中的元素拷贝给本身
    deque<int>b(a.begin()+5,a.end());
    printDeque(b);
    //构造函数将n个elem拷贝给本身
    deque<int>c(10,100);
    printDeque(c);
    //拷贝构造函数
    deque<int>d(c);
    printDeque(d);
}
int main(){
    test();
    return 0;
}
