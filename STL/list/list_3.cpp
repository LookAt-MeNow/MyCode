/* - size(); //返回容器中元素的个数 
- empty(); //判断容器是否为空 
- resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。 //如果容器变短，则末尾超出容器长度的元素被删除。 
- resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。 //如果容器变短，则末尾超出容器长度的元素被删除。 */
#include <iostream>
#include <list>
using namespace std;
void printList(const list<int>& t){
    for(list<int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<*it <<" ";
    }
    cout << endl;
}
void if_empty(const list<int>& t){
    if(t.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout <<"这个容器不是空的,其中的元素个数为:"<<t.size()<<endl;
    }
}
void test(){
    list<int>a;
    list<int>b;
    for(int i = 0;i<10;i++){
        a.push_back(i);
    }
    if_empty(a);
    if_empty(b);
    cout <<"重新指定容器的长度为num,重载版本"<<endl;
    b.resize(10,1);
    printList(b);
}
int main()
{
    test();
    return 0;
}