#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gns(int a,int b){//求最大公约数
    if(a==b){
        return a;
    }
    if(a>b){
        a=a-b;
    }else{
        b=b-a;
    }
    return gns(a,b);
}
int main(){
    int n;//存节点数
    int t;//输入的数字
    vector<int>b;
    int d;//
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        b.push_back(t);
    }
    sort(b.begin(),b.end());
    int sum = b.front();
    d = b.at(1)-b.at(0);
    for(int i =2;i<n;i++){
        d = gns(d,b.at(i)-b.at(i-1));
    }
    if(d==0){
        cout <<n;
    }else{
        cout <<((b.front()+b.back())/d)-1;
    }
    return 0;
}
