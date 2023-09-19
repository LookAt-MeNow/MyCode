/* find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end(); 
count(key); //统计key的元素个数  返回值是0 或者 1 */
#include <iostream> 
#include <set>
using namespace std;
void test(){
    set<double>a;
    a.insert(1.0);
    a.insert(4.0);
    a.insert(2.0);
    a.insert(3.0);
    a.insert(5.0);
    set<double>::iterator it = a.find(3.0);
    if(it!=a.end()){
        cout <<"找到了这个元素"<<endl;
    }else{
        cout<<"没找到这个元素"<<endl;
    }
    int m = a.count(1.0);
    int n = a.count(223);
    cout <<m<<endl;
    cout <<n<<endl;
}
int main(){
    test();
    return 0;
}