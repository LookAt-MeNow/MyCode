#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class My{
public:
    bool operator()(int a){
        return a>5;
    }
};

void test(){
    vector<int>a;
    for(int i = 0; i<10; i++){
        a.push_back(i);
    }
    vector<int>::iterator it = find_if(a.begin(),a.end(),My());//My()是匿名函数
    //这里使用了find_if算法
    if(it == a.end()){
        cout <<"没有找到" <<endl;
    }else{
        cout <<"找到了大于5的数为:"<<*it<<endl;
    }
}
int main(){
    test();
    return 0;
}