//朴素匹配算法
#include <iostream>
using namespace std;

int test(){
    char a[10],b[10];
    cin>>a;
    cin>>b;
    int i =0;int j=0;
    while(a[i]!='\0' && b[j]!='\0'){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(b[j]=='\0'){//如果子串指向了\0，返回匹配的位置
        return i-j;
    }else{//如果没有找到，指向的是主串的\0运行else
        return -1;
    }
}
int main(){
    int m=test();
    if(m==-1){
        cout <<"匹配失败";
    }else{
        cout <<"匹配的位置是:"<<m;
    }
    return 0;
}