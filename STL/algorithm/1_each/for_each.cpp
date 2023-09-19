#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int a){
    cout <<a<<" ";
}
class Myprint{
public:
    void operator()(int a){
        cout <<a<<" ";
    }
};
void test(){
    vector<int>a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout <<"普通函数"<<endl;
    for_each(a.begin(),a.end(),print);
    cout << endl;
    cout <<"函数对象"<<endl;
    for_each(a.begin(),a.end(),Myprint());
}
int main(){
    test();
    return 0;
}