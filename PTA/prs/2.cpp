#include<bits/stdc++.h>
void test(){
    int x;
    char t;
    std::cin>>x;
    std::cin>>t;
    int total = 1;
    int sum=1;
    int cen;
    while(total<x){
        int temp = total;
        sum+=2;
        temp+=sum*2;
        if(x<temp){
            break;
        }
        cen++;
        total = temp;
    }
    int i=cen;
    int m=1;
    int cnt=0;
    for(i;i>0;i--){
        for(int k=i*2+1;k>0;k--)    std::cout<<t;
        for(int j=1;j<m;j++)        std::cout<<" ";
        std::cout<<std::endl;
        for(int j=1;j<=m;j++)       std::cout<<" ";
        m++;
        cnt++;
    }
    std::cout<<t<<std::endl;
    int j=1;
    for(j;j<=cen;j++){
        int n=cnt-1;
        for(n;n>0;n--)              std::cout<<" ";
        for(int k=1;k<=j*2+1;k++)   std::cout<<t;
        std::cout<<std::endl;
        cnt--;
    }
    std::cout<<x-total;
}
int main(){
    test();
    return 0;
}