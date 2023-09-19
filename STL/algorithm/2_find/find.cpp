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
    //对于自定义的类型,使用find是重载 == 符号，不然find不知道怎么比较
    bool operator==(const Person& p1){
        if(this->name == p1.name &&
        this->age == p1.age &&
        this->hight == p1.hight){
            return true;
        }else{
            return false;
        }
    }

    string name;
    int age;
    int hight;
};

void test(){
    Person a1("张三",18,170);
    Person a2("李四",22,165);
    Person a3("王二",22,180);
    Person a4("刘五",22,190);
    Person a5("陈七",17,176);
    Person aa("张三",18,170);
    vector<Person>v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);
    v.push_back(a5);
    vector<Person>::iterator it = find(v.begin(),v.end(),aa);
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