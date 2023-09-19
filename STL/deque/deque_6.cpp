/* sort算法非常实用，使用时包含头文件 algorithm即可 */
#include <iostream>
#include <deque>
#include <algorithm>
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
    a.push_back(12);
    a.push_back(43);
    a.push_back(21);
    a.push_back(1);
    a.push_back(90);
    a.push_back(3);
    printDeque(a);
    sort(a.begin(),a.end());
    printDeque(a);
}
int main(){
    test();
    return 0;
}