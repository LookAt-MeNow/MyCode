/* empty(); //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除
 */
#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>& t){
    for(vector<int>::iterator it=t.begin();it!=t.end();it++){
        cout<<(*it)<<" ";
    }
    cout << endl;
}
void test(){
    vector<int>a;
    for(int i = 0;i<10;i++){
        a.push_back(i);
    }
    printVector(a);
    //如果是空的
    if(a.empty()){
        cout<<"a is empty"<<endl;
    }else{
        cout<<"a is not empty "<<endl;
        cout<<"a capacity is "<<a.capacity()<<endl;
        cout<<"a size is "<<a.size()<<endl;
    }
    a.resize(15,1);//重设size大小，多余的空间用1填充
    printVector(a);
    a.resize(5);//设置的比原来小，把后面多的删除了
    printVector(a);
}
int main(){
    test();
    return 0;
}