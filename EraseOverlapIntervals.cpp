#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
bool compBySecondVal(vector<int> v1, vector<int> v2){
    assert(v1.size() == 2);
    assert(v2.size() == 2);
    return v1[1] < v2[1];
}
class Solution {
public:
    // 贪心
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 先按照右端点升序
        sort(intervals.begin(),intervals.end(),compBySecondVal);
        int n = 1;
        int r = intervals[0][1];
        int size = intervals.size();
        for(int i = 1; i < size; i++){
            if(intervals[i][0] >= r){
                r = intervals[i][1];
                n++;
            }
        }
        return size - n;
    }
};