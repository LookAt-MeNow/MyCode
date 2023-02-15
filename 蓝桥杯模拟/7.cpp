
//小蓝有 n 个单词，但是单词中有一些是重复的，请帮小蓝去除重复的单词。
#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    int n=1;
    cin>>t;
    string a[t];     
    string b[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<t;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            b[n]=a[i];
            n++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<endl;
    }
    return 0;
 }

