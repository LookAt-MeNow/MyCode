#include <iostream>
#include <vector>
#include <string>
using namespace std;

class My{
public:
    My(string a,int b){
        this->name=a;
        this->age=b;
    }

    string name;
    int age;
};

void test01(){
    //存放自定义数据类型
    vector<My> t;
    My p1("aaa",10);
    My p2("bbb",20);
    My p3("ccc",30);
    My p4("ddd",40);
    My p5("eee",50);
    //向容器中添加数据
    t.push_back(p1);
    t.push_back(p2);
    t.push_back(p3);
    t.push_back(p4);
    t.push_back(p5);
    //遍历数据
    for(vector<My>::iterator it=t.begin();it!=t.end();it++){
        cout<<"name "<<(*it).name<<"age "<<(*it).age<<endl;
    }
}

int main(){
    test01();
    return 0;
}