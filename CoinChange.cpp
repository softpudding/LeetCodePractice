#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        int coinTypes = coins.size();
        // dynamic planning
        for(int i = 1; i <= amount; i++){
            int minCoins = 0;
            for(int j = 0; j < coinTypes; j++){
                int k = i - coins[j];
                if(k == 0){
                    minCoins = 1;
                }
                else if(k < 0){
                    ;
                }
                else{
                    if(dp[k] > 0){
                        if(minCoins == 0){
                            minCoins = dp[k] + 1;
                        }
                        else if(minCoins > 0){
                            if(dp[k]+1 < minCoins){
                                minCoins = dp[k] + 1;
                            }
                        }
                    }
                }
            }
            dp[i] = minCoins;
        }
        if(dp[amount] == 0)
            return -1;
        return dp[amount];
    }
};