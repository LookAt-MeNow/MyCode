//给定一天是一周中的哪天，请问 n 天后是一周中的哪天？
#include<iostream>
using namespace std;
int main(){
    int today;
    int before;
    cin>>today;
    cin>>before;
    while(before!=0){
        if(today == 7){
            today = 0;
        }
        today++;
        before--;
    }

    cout<<today;
    return 0;
}