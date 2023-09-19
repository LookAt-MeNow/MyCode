#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Person{
public:
    Person(string name,int age,int hight){
        this->name = name;
        this->age = age;
        this->hight = hight;
    }
    //对于自定义的类型,使用find是重载 == 符号，不然find不知道怎么比较
    bool operator==(const Person& p1){
        if(this->age == p1.age){
            return true;
        }else{
            return false;
        }
    }

    string name;
    int age;
    int hight;
};
//找到年龄为22的人出现次数
void test(){
    Person a1("张三",18,170);
    Person a2("李四",22,165);
    Person a3("王二",22,180);
    Person a4("刘五",22,190);
    Person a5("陈七",17,176);
    Person aa("张三",22,170);
    vector<Person>v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);
    v.push_back(a5);
    int num= count(v.begin(),v.end(),aa);
    if(num == 0){
        cout <<"没有找年龄为22的人"<<endl;
    }else{
        cout <<"找到了年龄为22的有"<<num<<"个人"<<endl;
    }
}
int main(){
    test();
    return 0;
}