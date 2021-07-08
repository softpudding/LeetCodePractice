#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
private:
    const static bool debug = false;
    static inline int MIN(int a, int b){
        return a < b ? a : b;
    }
    // 从a转到b clockwise和anticlockwise的距离
    static inline int clockwiseDistance(int a, int b, int n){
        return (b-a+n)%n;
    }
    static inline int antiClockwiseDistance(int a, int b, int n){
        return (a-b+n)%n;
    }
public:
    int findRotateSteps(string ring, string key) {
        int curPos = 0;
        int steps = 0;
        int keySize = key.size(), ringSize = ring.size();
        int res = 1000000;
        vector<vector<int>> charIndices;
        for(int i = 0; i < 26; i++)
            charIndices.push_back(vector<int>());
        for(int i = 0; i < ringSize; i++){
            charIndices[ring[i]-'a'].push_back(i);
        }
        // dp[i][j] 为了拼写出key的第i个字符 ring的第j个字符与 12:00方向对齐的最少步数（下标均从0开始）
        vector<vector<int>> dp;
        for(int i = 0; i < keySize; i++){
            dp.push_back(vector<int>(ringSize,0));
        }
        for(int i = 0; i < keySize; i++){
            char targetChar = key[i];
            vector<int> & targetCharIndices = charIndices[key[i] - 'a']; 
            if(i == 0){
                for(int j = 0; j < targetCharIndices.size(); j++){
                    dp[i][targetCharIndices[j]] = MIN(targetCharIndices[j],ringSize-targetCharIndices[j]);
                }
            }
            else{
                vector<int> & prevTargetCharIndices = charIndices[key[i-1] - 'a'];
                for(int j = 0; j < targetCharIndices.size(); j++){
                    int minVal = 100000;
                    for(int k = 0; k < prevTargetCharIndices.size(); k++){
                        int val = dp[i-1][prevTargetCharIndices[k]] + MIN(clockwiseDistance(prevTargetCharIndices[k],targetCharIndices[j],ringSize),
                        antiClockwiseDistance(prevTargetCharIndices[k],targetCharIndices[j],ringSize));
                        if(val<minVal){
                            minVal = val;
                        }
                    }
                    dp[i][targetCharIndices[j]] = minVal;
                }
            }
        }
        for(int i = 0; i < ringSize; i++){
            if(ring[i] == key[keySize-1] && dp[keySize-1][i] < res)
                res = dp[keySize-1][i];
        }
        
        return res+keySize;
    }
};
int main(){
    string ring,key;
    cin>>ring;
    cin>>key;
    Solution s;
    cout<<s.findRotateSteps(ring,key);
    return 0;
}