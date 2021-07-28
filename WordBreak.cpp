#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int> cmap;
        int len = wordDict.size();
        for(int i = 0; i < len; i++){
           cmap.insert(pair<string,int>(wordDict[i],1));
        }
        len = s.size();
        vector<vector<string>> dp(len+1,vector<string>());
        for(int i = 1; i < len; i++){
            string targetStr = s.substr(0,i);
            if(cmap.find(targetStr) != cmap.end()){
                dp[i].push_back(targetStr);

                cout<<i<<" strs:\n";
                for(int k = 0; k < dp[i].size();k++){
                    cout<<dp[i][k]<<endl;
                }
            }

            for(int j = i-1; j >= 0; j--){
                if(dp[j].size() != 0){
                    targetStr = s.substr(j,i-j);
                    if(cmap.find(targetStr) != cmap.end()){
                        for(int a = 0; a < dp[j].size(); a++){
                            string s = dp[j][a];
                            dp[i].push_back(s+" "+targetStr);

                            cout<<i<<" strs:\n";
                            for(int k = 0; k < dp[i].size();k++){
                                cout<<dp[i][k]<<endl;
                            }
                        }
                    }
                }
            }
        }
        return dp[len];
    }
};