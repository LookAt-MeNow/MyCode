//顺序存储结构
#include<iostream>
using namespace std;
#define Max 100
#define ElemType int
typedef ElemType BiTree[Max];//定义二叉树

class Mytree{
private:
    BiTree tree;
    int size = 0;
public:
    Mytree(){}
    void InitBiTree();
    void printBiTree();
    ElemType FindParent(ElemType e);
    ElemType LeftChild(ElemType e);
    ElemType RightChild(ElemType e);
    ElemType Gettree(ElemType e);
    bool EmptyTree();
};

void Mytree::InitBiTree(){
    ElemType node;
    cout<<"请按层次从左向右输入节点,空节点用0表示,按1010停止输入"<<endl;
    int i = 1;
    while(cin>>node){
        if(node == 1010){
            break;
        }
        tree[i] = node;
        i++;
        size++;
    }

}
void Mytree::printBiTree(){
    //层次遍历
    for(int i =1;i<=size;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}
ElemType Mytree::FindParent(ElemType e){
    if(EmptyTree()) cout<<"这是个空树"<<endl;
    if(e == 1) cout<<"根节点没有父节点"<<endl;
    if(tree[e] == 0) { cout<<"不存在这个节点"; return -1;}
    for(int i =2;i<=size;i++){
        if(i == e){
            return tree[i/2];
        }
    }
    return -1;
}

ElemType Mytree::LeftChild(ElemType e){
    if(EmptyTree()) cout<<"这是个空树"<<endl;
    if(tree[e] == 0) { cout<<"不存在这个节点"; return -1;}
    for(int i =2;i<=size;i++){
        if(i == e){
            if(i*2<size && tree[i*2]!=0){
                return tree[i*2];
            }else{
                cout<<"当前节点没有左孩子"<<endl;
            }
        }
    }
    return -1;
}   

ElemType Mytree::RightChild(ElemType e){
    if(EmptyTree()) cout<<"这是个空树"<<endl;
    if(tree[e] == 0) { cout<<"不存在这个节点"; return -1;}
    for(int i =2;i<=size;i++){
        if(i == e){
            if(i*2+1<size && tree[i*2+1]!=0){
                return tree[i*2+1];
            }else{
                cout<<"当前节点没有右孩子"<<endl;
            }
        }
    }
    return -1;
}
bool Mytree::EmptyTree(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

ElemType Mytree::Gettree(ElemType e){
    return tree[e];
}
int main(){
    Mytree a;
    int tmp;
    a.InitBiTree();
    a.printBiTree();
    cout<<"-----------------"<<endl;
    cout<<"请输入想要查询的节点"<<endl;
    cin>>tmp;
    cout<<"这个节点的的值是："<<a.Gettree(tmp)<<endl;
    cout<<"这个节点的父节点："<<a.FindParent(tmp)<<endl;
    cout<<"这个节点的左孩子："<<a.LeftChild(tmp)<<endl;
    cout<<"这个节点的右孩子："<<a.RightChild(tmp)<<endl;
    return 0;
}
