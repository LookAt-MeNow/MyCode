/* 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。 *i/
//暴力解法
/* #include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };
};
void printfVector(vector<int>& t){
    for(vector<int>::iterator it=t.begin();it!=t.end();it++){
        cout <<(*it)<<" ";
    }
    cout << endl;
}
void test(){
    Solution a;
    vector<int> m;
    vector<int> n;
    m.push_back(2);
    m.push_back(7);
    m.push_back(11);
    m.push_back(15); 
    printfVector(m);
    n=a.twoSum(m,9);
    printfVector(n);
}
int main(){
    test();
    return 0;
} */

//哈希表法
//哈希表可以直接使用STL类中的

#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Soution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>a;//建立hash表
        vector<int> b(2,-1);//用来接收数据
        vector<int>::iterator it = nums.begin();
        for(int i = 0;i<nums.size();i++){
            a.insert(pair<int,int>((*it),i));
        }
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            //判断是否找到目标元素且目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
        return b;
    }

};

//优化-----将数据放在哈希表的过程放在第二个循环中，边检查边放入

