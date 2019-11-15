/*https://leetcode.com/problems/climbing-stairs/*/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)return n;
        
        int tmp1 = 1,tmp2 = 2, rst = 0;
        for(int i = 2 ; i < n ; i++){
            rst = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = rst;
        }
        return rst;
    }
};