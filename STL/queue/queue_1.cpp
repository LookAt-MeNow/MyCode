#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Person{
public:
    friend void test();
    Person(int age,string name){
        this->age=age;
        this->name=name;
    }
private:
    int age;
    string name;
};

void test(){
    //构造函数
    queue<Person>a;
    //数据存取
    Person p1(19,"张三");
    Person p2(20,"李四");
    Person p3(25,"王二");
    Person p4(18,"刘五");
    a.push(p1);
    a.push(p2);
    a.push(p3);
    a.push(p4);
    cout <<"这个队列大小是:"<<a.size()<<endl;
    while(!a.empty()){
        cout<<"排头的名字和年龄分别是"<<a.front().name<<" "<<a.front().age<<endl;
        cout<<"排尾的名字和年龄分别是"<<a.back().name<<" "<<a.back().age<<endl;
        //出队
        a.pop();
    }
    cout <<"这个队列大小是:"<<a.size()<<endl;
}
int main(){
    test();
    return 0;
}