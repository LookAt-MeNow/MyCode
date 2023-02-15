/* 　　请找到一个大于 2022 的最小数，这个数转换成二进制之后，最低的 6 个二进制为全为 0 。
　　请将这个数的十进制形式作为答案提交 */
#include<iostream>
using namespace std;
int* test(int a){
    int m[20];
    int t=0;
    if(a!=0){
        t=a%2;
        a=a/2;
        test(a);
        cout <<t;
        m[p]=t;
        p++;
    }
    return m;
}
static int p=0;
int main(){
    int a=2022;
    int *m;
    m=test(a);
    cout<<endl;
    for(int i=0;i<p;i++){
        cout<<*m;
    }
    return 0;
}