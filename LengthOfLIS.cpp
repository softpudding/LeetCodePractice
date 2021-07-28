class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);
        for(int i = 1; i < size; i++){
            int len = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    len = dp[j] + 1 > len ? dp[j] + 1 : len;
                }
            }
            dp[i] = len;
        }
        int max = 0;
        for(int i = 0; i < size; i++){
            if(dp[i] > max){
                max = dp[i];
            }
        }
        return max;
    }
};