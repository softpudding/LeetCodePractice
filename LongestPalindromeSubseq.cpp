#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size()-1;
        vector<vector<int>> dp(size,vector<int>(size,0));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
        }
        for(int len = 2; len <= size; len++){
            for(int i = 0; i+len-1 < size; i++){
                int j = i+len-1;
                if(s[i] == s[j]){
                    if(i+1 <= j-1){
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                    else{
                        dp[i][j] = 2;
                    }
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][size-1];
    }
};