/* - string& operator+=(const char* str); //重载+=操作符 1
- string& operator+=(const char c); //重载+=操作符 2
- string& operator+=(const string& str); //重载+=操作符 3
- string& append(const char *s); //把字符串s连接到当前字符串结尾 
- string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾 
- string& append(const string &s); //同operator+=(const string& str) 
- string& append(const string &s, int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾 */
//字符串拼接
#include <iostream>
#include <string>
using namespace std;

void test(){
    //重载+=操作符 1
    string str1;
    str1 = "I ";
    str1+="Love game";
    cout <<"str1="<<str1<<endl;
    //重载+=操作符 2
    str1+='.';
    cout <<"str1="<<str1<<endl;
    //重载+=操作符 3
    string str2;
    str2 = " No,you don't";
    str1+=str2;
    cout <<"str1="<<str1<<endl;
    //把字符串s连接到当前字符串结尾 
    str1.append(" ....");
    cout <<"str1="<<str1<<endl;
    //把字符串s的前n个字符连接到当前字符串结尾 
    str1.append(" bey sdfsdfasdhf",4);
    cout <<"str1="<<str1<<endl;
    //同operator+=(const string& str) 
    string str3;
    str3 = " aaaa";
    str1.append(str3);
    cout <<"str1="<<str1<<endl;
    //字符串s中从pos开始的n个字符连接到字符串结尾 */
    str1.append(str3,0,3);
    cout <<"str1="<<str1<<endl;
}
int main(){
    test();
    return 0;
}