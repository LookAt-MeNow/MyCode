#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
void print(int a){
    cout <<a<<" ";
}
class Tranform{
public:
    int operator()(int a){
        return a-1;
    }
};
void test01()
{
    vector<int> v;
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    cout <<"v的数据是"<<endl;
    for_each(v.begin(),v.end(),print);
    cout << endl;
    vector<int> v2;
    v2.resize(v.size());//不开辟空间不能运行
    cout<<"把v中的元素都-1再传入v2"<<endl;
    transform(v.begin(), v.end(), v2.begin(),Tranform());
    cout <<"v2的数据是"<<endl;
    for_each(v2.begin(),v2.end(),print);
}
int main()
{
    test01();
    return 0;
}