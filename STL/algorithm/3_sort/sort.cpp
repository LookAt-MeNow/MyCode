#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void myPrint(int a){
    cout <<a<<" ";
}
void test(){
    vector<int>a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(1);
    a.push_back(5);
    a.push_back(3);
    cout <<"从小到大排序"<<endl;
    sort(a.begin(),a.end());
    for_each(a.begin(),a.end(),myPrint);
    cout << endl;
    cout <<"从大到小排序"<<endl;
    sort(a.begin(),a.end(),greater<int>());
    for_each(a.begin(),a.end(),myPrint);
}
int main(){
    test();
    return 0;
}
