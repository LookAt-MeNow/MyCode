/* class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);//初始化dp数组，用于存在nums区间的最长子序列
        int cnt = 0;
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
            }
            if(dp[i]>cnt)    cnt = dp[i];
        }
        return cnt;
    }
}; */