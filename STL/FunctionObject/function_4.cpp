/* template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数 */

#include <iostream>
#include <functional>
using namespace std;
void test(){
    cout <<"negate()"<<endl;
    negate<int>a;
    cout <<"10取反是"<<a(10)<<endl;
    cout <<"plus()"<<endl;
    plus<int>b;
    cout <<"10+1="<<b(10,1)<<endl;
    cout <<"modulus()"<<endl;
    modulus<int>c;
    cout<<"3模2等于"<<c(3,2)<<endl;
}
int main(){
    test();
    return 0;
}