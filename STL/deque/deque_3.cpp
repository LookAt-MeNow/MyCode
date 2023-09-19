/* - deque.empty(); //判断容器是否为空
- deque.size(); //返回容器中元素的个数 
- deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。 //如果容器变短，则末尾超出容器长度的元素被删除 
- deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。 //如果容器变短，则末尾超出容器长度的元素被删除 */
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int>& t){
    for(deque<int>::const_iterator it = t.begin(); it!=t.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
void test(){
    //判断容器是否为空
    deque<int>a;
    deque<int>b;
    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }
    if(a.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout <<"这个容器不是空的且";
        //返回容器中元素的个数 
        cout << "这个容器的size为: "<<a.size()<<endl;
    }
    if(b.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout <<"这个容器不是空的"<<endl;
        //返回容器中元素的个数 
        cout << "这个容器的size为: "<<a.size()<<endl;
    }
    //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。 //如果容器变短，则末尾超出容器长度的元素被删除 
    a.resize(15);
    printDeque(a);
    a.resize(5);
    printDeque(a);
}
int main(){
    test();
    return 0;
}
