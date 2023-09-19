/* - vector v; //采用模板实现类实现，默认构造函数 
- vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身
- vector(n, elem); //构造函数将n个elem拷贝给本身
- vector(const vector &vec); //拷贝构造函数 */
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
    //采用模板实现类实现，默认构造函数 
    vector<int>a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    printVector(a);
    //将v[begin(), end())区间中的元素拷贝给本身
    vector<int>b(a.begin(),a.end());
    printVector(b);
    //构造函数将n个elem拷贝给本身
    vector<int>c(10,100);
    printVector(c);
    //拷贝构造函数
    vector<int>d(c);
    printVector(d);
}
int main(){
    test();
    return 0;
}