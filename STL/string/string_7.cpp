/* - string& insert(int pos, const char* s); //插入字符串 
- string& insert(int pos, const string& str); //插入字符串 
- string& insert(int pos, int n, char c); //在指定位置插入n个字符c 
- string& erase(int pos, int n = npos); //删除从Pos开始的n个字符 */

#include <iostream>
#include <string>
using namespace std;

//插入字符串
void test01(){
    string str1 = "hello ";
    string str2 = "world";
    str1.insert(6,str2);
    cout <<"str1="<<str1<<endl;
    //在指定位置插入n个字符c 
    str1.insert(11,1,' ');
    str1.insert(12,3,'m');
    cout <<"str1="<<str1<<endl;
}
//删除字符串
void test02(){
    string str = "asdjfhldskjhf";
    str.erase(3,1);
    cout <<"str="<<str<<endl;

}
int main(){
    test01();
    test02();
    return 0;
}