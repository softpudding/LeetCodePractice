#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<list>
using namespace std;
class Solution {
public:
    static bool compare(vector<int> & v1, vector<int> & v2){
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),compare);
        vector<int> lastElement;
        lastElement = intervals[0];
        int size = intervals.size();
        for(int i = 1; i < size; i++){
            // case aaaaaaa 
            //               bbbbbbbbbb
            if(intervals[i][0] > lastElement[1]){
                res.push_back(lastElement);
                lastElement = intervals[i];
            }
            // case aaaaaaa
            //        bbbbbbbb
            else{
                lastElement[1] = max(intervals[i][1],lastElement[1]);
            }
        }
        res.push_back(lastElement);
        return res;
    }
};