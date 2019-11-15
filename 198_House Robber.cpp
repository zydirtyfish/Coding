/*https://leetcode.com/problems/house-robber/*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp;
        dp.resize(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        int rst = max(dp[0],dp[1]);
        for(int i = 2 ; i < nums.size() ; i ++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
            rst = max(dp[i],rst);
        }
        return rst;
    }
};