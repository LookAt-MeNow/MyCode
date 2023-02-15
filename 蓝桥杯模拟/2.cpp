/* 我们计从 1949 年 10 月 1 日至 1949 年 10 月 2 日为经过了 1 天。
　　请问从 1949 年 10 月 1 日至 2022 年 1 月 1 日经过了多少天？ */
#include<iostream>
using namespace std;

int main(){
    int k;
    for(int a=1950;a<=2021;a++){
        if(a%400==0 || a%4==0 && a%100!=0){
            k++;
        }
    }
    int m;
    int q;
    m=71-k;
    q=m*365+k*366+91;
    cout<<q;
    return 0;
}