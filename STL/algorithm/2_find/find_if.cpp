//所有找年龄大于20的人
/* find(iterator beg, iterator end, value);  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//查找自定义数据类型
class Person{
public:
    Person(string name,int age,int hight){
        this->name = name;
        this->age = age;
        this->hight = hight;
    }
    //使用一元谓词
    bool operator()(const Person& p1){
        return p1.age > this->age;
    }
    string name;
    int age;
    int hight;
};
class My{
public:
    //使用一元谓词
    bool operator()(const Person& p1){
        return p1.age > 20;
    }
};


void test(){
    Person a1("陈七",17,176);
    Person a2("李四",11,165);
    Person a3("张三",18,170);
    Person a4("王二",11,180);
    Person a5("刘五",19,190);
    vector<Person>v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);
    v.push_back(a5);
    vector<Person>::iterator it = find_if(v.begin(),v.end(),My());
    if(it == v.end()){
        cout <<"没有找"<<endl;
    }else{
        cout <<"找到了"<<it->name<<" "<<it->age<<" "<<it->hight<<endl;
    }
}
int main(){
    test();
    return 0;
}
