/* 题号 16 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // v0.1 最简单 遍历 可以通过测试 424ms 5.02%
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        int temp;
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                for(int k = j+1; k< size; k++){
                    temp = nums[i]+nums[j]+nums[k];
                    if((temp > target? temp - target : target - temp) < (closest > target? closest - target : target - closest)){
                        closest = temp;
                    }
                }
            }
        }
        return closest;

    }
};
class Solution_2 {
public:
    inline int abs(int a){
        return a > 0 ? a : -a;
    }
    // v0.2 减少内存访问次数 可以通过测试 368ms 感觉没有本质上的变化 可能要从算法的角度来考虑
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        int temp;
        int closest_difference = nums[0]+nums[1]+nums[2]-target,temp_difference;
        int temp_third;
        for(int i = 0; i < size - 2; i++){
            for(int j = i+1; j < size - 1; j++){
                temp_third = nums[j+1];
                temp = nums[i] + nums[j] + temp_third;
                temp_difference = temp - target;
                if(abs(temp_difference) < abs(closest_difference)){
                    closest = temp;
                    closest_difference = temp_difference;
                }
                for(int k = j+1; k< size; k++){
                    if(abs(nums[k] - temp_third + temp_difference) < abs(closest_difference)){
                        temp_third = nums[k];
                        temp = nums[i] + nums[j] + temp_third;
                        temp_difference = temp - target;
                        closest = temp;
                        closest_difference = temp_difference;
                    }
                }
            }
        }
        return closest;

    }
};
class Solution_3 {
public:
    inline int abs(int a){
        return a > 0 ? a : -a;
    }
    // v0.3 这个是看了评论才知道的 应该先排序 然后再。。8ms 90.59%
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        int temp, temp_first;
        for(int i = 0; i < size - 2; i++){
            temp_first = nums[i];
            int l = i+1, r = size - 1;
            while(l != r){
                temp = temp_first + nums[l] + nums[r];
                if(temp < target){
                    closest = abs(temp - target) < abs(closest - target) ? temp : closest;
                    l++;
                }
                else if(temp > target){
                    closest = abs(temp - target) < abs(closest - target) ? temp : closest;
                    r--;
                }
                else{
                    return temp;
                }
            }
        }
        return closest;
    }
};