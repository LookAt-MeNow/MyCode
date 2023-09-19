#include <iostream>
using namespace std;
typedef struct Node
{
    int date;
    struct Node *next;
} Node, *PNode; // Node 相当于struct Node , *PNode 相当于struct Node*
// 用PNode主要为了强调这是一个单链表，用Node*主要强调这是一个节点

// 尾插法创建链表
PNode ListNodeInit()
{
    Node *L;
    Node *r;                          // 定义尾指针，每次都指向最后一个节点
    L = (Node *)malloc(sizeof(Node)); // 申请头节点空间
    L->next = NULL;
    r = L; // 尾指针指向头节点
    int a;
    cout << "请输入节点数" << endl;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int t;
        cin >> t;
        Node *p; // 创建节点
        p = (Node *)malloc(sizeof(Node));
        p->date = t;
        r->next = p; // 把新节点插入到r节点之后
        r = p;       // 尾指针指向下一个节点
    }
    r->next = NULL;
    return L;
}

// 按位查找,返回第i个数据
Node *GetData_1(PNode L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    Node *p;   // p指向当前指向的节点
    int j = 0; // 计数,记录当前p指向的是第几个节点
    p = L;     // p开始指向头节点
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//按值查找，返回第i个数据
Node *GetData_2(PNode L, int e)
{
    Node *p;   // p指向当前指向的节点
    p = L->next;     // 从第一个数据开始查找,头节点是没有数据域的
    while(p != NULL && p->date != e){
        p = p->next;
    }
    return p;
}
//返回表长
int GetListLen(PNode L){
    Node* s = L;
    int num=0;
    while(s->next!=NULL){
        s = s->next;
        num++;
    }
    return num;
}
//指定节点的后插操作
bool Set_Behind(Node* p,int t){
    if(p==NULL){
        return false;
    }
    Node* s = (Node*)malloc(sizeof(PNode));//开辟一块空间
    s->date = t;
    s->next = p->next;
    p->next =s;
    return true;
}
//按位插入数据
bool Set_Wei(PNode L,int i){
    Node *p = GetData_1(L, i-1);//这里要传入i-1,因为插入数据的时候是前一个数据的next指向的
    int t;
    cout <<"插入的数据是:";
    cin>>t; 
    if(Set_Behind(p,t)){
        return true;//如果插入成功就返回真
    }else{
        return false;
    }
}
//指定节点的删除
bool ListDel_1(Node* p){
    if(p==NULL){
        return false;
    }
    Node* s = p->next;//让节点s指向p的下一个节点
    p->date = p->next->date;//让p下一个节点的数据将p覆盖掉
    p->next = s->next;//把p的指针域换成下一个节点的指针域
    free(s);//释放s节点
    return true;
}
//按位删除数据
bool ListDel_2(PNode L,int i){
    Node *p = GetData_1(L, i);//这里要传入i
    if(ListDel_1(p)){
        return true;//如果插入成功就返回真
    }else{
        return false;
    }
}

// 遍历链表
void ListPrint(PNode L)
{
    Node *s;
    s = L->next; // 让s指向第一个元素
    while (s != NULL)
    {
        cout << s->date << " ";
        s = s->next;
    }
}

int main()
{
    PNode L = ListNodeInit();
    cout << "------------------------------" << endl;
    cout<<"遍历这个表"<<endl;
    ListPrint(L);
    cout << endl;
    cout << "------------------------------" << endl;
    int len = GetListLen(L);
    cout <<"这个表长为:"<<len<<endl;
    cout << "------------------------------" << endl;
    int i;
    cout << "请输入要查找的位数:";
    cin >> i;
    Node *t1 = GetData_1(L, i);
    cout << "第" << i << "个节点的数据是" << t1->date << endl;
    cout << "------------------------------" << endl;
    int e;
    cout << "请输入要查找的数:";
    cin >> e;
    Node *t2 = GetData_2(L, e);
    if(t2!=NULL){
        cout <<"找到了数据为"<<e<<"的元素"<<endl;
    }else{
        cout<<"没有找到值为"<<e<<"的元素"<<endl;
    }
    cout << "------------------------------" << endl;
    cout << "请输入要插入的位数:";
    cin >> i;
    bool ret = Set_Wei(L, i);
    if(ret){
        cout << "插入成功"<< endl;
    }else{
        cout << "插入失败"<< endl;
    }
    cout<<"插入后遍历这个表"<<endl;
    ListPrint(L);
    cout <<endl;
    cout << "------------------------------" << endl;
    cout << "请输入要删除的位数:";
    cin >> i;
    bool ret2 = ListDel_2(L,i);
    if(ret){
        cout << "删除成功"<< endl;
    }else{
        cout << "删除失败"<< endl;
    }
    cout<<"删除后遍历这个表"<<endl;
    ListPrint(L);
    cout <<endl;
    cout << "------------------------------" << endl;

    return 0;
}