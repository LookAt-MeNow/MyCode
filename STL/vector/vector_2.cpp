/* vector& operator=(const vector &vec); //重载等号操作符

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身

assign(n, elem); //将n个elem拷贝赋值给本身 */
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int>& t){
    for(vector<int>::iterator it=t.begin();it!=t.end();it++){
        cout <<(*it)<<" ";
    }
    cout << endl;
}
void test(){
    vector<int>a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    printVector(a);
    //重载等号操作符
    vector<int>b;
    b=a;
    printVector(b);
    //将[beg, end)区间中的数据拷贝赋值给本身
    vector<int>c;
    c.assign(b.begin(),b.end());
    printVector(c);
    //将n个elem拷贝赋值给本身
    vector<int>d;
    d.assign(10,100);
    printVector(d);
}
int main(){
    test();
    return 0;
}