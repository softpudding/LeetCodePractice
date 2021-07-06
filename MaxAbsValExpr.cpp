#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
private:
    const static int TYPES = 4;
public:
    // 三维曼哈顿距离
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        /* 
         * |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| = 
         * 情况1. arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j = (arr1[i]+arr2[i]+i) - (arr1[j]+arr2[j]+j)
         * 情况2. arr1[i] - arr1[j] + arr2[i] - arr2[j] + i + j = (arr1[i]+arr2[i]-i) - (arr1[j]+arr2[j]-j)
         * 情况3. arr1[i] - arr1[j] - arr2[i] + arr2[j] + i - j = (arr1[i]-arr2[i]+i) - (arr1[j]-arr2[j]+j)
         * 情况4. arr1[i] - arr1[j] - arr2[i] + arr2[j] - i + j = (arr1[i]-arr2[i]-i) - (arr1[j]-arr2[j]-j)
         * 情况5. - arr1[i] + arr1[j] + arr2[i] - arr2[j] + i - j = (arr1[j]-arr2[j]-j) - (arr1[i]-arr2[i]-i) 与情况4相同
         * 情况6、7、8 都是冗余的 不需要再考虑 因为i、j是等价的
         */
        int maxVals[TYPES] = {-400000, -400000, -400000, -400000};
        int minVals[TYPES] = {400000, 400000, 400000, 400000};
        int operators[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
        int size = arr1.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < TYPES; j++){
                int val = arr1[i] + operators[j][0]*arr2[i]+operators[j][1]*i;
                maxVals[j] = val > maxVals[j] ? val : maxVals[j];
                minVals[j] = val < minVals[j] ? val : minVals[j];
            }
        }
        int res = 0;
        for(int i = 0; i < TYPES; i++){
            res = maxVals[i] - minVals[i] > res ? maxVals[i] - minVals[i] : res;
        }
        
        return res;
        
        return 0;
    }
};