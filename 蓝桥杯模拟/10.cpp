/* 　　小蓝有一个序列 a[1], a[2], ..., a[n]，每次可以交换相邻的两个元素，代价为两个元素中较大的那个。
　　请问，要通过交换将序列变为从小到大递增的序列，总代价最少为多少？ */
/* 　　输入一行包含一个整数 n ，表示序列长度。
　　第二行包含 n 个整数，表示给定的序列。 */
#include<iostream>
using namespace std;
void paixu(){
    int t;
    int k=0;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<=t;i++){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            k+=a[i+1];    
        }
    }
    cout <<k;
}

int main(){
    paixu();
    return 0;
}