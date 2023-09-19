/* - push_back(ele); //尾部插入元素ele 
- pop_back(); //删除最后一个元素 
- insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele 
- insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele 
- erase(const_iterator pos); //删除迭代器指向的元素 
- erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素 
- clear();//删除容器中所有元素 */
#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>& t){
    for(vector<int>::iterator it=t.begin();it!=t.end();it++){
        cout <<*it<<" ";
    }
    cout << endl;
}
void test(){
    vector<int>a;
    //尾部插入元素ele 
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    //遍历
    printVector(a);
    //删除最后一个元素 
    a.pop_back();
    printVector(a);
    //迭代器指向位置pos插入元素ele
    a.insert(a.begin()+2,3); //在第二个位置插入一个3
    printVector(a);
    //迭代器指向位置pos插入count个元素ele 
    a.insert(a.begin(),3,100);//在开始位置插入三个100
    printVector(a);
    //删除迭代器指向的元素 
    a.erase(a.begin());
    printVector(a);
    //删除迭代器从start到end之间的元素 
    a.erase(a.begin(),a.begin()+2);
    printVector(a);
    //删除容器中所有元素
    a.clear();
    if(a.empty()){
        cout<<"a is empty"<<endl;
    }else{
        cout<<"a is not empty "<<endl;
        cout<<"a capacity is "<<a.capacity()<<endl;
        cout<<"a size is "<<a.size()<<endl;
    }
}
int main(){
    test();
    return 0;
}

/*     //返回索引idx所指的数据
    for(int i = 0; i<10;i++){
        cout <<v.at(i)<< " ";
    } */
/*     cout << endl;
    //返回索引idx所指的数据
    for(int i = 0; i<10;i++){
        cout <<v[i]<< " ";
    } */
/*     cout << endl;
    //返回容器中第一个数据元素
    cout <<"df "<<v.front()<<endl;
    //返回容器中最后一个数据元素
    cout <<"fdg "<<v.back()<<endl; */