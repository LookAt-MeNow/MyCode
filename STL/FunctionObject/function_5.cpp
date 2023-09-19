#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
void test(){
    vector<int>a;
    a.push_back(21);
    a.push_back(12);
    a.push_back(31);
    a.push_back(2);
    a.push_back(11);
    cout <<"排序前"<<endl;
    for(vector<int>::iterator it =a.begin();it!=a.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
    sort(a.begin(),a.end(),greater<int>());
    cout <<"排序后"<<endl;
    for(vector<int>::iterator it =a.begin();it!=a.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
int main(){
    test();
    return 0;
}