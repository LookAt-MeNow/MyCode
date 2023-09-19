/* int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s */

#include <iostream>
#include <string>
using namespace std;
//查找
void test01(){
    //使用find
    string str = "abcdefg_de";
    if(str.find("de")==-1){
        cout <<"find erro"<<endl;
    }else{
        cout <<"find success,this point is "<<str.find("de")<<endl;
    }
    if(str.find("dg")==-1){
        cout <<"find erro"<<endl;
    }else{
        cout <<"find success,this point is "<<str.find("de")<<endl;
    }
    //使用rfind
    if(str.rfind("de")==-1){
        cout <<"rfind erro"<<endl;
    }else{
        cout <<"rfind success,this point is "<<str.rfind("de")<<endl;
    }
    if(str.rfind("dg")==-1){
        cout <<"rfind erro"<<endl;
    }else{
        cout <<"rfind success,this point is "<<str.rfind("de")<<endl;
    }
    //find是从左向右找，rfind是从右往左找
}
//替换
void test02(){
    string str = "abcdefg";
    str.replace(1,3,"1111");//把一号位置后面三个位置替换为1111
    cout <<"str="<<str<<endl;
}
int main(){
    test01();
    test02();
    return 0;
}