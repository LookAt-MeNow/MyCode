/* 对于一个日期，我们可以计算出年份的各个数位上的数字之和，也可以分别计算月和日的各位数字之和。
请问从 1900 年 1 月 1 日至 9999 年 12 月 31 日，总共有多少天，
年份的数位数字之和等于月的数位数字之和加日的数位数字之和。
例如，2022年11月13日满足要求，因为 2+0+2+2=(1+1)+(1+3) 。 */
#include<iostream>
#include<vector>
using namespace std;
vector<int>a = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool RunYear(int x){//判断闰年
    if( (x%4==0 && x%100!=0) ||x%400==0){
        return true;
    }else{
        return false;
    }
}

int get(int x){//计算每个位数的和
    int sum = 0;
    while(x>0){
        sum+=x%10;
        x /= 10;
        if(x<10){
            sum+=x;
            break;
        }
    }
    return sum;
}

int test(vector<int>a){
    int cnt=0;
    for(int i =1900;i<=9999;i++){
        bool year = RunYear(i);
        for(int j =1;j<=12;j++){
            int k=a[j];
            if(j==2 && year){
                k++;
            }
            for(int l=1;l<=k;l++){
                if(get(i)==get(j)+get(l)){
                    cnt++;
                }
            }                    
        }
    }
    return cnt;
}
int main(){
    int m = test(a);
    cout<<m; 
    return 0;
}