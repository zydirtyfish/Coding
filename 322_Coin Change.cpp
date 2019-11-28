/*https://leetcode.com/problems/coin-change/ */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || amount == 0) return 0;
        vector<int> dp;
        dp.resize(amount + 1);
        dp[0] = -1;
        for(int i = 1 ; i < dp.size(); i++){
            dp[i] = -1;
            for(int j = 0 ; j < coins.size() ; j++){
                if(i == coins[j]){
                    dp[i] = 1;
                    break;
                }
                if(i > coins[j] && dp[i - coins[j]] > 0){
                    if(dp[i] == -1 || dp[i] > 1 + dp[i-coins[j]])
                        dp[i] = 1 + dp[i-coins[j]];
                }
            }
        }
        return dp[amount];
    }
};