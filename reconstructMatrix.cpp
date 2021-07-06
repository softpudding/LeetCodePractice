#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res;
        int cols = colsum.size();
        res.push_back(vector<int>(cols,0));
        res.push_back(vector<int>(cols,0));
        // 先处理colsum中所有为2的情况
        for(int i = 0; i < cols; i++){
            if(colsum[i] == 2){
                if(upper && lower){
                    upper --;
                    lower --;
                    res[0][i] = 1;
                    res[1][i] = 1;
                }
                else{
                    return vector<vector<int>>();
                }
            }
            
        }
        // 再处理所有为1的情况 优先给upper赋值
        for(int i = 0; i < cols; i++){
            if(colsum[i] == 1){
                if(upper){
                    upper--;
                    res[0][i] = 1;
                }
                else if(lower){
                    lower--;
                    res[1][i] = 1;
                }
                else{
                    return vector<vector<int>>();
                }
            }
        }
        if(!upper && !lower)
            return res;
        else
            return vector<vector<int>>();
    }
};