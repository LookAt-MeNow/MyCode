#include <iostream>
#include <set>
#include <string>
using namespace std;
class Person{
public:
    string name;
    int age;
    int hight;
    Person(string name,int age,int hight){
        this->name=name;
        this->age=age;
        this->hight=hight;
    }
};
class MyCompare
{
public:
    bool operator()(const Person& p1,const Person& p2) const{
        if(p1.age == p2.age){
            return p1.hight < p2.hight;
        }else{
            return p1.age < p2.age;
        }
    }  
};
void test(){
    Person a1("张三",18,170);
    Person a2("李四",22,165);
    Person a3("王二",22,180);
    Person a4("刘五",22,190);
    Person a5("陈七",17,176);
    set<Person,MyCompare>a;
    a.insert(a1);
    a.insert(a2);
    a.insert(a3);
    a.insert(a4);
    a.insert(a5);
    for (set<Person, MyCompare>::iterator it = a.begin(); it != a.end(); it++){
        cout << "姓名： " << it->name << " 年龄： " << it->age << "身高："<<it->hight<<endl;
    }

}
int main(){
    test();
    return 0;
}
