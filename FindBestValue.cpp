#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
    class Solution {
    public:
        int findBestValue(vector<int>& arr, int target) {
            // 随着设置的阈值增大 我们得到的结果是单调递增的
            sort(arr.begin(),arr.end());
            int curSum = 0;
            int size = arr.size();
            for(int i = 0; i < size; i++){
                curSum += arr[i];
            }
            // 从arr里面最大的开始尝试
            int value = arr[size - 1];
            int diff = curSum - target, lastDiff = diff;
            int left = size - 2, right = size - 1;
            // 两种极大极小情况处理
            if(diff <= 0)
                return arr[size-1];
            if(arr[0]*size >= target){
                return (int)(((double)target)/size+0.499);
            }
            // 如果不是极大极小情况 我们要找的value一定在某个arr[left]和arr[right]之间
            int rightVal = 0, leftVal = 0;
            int rightCt = 1;
            while(left >= 0){
                while(left >= 0 && arr[left] == arr[right]){
                    if(left == 0)
                        return arr[left];
                    right = left;
                    left--;
                    // 记录一下有几个大于等于arr[j]的值
                    rightCt++;
                }
                // diff为选取value为arr[left]之后的值
                diff -= rightCt*(arr[right]-arr[left]);
                if(diff == 0)
                    return arr[left];
                if(diff<0 && lastDiff>0){
                    // 如果diff和lastdiff异号
                    // value一定在arr[left]和arr[right]之间
                    break;
                }
                // 逻辑上不可能发生的情况
                if(left == 0)
                    assert(0);
                lastDiff = diff;
                right = left;
                rightCt++;
                left--;
            }
            // 假设要找的最理想值为x (x>arr[left] && x<arr[right])
            // 有lastDiff - rightCt*(arr[right]-x) == 0
            // rightCt*x == rightCt*arr[right]-lastDiff
            //cout<<diff<<' '<<lastDiff<<' '<<rightCt<<' '<<arr[right]<<endl;
            //cout<<(rightCt*arr[right]-lastDiff)<<' '<<((double)(rightCt*arr[right]-lastDiff))/4+0.49;
            int res = (int)(((double)(rightCt*arr[right]-lastDiff))/rightCt+0.499);
            return res;
        }
    };