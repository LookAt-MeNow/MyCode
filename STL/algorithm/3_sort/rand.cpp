#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
void myPrint(int a){
    cout <<a<<" ";   
}
void test(){
    //设置随机数种子
    srand((unsigned int)time(NULL));
    vector<int>a;
    for(int i =0;i<10;i++){
        a.push_back(i);
    }
    random_shuffle(a.begin(),a.end());//如果不设置随机数种子那么每次运行生成的随机数都一样
    for_each(a.begin(),a.end(),myPrint);
}
int main(){
    test();
    return 0;
}