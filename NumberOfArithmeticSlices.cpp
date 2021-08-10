#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        vector<vector<int>> dp(size,vector<int>(size,0));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i+1 < size){
                dp[i][i+1] = 2;
            }
        }
        for(int i = 0; i < size; i++){
            for(int j = i+2; j < size; j++){
                if(dp[i][j-1] - dp[i][j-2] == dp[i][j] - dp[i][j-1]){
                    dp[i][j] = dp[i][j-1]+1;
                    if(dp[i][j]>=3){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
        
    }
};