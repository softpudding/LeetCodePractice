#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
private:
    void inline printArray(vector<int> & nums){
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i]<<' ';
        }
        cout<<endl;
    }

    // 在递增数组nums里把下标为i的数值*2 并且维护nums数组单调递增的特性
    void doublePos(vector<int> & nums, int i){
        int val = nums[i]*2;
        int size = nums.size();
        int j;
        for(j = i+1; j < size; j++){
            if(nums[j] < val){
                nums[j-1] = nums[j];
            }
            else{
                break;
            }
        }
        nums[j-1] = val;
    }
    // 在递增数组nums里把下标为i的数值/2 并且维护nums数组单调递增的特性
    void halfPos(vector<int> & nums, int i){
        int val = nums[i]/2;
        int size = nums.size();
        int j;
        for(j = i-1; j >= 0; j--){
            if(nums[j] > val){
                nums[j+1] = nums[j];
            }
            else{
                break;
            }
        }
        nums[j+1] = val;
    }
public:
    int minimumDeviation(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int dev = nums[size - 1] - nums[0];
        int newDev = 0;
        int newVal = 0;
        int shouldEnd = 0;
        while(true){
            shouldEnd = 0;
            // 如果当前最小值是奇数 可以尝试*2
            if(nums[0] % 2){
                newVal = nums[0]*2;
                if(newVal > nums[size - 1]){
                    if(nums[size-1]-nums[0] == nums[0]*2 - nums[size -2])
                        break;
                    newDev = newVal - nums[1];
                    if(newDev > dev)
                        shouldEnd++;
                    else{
                        dev = newDev;
                        doublePos(nums,0);
                    }
                }
                else{
                    // 这种情况newDev>dev是必然的
                    doublePos(nums,0);
                    dev= nums[size-1]-nums[0];
                }
            }
            else{
                shouldEnd++;
            }
            // 如果最大值是偶数 可以尝试/2
            if(nums[size - 1] % 2 == 0){
                newVal = nums[size - 1]/2;
                if(newVal < nums[0]){
                    newDev = nums[size - 2] - newVal;
                    if(newDev > dev){
                        shouldEnd++;
                    }
                    else{
                        dev = newDev;
                        halfPos(nums,size-1);
                    }
                }
                else{
                    halfPos(nums,size-1);
                    dev= nums[size-1]-nums[0];
                }
            }
            else{
                shouldEnd++;
            }
            if(shouldEnd == 2)
                break;
        }
        return dev;
    }
};