#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
vector<int> ten_to_two(int x);
int two_to_ten(vector<int>x);
vector<char> ten_to_th(int x);
int th_to_ten(vector<char>x);
bool check(int x){
    while(x){
        if(x%16 >=10 && x%16<=15 ){
            x/=16;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
     int k  = 0;
    for(int i=2022; ;i++){
        if(check(i)){
            cout<<i;
            break;
        }
    }
    test();
    return 0;
}

//扩展进制转化

void test(){//测试进制转化
    two_to_ten(ten_to_two(32523));
    cout <<"------------------------"<<endl;
    th_to_ten(ten_to_th(23453));
}
//十进制转化二进制
vector<int> ten_to_two(int x){
    stack<int>m;
    vector<int>n;
    while(x){
        int temp = 0;
        if(x!=1){
            temp = x%2;
            m.push(temp);
            x /= 2;
        }else{
            m.push(1);
            break;
        }
    }
    while(!m.empty()){
        n.push_back(m.top());
        m.pop();
    }
    for(int i = 0;i<n.size();i++){
        cout<<n[i];
    }
    cout<<endl;
    return n;
}

//二进制转化十进制
int two_to_ten(vector<int>x){
    int num=0;
    int t = x.size();
    for(int i=0;i<t;i++){
        num = num + pow(2,(t-(i+1)))*x[i];
    }
    cout<<num<<endl;
    return num;
}


//十进制转化十六进制

vector<char> ten_to_th(int x){
    vector<char>m;
    while(x>0){
        int t = x%16;  
        if(t>=1 && t<=9){
            m.push_back(t+48);
            x /= 16;
        } 
        if(t==10){
            m.push_back('A');
            x /= 16;
        }else if(t==11){
            m.push_back('B');
            x /= 16;
        }else if(t==12){
            m.push_back('C');
            x /= 16;
        }else if(t==13){
            m.push_back('D');
            x /= 16;
        }else if(t==14){
            m.push_back('E');
            x /= 16;
        }else if(t==15){
            m.push_back('F');
            x /= 16;
        }
    }
    for(int i = m.size()-1;i>=0;i--){
        cout<<m[i];
    }
    cout<<endl;
    return m;
}

//十六进制转化十进制

int th_to_ten(vector<char>x){
    int num=0;
    int t = x.size();
    for(int i=t-1;i>=0;i--){
        int temp = x[i];
        int sum = 0;
        if(x[i]>='1' && x[i]<='9'){
           sum = temp - 48;
        }
        if(x[i]=='A'){
            sum = 10;
        }else if(x[i]=='B'){
            sum = 11;
        }else if(x[i]=='c'){
            sum = 12;
        }else if(x[i]=='D'){
            sum = 13;
        }else if(x[i]=='E'){
            sum = 14;
        }else if(x[i]=='F'){
            sum = 15;
        }
        num = num + pow(16,i)*sum;
    }
    cout<<num<<endl;
    return num;
}

