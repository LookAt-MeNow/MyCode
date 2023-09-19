//回文判断
#include<iostream>
#include<string>

using namespace std;

void test(){
    string str;
    string str1;
    string str2;
    cin>>str;
    int l=0;
    int r = str.size()-1;
    while (l<r){
        str1.insert(l,1,str[l]);
        //cout <<"str1 "<<str1[l]<<" "<<endl;
        str2.insert(l,1,str[r]);
        //cout <<"str2 "<<str2[l]<<" "<<endl;
        ++l;
        --r;
    }
    if(str1.compare(str2) == 0){
        cout<<"Y";
    }else{
        cout<<"N";
    }
}
int main(){
    test();
    return 0;
}