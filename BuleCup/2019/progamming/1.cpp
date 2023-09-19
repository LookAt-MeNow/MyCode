#include <iostream>
using namespace std;
bool test(int x){
    while (x)
    {
        int t=x%10;
        if(t==2 || t==0 || t==1 || t==9){
            return true;
        }
        x/=10;
    }
    return false;
}

int main(){
    int m;
    cin>>m;
    int sum=0;
    for(int i =1;i<=m;i++){
        if(test(i)){
            sum+=i;
        }
    }
    test(10);
    test(20);
    cout <<sum;
    return 0;
}

