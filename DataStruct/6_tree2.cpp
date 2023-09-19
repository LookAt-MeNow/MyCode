#include<iostream>

using namespace std;

#define ElemType int

typedef struct BiTreeNode//定义结构体
{
    ElemType  data; //数据域
    BiTreeNode *lChild;//左孩子
    BiTreeNode *rChlid;//右孩子
} BiTreeNode, *BiTree;
//先序创建二叉树
void CreateBiTree(BiTree &T){
    ElemType ch;
    cin >> ch;
    if (ch == -1)
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data = ch;
        CreateBiTree(T->lChild);//cout<<"输入"<<ch<<"的左孩子：" ;
        CreateBiTree(T->rChlid);//cout<<"输入"<<ch<<"的右孩子：" ;
    }
}

//中序遍历
void GetMid(BiTree T){
    if(T){
        GetMid(T->lChild);
        cout<<T->data<<" ";
        GetMid(T->rChlid);
    }
}
//先序遍历
void GetFrist(BiTree T){
    if(T){
        cout<<T->data<<" ";
        GetMid(T->lChild);
        GetMid(T->rChlid);
    }
}
//后序遍历
void GetLast(BiTree T){
    if(T){
        GetMid(T->lChild);
        GetMid(T->rChlid);
        cout<<T->data<<" ";
    }
}
int main(void)
{
    BiTree T;
    cout<<"请输入先序遍历顺序下各个结点的值,-1表示没有结点:"<<endl;
    CreateBiTree(T);
    GetMid(T);
    cout<<endl;
    cout<<"---------------"<<endl;
    GetFrist(T);
    cout<<endl;
    cout<<"---------------"<<endl;
    GetLast(T);
    return 0;
}

