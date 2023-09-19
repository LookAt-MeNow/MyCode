#include <iostream>
using namespace std;
//定义链式节点
typedef struct ListNode
{
    int data;
    ListNode* next;
}ListNode;
//定义链式队列类
class ListQueue{
private:
    ListNode* front;//队头指针
    ListNode* rear;//队尾指针
    int size;//队列长度
public:
    ListQueue();//构造函数初始化队列
    ~ListQueue();//析构函数销毁队列
    void In_Queue(int x);//入队操作
    bool If_empty();//判断队列是否为空
    bool Out_Queue(int& x);//出队操作
};

ListQueue::ListQueue(){
    front = rear =(ListNode*)malloc(sizeof(ListNode));//队头和队尾指针都指向头节点
    front->next=NULL;
    size=0;
}

void ListQueue::In_Queue(int x){
    ListNode* s = (ListNode*)malloc(sizeof(ListNode));
    s->data = x;
    s->next =NULL;
    rear->next =s;//让rear的next指针域指向s
    rear = s;//将s改为尾指针
    size++;
}

bool ListQueue::If_empty(){
    if(this->front==this->rear){
        cout <<"这个队列是空的"<<endl;
        return true;
    }else{
        return false;
    }
}

bool ListQueue::Out_Queue(int& x){
    if(this->If_empty()){
        cout <<"出队失败"<<endl;
        return false;
    }
    ListNode* p = front->next;//用p指向这次要出队的节点
    x  = p->data;//用x接收要出队节点的数据
    front->next = p->next;//修改头节点指向
    if(rear == p){//如果要删除的是最后一个节点
        front = rear;
    }
    free(p);//删除节点
    size--;
    return true;
}

ListQueue::~ListQueue(){
    if(front!=rear){
        ListNode* p = front->next;//用p指向这次要出队的节点
        front->next = p->next;//修改头节点指向
        if(rear == p){//如果要删除的是最后一个节点
            front = rear;
        }
        free(p);
    }
}
int main(){
    ListQueue L;
    for(int i =0;i<10;i++){
        L.In_Queue(i);
    }
    int m;
    for(int i =0;i<5;i++){
        L.Out_Queue(m);
        cout <<m<<" ";
    }
}