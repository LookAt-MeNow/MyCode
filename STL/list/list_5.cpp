/* front(); //返回第一个元素。
back(); //返回最后一个元素。 */
#include <iostream>
#include <list>
using namespace std;
void test(){
    list<int>a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout<<"链表a第一个元素是:"<<a.front()<<endl;
    cout<<"链表a最后一个元素是:"<<a.back()<<endl;
    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误 不支持[]方式访问数据
    //list容器的迭代器是双向迭代器，不支持随机访问
    //it = it + 1;//错误，不可以跳跃访问，即使是+1
}   
int main()
{
    test();
    return 0;
}