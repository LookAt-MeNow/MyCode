#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> t)
{
    for(vector<int>::iterator it = t.begin();it!=t.end();it++){
        cout << *it <<" ";
    }
    cout << endl;
}
void test(){
    vector<int>a;
    vector<int>b;
    for(int i = 0;i<10;i++){
        a.push_back(i);
    }
    for(int i = 10;i>0;i--){
        b.push_back(i);
    }
    cout <<"交换前"<<endl;
    printVector(a);
    printVector(b);
    cout <<"交换后"<<endl;
    a.swap(b);
    printVector(a);
    printVector(b);
}
int main(){
    test();
    return 0;
}