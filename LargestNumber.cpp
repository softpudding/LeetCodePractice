#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool compare(int a, int b){
        string aa = to_string(a);
        string bb = to_string(b);
        return aa+bb > bb+aa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string res;
        for(int i = 0; i < nums.size(); i++){
            res += to_string(nums[i]);
        }
        if(res[0] == '0')
            return "0";
        return res;
    }
};