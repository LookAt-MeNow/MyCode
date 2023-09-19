/* - at(int idx); //返回索引idx所指的数据 
- operator[]; //返回索引idx所指的数据 
- front(); //返回容器中第一个数据元素
- back(); //返回容器中最后一个数据元素 */

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
    cout <<"返回索引idx所指的数据 at(5)="<<a.at(5)<<" a[4]="<<a[4]<<endl;
    cout <<"返回容器中第一个数据元素 a.front()="<<a.front()<<endl;
    cout <<"返回容器中最后一个数据元素 a.back()="<<a.back()<<endl;
    printDeque(a);

}
int main(){
    test();
    return 0;
}
