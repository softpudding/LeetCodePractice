#include <vector>
using namespace std;
class Solution {
public:
    unsigned int getWays(vector<unsigned int> & nums, unsigned int cur_index, unsigned int target){
        unsigned int ways = 0, size = nums.size();
        if(nums[cur_index] > target){
            return 0;
        }
        unsigned int new_target = target - nums[cur_index];
        if(new_target == 0){
            unsigned int zeros = 0;
            for(unsigned int i = cur_index + 1; i < size; i ++){
                if(nums[i] == 0){
                    zeros ++;
                }
            }
            return 1 + (zeros ? (1<<zeros) - 1 : 0);
        }
        for(unsigned int i = cur_index + 1; i < size; i++){
            ways += getWays(nums,i,new_target);
        }
        return ways;
    }
    unsigned int findTargetSumWays(vector<unsigned int>& nums, unsigned int S) {
        unsigned int sum = 0, size = nums.size(), zeros = 0;
        for(unsigned int i = 0;i < size; i++){
            sum+=nums[i];
            if(nums[i] == 0)
                zeros ++;
        }
        if((S+sum) % 2)
            return 0;
        unsigned int target = (S + sum) / 2;
        if(target == 0){
            unsigned int zeros = 0;
            for(unsigned int i = 0; i < size; i ++){
                if(nums[i] == 0)
                    zeros ++;
            }
            return (1<<zeros);
        }
        unsigned int ways = 0;
        for(unsigned int i = 0; i < size; i++){
            ways += getWays(nums,i,target);
        }
        return ways;
    }
};