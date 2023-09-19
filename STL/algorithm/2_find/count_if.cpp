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
    string name;
    int age;
    int hight;
};
class My{
public:
    //使用一元谓词
    bool operator()(const Person& p1){
        return p1.age > 22;
    }
};

//找到年龄为22的人出现次数
void test(){
    Person a1("张三",18,170);
    Person a2("李四",22,165);
    Person a3("王二",23,180);
    Person a4("刘五",25,190);
    Person a5("陈七",17,176);
    vector<Person>v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);
    v.push_back(a5);
    int num= count_if(v.begin(),v.end(),My());//第三个参数是谓词
    if(num == 0){
        cout <<"没有找年龄大于22的人"<<endl;
    }else{
        cout <<"找到了年龄大于22的有"<<num<<"个人"<<endl;
    }
}
int main(){
    test();
    return 0;
}