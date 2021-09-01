#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int res = 0;
        std::map<int,std::vector<int> &> numPosMap;
        int size = nums.size();
        std::map<int,std::vector<int> &>::iterator it;
        for(int i = 0; i < size; i++){
            it = numPosMap.find(nums[i]);
            if(it == numPosMap.end()){
                numPosMap.insert(std::pair<int,std::vector<int>&>(nums[i],std::vector<int>()));
            }
            else{
                it->second.push_back(i);
            }
        }
        for(int i = 0; i < size-2; i++){
            for(int j = i+1; j < size-1; j++){
                // try nums[i] nums[j] .. subarray
                int diff = nums[j] - nums[i];
                int len = 2;
                int prevN = nums[j];
                int nextN = prevN + diff;
                it = numPosMap.find(nextN);
                if(it == numPosMap.end()){
                    continue;
                }
                else{
                    
                }
            }
        }
    }
};