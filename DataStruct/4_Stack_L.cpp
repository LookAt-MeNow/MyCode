#include <iostream>
using namespace std;
//定义链式节点
typedef struct ListNode
{
    int data;
    ListNode* next;
}ListNode;
//定义链式队列类
class ListStack{
private:
    ListNode* top;
    int size;//队列长度
public:
    ListStack();//构造函数初始化队列
    void push(int x);//入队操作
    bool If_empty();//判断队列是否为空
    bool pop();//出队操作
    int GetTop();//获取栈顶元素
    void print(ListStack L);//通过出队和获取栈顶元素实现遍历
};
ListStack::ListStack(){
    top = (ListNode*)malloc(sizeof(ListNode));
    //为top开辟空间，不开辟会报错
    top->next = NULL;//不带头节点
    size = 0;
}

void ListStack::push(int x){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//开辟一个节点
    p->data =x;
    p->next = top->next;
    top->next = p;
    size++;
}

bool ListStack::If_empty(){
    return top->next==NULL;
}

bool ListStack::pop(){
    if(ListStack::If_empty()){
        return false;//队空返回false
    }
    ListNode* s = top->next;
    top->next = s->next;
    free(s);
    size--;
    return true;
}

int ListStack::GetTop(){
    return top->next->data;
}

void ListStack::print(ListStack L){
    int t = L.size;
    int item;
    for(int i=0;i<t;i++){
        item = L.GetTop();
        cout <<item<<" ";
        L.pop();
    }
}
int main(){
    ListStack L;
    L.push(1);
    L.push(2);
    L.push(3);
    L.push(4);
    L.push(5);
    L.print(L);
    return 0;
}

