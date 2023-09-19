//背包01问题
#include<iostream> 
#include<vector>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
void test(){
    int num,bagweight;
    cout<<"请输入商品的数量和背包大小"<<endl;
    cin>>num>>bagweight;
    vector<int>wight(num);
    vector<int>value(num);
    cout<<"请输入商品信息(先输入体积再价值)"<<endl;
    for(int i =0;i<num;i++){
        cin>>wight[i];
        cin>>value[i];
    }

    //定义一个二维数组用于记录数据
    vector<vector<int>> dp(wight.size(),vector<int>(bagweight+1,0));
    //该dp的含义是在0~i中选取i个物品装进j容量的背包中
    //初始话第一行和第一列
    for(int j=wight[0];j<=bagweight;j++){
        dp[0][j] = value[0];
    }

    //weight数组的大小就是物品个数
    for(int i=1;i<wight.size();i++){//先遍历物品，这里因为第一行已经全部初始话所以，从i=1开始遍历
        for(int j =0;j<=bagweight;j++){//遍历背包容量
            if(j<wight[i]){//如果背包的容量小于物品的重量，就不拿i物品
                dp[i][j] = dp[i-1][j];
            }else{//拿物品
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-wight[i]]+value[i]);
            }
        }
    }
    cout << dp[wight.size() - 1][bagweight] << endl;//最后一格即使最优的解
}

int main(){
    test();
    return 0;
}