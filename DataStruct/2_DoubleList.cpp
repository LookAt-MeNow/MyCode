#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node* prior;//前节点
    struct Node* next;//后节点
    /* data */
}DNode,*DPList;
//初始化双链表
bool InitDList(DPList& L){
    if(L!=NULL){
    L = (DNode* )malloc(sizeof(DPList));//开辟头节点
    L->prior = NULL;
    L->next = NULL;
    }else{
        return false;
    }
    return true;
}
//建立双链表
DPList SetDList(DPList& L){
    InitDList(L);//初始一个空表 
    int t;
    DNode* r;//创建尾指针
    r = L;
    cout <<"请输入节点数:";
    cin>>t;
    cout <<"请输入数据"<<endl;
    for(int i=0;i<t;i++){
        int m;
        cin>>m;
        DNode* p = (DNode*)malloc(sizeof(DPList));
        p->data = m;//把数据给节点p
        r->next = p;//将r的next指向p
        p->prior =r;//将p的前指针指向r
        r = p;//尾指针指向下一个节点
    }
    r->next = NULL;
    return L;
}
//遍历链表
void printDList(DPList t){
    DNode* s;
    s = t->next;
    while (s != NULL)
    {
        cout <<s->data<<" ";
        s = s->next;
        /* code */
    }
}
//计算链表长度
int DListLen(DPList L){
    int num = 0;
    if(L==NULL){
        return num;
    }else{
        DNode* s;
        s = L;
        while (s->next!=NULL)
        {
            s = s->next;
            num++;
        } 
    }
    return num;
}
//按位插入
bool DListInsert(DPList& L,int i,int e){
    int m = DListLen(L);//计算链表长度
    if(i<0 || i>m){
        return false;//判断传入位置是否合适
    }
    DNode* p;//显示p当前指向的节点
    int j = 0;//计数
    p = L;//p从头节点开始，头节点是第0个数据
    while(p!=NULL && j<i-1){//这里是i-1，因为后插操作使用的是前节点的next指针操作的
        p = p->next;
        j++;
    }
    //-------------------------------------以上是按位查找操作
    if(p==NULL){
        return false;
    }
    DNode* s = (DNode*)malloc(sizeof(DPList));//开辟一个节点用于插入
    s->data = e;//把数据给s节点
    p->next->prior = s;//p下一个节点的前指针指向s
    s->next = p->next;//将p下一个节点给s下一个节点
    s->prior = p;//s的前指针指向p
    p->next = s; //p的下一个节点改为s
    return true;
    //-------------------------------------后插操作
}
//按位删除
bool DListDel(DPList& L,int i){
    int m = DListLen(L);//计算链表长度
    if(i<0 || i>m){
        return false;//判断传入位置是否合适
    }
    DNode* p;//显示p当前指向的节点
    int j = 0;//计数
    p = L;//p从头节点开始，头节点是第0个数据
    while(p!=NULL && j<i-1){//这里是i-1，因为后插操作使用的是前节点的next指针操作的
        p = p->next;
        j++;
    }
    //-------------------------------------以上是按位查找操作
    if(p==NULL){
        return false;
    }
    DNode* s = p->next;//找到p的下一个节点
    if(s == NULL){
        return false;//如果下一个节点是NULL返回false
    }
    p->next = s->next;//把s下一个节点给p
    if(s->next!=NULL){//判断s下一个节点是否是空
        s->next->prior = p;//将s下一个节点的前指针指向p
    }
    free(s);//删除s
    return true;
    //-------------------------------------后插操作
}
int main(){
    DPList L;
    L = SetDList(L);
    cout<<"----------------------------"<<endl;
    cout<<"插入前"<<endl;
    printDList(L);
    cout <<endl;
    cout<<"----------------------------"<<endl;
    cout <<"请分别输入插入的位置和数据:";
    int i;
    int e;
    cin>>i;
    cin>>e;
    DListInsert(L,i,e);
    cout<<"插入后"<<endl;
    printDList(L);
    cout <<endl;
    cout<<"----------------------------"<<endl;
    cout <<"请输入删除的位置:";
    cin>>i;
    DListDel(L,i);
    cout<<"删除后"<<endl;
    printDList(L);
    cout <<endl;
    cout<<"----------------------------"<<endl;
    return 0;
}