#include <iostream>
using namespace std;
//定义链式节点
typedef double T;
typedef struct ListNode
{
    T data;
    ListNode* next;
}ListNode;
//定义链式队列类
class ListStack{
private:
    ListNode* top;
    int size;//队列长度
public:
    ListStack();//构造函数初始化队列
    void push(T x);//入队操作
    bool If_empty();//判断队列是否为空
    T pop();//出栈操作并返回出队的值
    T GetTop();//获取栈顶元素
    void print(ListStack L);//通过出队和获取栈顶元素实现遍历
    void compute(ListStack L1,ListStack L2);//实现计算并将值压入栈
    double Cal(char str[100]);//计算中缀表达式
};
ListStack::ListStack(){
    top = (ListNode*)malloc(sizeof(ListNode));
    //为top开辟空间，不开辟会报错
    top->next = NULL;//不带头节点
    size = 0;
}

void ListStack::push(T x){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//开辟一个节点
    p->data =x;
    p->next = top->next;
    top->next = p;
    size++;
}

bool ListStack::If_empty(){
    return top->next==NULL;
}

T ListStack::pop(){
    if(ListStack::If_empty()){
        return 0;//队空返回false
    }
    T m = this->GetTop();
    ListNode* s = top->next;
    top->next = s->next;
    free(s);
    size--;
    return m;
}

T ListStack::GetTop(){
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
void ListStack::compute(ListStack L1,ListStack L2){
    char a;//运算符栈传入的是运算的ascll码对应的，用char接收自动转化
    T b,c,d;
    a = L1.pop();
    b = L2.pop();
    c = L2.pop();
    if(a=='*'){
        d = c*b;//这里的c b位置不能改变，因为出栈的顺序是固定的
    }else if(a=='/'){
        d = c/b;
    }else if(a=='+'){
        d = c+b;
    }else if(a=='-'){
        d = c-d;
    }else{
        //cout <<"erro"<<endl;
    }
    L2.push(d);//将运算后的值重新压入栈中
}
//计算中缀表达式
//思路初始化两个栈，一个用来放操作数，一个用来放运算符
//要是遇到了操作数压入操作数栈
//要是遇到运算符压入运算符栈(弹出运算的时候也会弹出两个操作数进行计算，并将结果放回操作数栈)用compute函数实现
double ListStack::Cal(char str[100]){
    int len = 0;
    for(int i = 0;str[i]!='\0';i++){
        len++;//计算表达式长度
    }   
    ListStack L1;
    ListStack L2;
    //(1+2)*3-(2+2)/4
    for(int i =0;i<=len;i++){
        if('0'<=str[i] && str[i]<='9'){//判断是不是数字
            L2.push(str[i]-48);//因为char传入时转成ascll,减去48就是原来的值
            continue;//存入一个后直接开始下一轮循环
        }//这是当表达式的开头不是括号的时候   
        if(str[i]=='(' || L1.If_empty()){//如果开头是括号就将(压入栈，如果不是，那么执行了上面的if，下一个也肯定是运算符
            L1.push(str[i]);//这里不是存数字直接存就可以了
            continue;
        }
        if(str[i]==')'){//如果是)则要开始计算括号里的,)是不需要入栈的，只是一个判断的作用
            char item = L1.GetTop();
            //这个地方我开始写的时候是while(item!='(')，这样就写成一个死循环了，因为现在的item就是开始的值静态的，这样写循环里要加一句item = L1.GetTop();重新获取写的栈顶值
            while(item!='('){//如果栈里不是两个连续的( (,这里用while不用if是因为可能括号里不止一个运算符  列入((1+2*2/2)*3)-(2+2)/4
                this->compute(L1,L2);//计算
                item = L1.GetTop();
            }
            L1.pop();//将栈中的(出栈
            continue;
        }
        if(str[i]=='*'||str[i]=='/'){
            T item2 = L1.GetTop();//看上一个运算符是否已经是*或/，如果是则先运算上一个* /  例如((1+2*2/2)*3)-(2+2)/4
            if(item2 == '/' || item2 == '*'){
                this->compute(L1,L2);
            }
            L1.push(str[i]);//在把这个运算符压入栈
            continue;
        }
        if(str[i]=='+' || str[i]=='-'){
            T item3 = L1.GetTop();
            if(item3 !='('){//如果栈最上面不是(则直接运算  列如  (1+(2-3)+4)/4
                this->compute(L1,L2);
            }
            L1.push(str[i]);//如果是则直接进栈
            continue;
        }
        while(!L1.If_empty()){//如果开头不是(,运算到最后栈不为空则继续运算
            this->compute(L1,L2); //例如1+2-(1*2)
        }
    }
    T num;
    num = L2.GetTop();//获取运算值
    return num;
}
void test(){
    ListStack L;
    char str[100];
    cout <<"请输入计算的中缀式:";
    cin>>str;
    int num = L.Cal(str);
    cout <<num; 
}
int main(){
    test();
    return 0;
}


//后缀相加
/* double ComputePostfix(char* str)
{
    // ÇëÔÚ´ËÌí¼Ó´úÂë£¬²¹È«º¯ÊýComputePostfix£¬¼ÆËãºó×º±í´ïÊ½
    LinkStack* L = LS_Create();//创建放操作数的栈
    //开始扫描
    int len = 0;
    T item=0;
    T a,b;
    for(int i = 0;str[i]!='\0';i++){
        len++;//计算表达式长度
    }
    for(int i =0;i<len;i++){
        if('0'<=str[i] && str[i]<='9'){//判断是不是数字
            LS_Push(L,str[i]-48);//因为char传入时转成ascll,减去48就是原来的值
            continue;//存入一个后直接开始下一轮循环
        }
        if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'){
            LS_Pop(L,a);
            LS_Pop(L,b);
            if(str[i]=='*'){
                item=b*a;
                LS_Push(L,item);
                continue;
            }
            if(str[i]=='/'){
                item=b/a;
                LS_Push(L,item);
                continue;
            }
            if(str[i]=='+'){
               item=b+a;
               LS_Push(L,item);
               continue;
            }
            if(str[i]=='-'){
                item=b-a;
                LS_Push(L,item);
                continue;
            }
        }
    }
    LS_Free(L);
    return item;
} */