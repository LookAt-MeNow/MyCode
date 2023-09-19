/* 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ */

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return n;
        }
        vector<int>a(n+1);//这里要+1因为物理空间大小和逻辑空间大小差1
        a[1] = 1;
        a[2] = 2;
        for(int i = 3;i<n;i++){
            a[i] = a[i-1] +a[i-2];
        }
        return a[n];
    }
};