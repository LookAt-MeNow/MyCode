#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    int a,b;//节点数和节点权数
    int cont;//计数，因为完全二叉树的最后一层不一定是满的
    cin>>a;
    ll Maxsum = 0;//最大的层数和
    bool flag = false;
    int MaxN;//最大层数
    int i =0;
	for(i; ; i++){//每层的层数从0开始计算
        ll sum = 0;//每层的和
        for(int N = 0;N<(1<<i);N++){//利用左移运算符号输入每层的数据
            cin>>b; sum+=b;
            if(++cont>=a){
                flag = true;
                break;
            }
        }
        if(Maxsum<sum){
            Maxsum=sum; MaxN = i+1;
        }
        if(flag)
            break;
    }
    cout <<MaxN;
    return 0;
}