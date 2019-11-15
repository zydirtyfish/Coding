/*https://leetcode.com/problems/maximum-subarray/*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        int rst = nums[0], dp = nums[0];
        for(int i = 1; i < nums.size() ; i ++){
            dp = max(nums[i],nums[i]+dp);
            rst = max(dp,rst);
        }
        return rst;
    }
};