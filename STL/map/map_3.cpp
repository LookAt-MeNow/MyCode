/* - insert(elem); //在容器中插入元素。 
- clear(); //清除所有元素 
- erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
- erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。 
- erase(key); //删除容器中值为key的元素。 */
#include <iostream>
#include <map>
using namespace std;
void printMap(const map<int,int>& t ){
    for(map<int,int>::const_iterator it = t.begin();it!=t.end();it++){
        cout <<it->first<<" "<<it->second<<"|";
    }       
    cout << endl;
}
void if_empty(const map<int,int>& t ){
    if(t.empty()){
        cout <<"这个容器是空的"<<endl;
    }else{
        cout <<"这个容器不是空的,大小为"<<t.size()<<endl;
    }
}
void test(){
    map<int,int>m;
    //插入方式一
    m.insert(pair<int,int>(1,10));
    //插入方式二
    m.insert(make_pair(2,20));
    //插入方式三
    m.insert(map<int,int>::value_type(3,30));
    //插入方式四
    m[4]=40;
    printMap(m);
    map<int,int>::iterator it = m.begin();
    m.erase(++it);
    cout<<"删除元素"<<endl;
    printMap(m);
    cout<<"删除key为3的元素"<<endl;
    m.erase(3);
    printMap(m);
    cout<<"清空数据"<<endl;
    m.clear();
    if_empty(m);
}
int main(){
    test();
    return 0;
}