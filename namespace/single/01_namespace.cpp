#include<iostream>

using namespace std;

namespace my{
    int add(int a,int b){   //写在命名空间的函数
        return a+b;
    }

}

int add(int a,int b){   //一般的普通函数
    return a+b+1;    
}
int main(int argc,char** argv){
    int a=5,b=5;
    cout<< add(a,b) <<endl;
    cout<< my::add(a,b) <<endl;
    return 0;
}