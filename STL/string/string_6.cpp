/* - int compare(const string &s) const; //与字符串s比较 
- int compare(const char *s) const; //与字符串s比较
- char& operator[] (int n); //通过[]方式取字符 
- char& at(int n); //通过at方法获取字符 */

#include <iostream>
#include <string>
using namespace std;
//字符串比较
void test01(){
    string str1 ="hello";
    string str2 ="hello";
    if(str1.compare(str2)==0){
        cout <<"str1 == str2"<<endl;
    }else{
        cout <<"str1!=str2"<<endl;
    }

}
//字符串存取
void test02(){
    //通过[]方式取字符 
    string str ="hello";
    for(int i =0; i<str.size();i++){
         cout <<str[i]<<" ";
    }
    cout << endl;
    //通过at方法获取字符
    for(int i =0; i<str.size();i++){
         cout <<str.at(i)<<" ";
    }
    cout << endl;
    //修改字符串中的字符
    str[0]='x';
    str.at(1)='m';
    cout <<"str="<<str<<endl;
}
int main(){
    test01();
    cout <<"-------------"<<endl;
    test02();
    return 0;
}