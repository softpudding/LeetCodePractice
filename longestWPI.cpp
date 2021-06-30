#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        // scores将hours以是否大于8作为标准来二值化
        vector<int> scores(len,0);
        for(int i = 0; i < len; i++)
            scores[i] = hours[i] > 8 ? 1: -1;
        // presum是score数组的一个前缀和
        vector<int> preSum(len,0);
        int temp_sum = 0;
        // negPresum2Index是presum数组中值为k（k是负数）的
        // 元素第一次出现的位置
        map<int,int> negPresum2Index;
        int res = 0;
        for(int i = 0; i < len; i++){
            temp_sum += scores[i];
            preSum[i] = temp_sum;
            if(temp_sum < 0 && negPresum2Index.find(temp_sum) == negPresum2Index.end()){
                negPresum2Index.insert(pair<int,int>(temp_sum,i));
            }
            else if(temp_sum > 0){
                // 假设longestWPI是下表为0~i的一个区间 那么结果会在这里得到
                res = i+1;
            }
        }
        // 假设要求的longestWPI是下标j~i的一段区间 其中0<=i<=j 
        // 那么必然有preSum[j] == preSum[i]-1
        // 并且 preSum[i] < 0
        for(int i = 0, j = 0; i < len; i++){
            if(preSum[i] <= 0){
                auto iter = negPresum2Index.find(preSum[i] - 1);
                if(iter == negPresum2Index.end()){
                    continue;
                }
                else{
                    j = iter->second;
                    if(i > j)
                        res = i - j > res ? i - j : res;
                }
            }

        }

        return res;

    }
};

int main(){
    int test_arr[] = {6,6,9};
    vector<int> test_input = vector<int>(test_arr, test_arr+3);
    Solution s;
    cout<<"\nResult:"<<s.longestWPI(test_input);
    return 0;

}