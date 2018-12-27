/*
 2018.12.2
 题目：下一个排列
 解决思想：很简单...大概十分钟就解决了，不说了。
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tail_val=nums[nums.size()-1];
        int i=nums.size()-2;
        while(nums[i]>=nums[i+1]&&i>=0)
            i--;
        if(i==-1)
        {
            sort(nums,0,nums.size()-1);
        }
        else{
            int div=nums[i];
            int new_div=nums.size()-1;
            for(;new_div>i;new_div--)
            {
                if(nums[new_div]>div)
                    break;
            }
            int temp=nums[new_div];
            nums[new_div]=div;
            nums[i]=temp;
            sort(nums,i+1,nums.size()-1);
        }
    }
    //temporarily use a 0(n^2) sort
    void sort (vector<int>& nums, int low, int high)
    {
        for(int i=low;i<=high;i++)
            for(int j=i+1;j<=high;j++)
            {
                if(nums[j]<nums[i])
                {
                    int temp=nums[j];
                    nums[j]=nums[i];
                    nums[i]=temp;
                }
            }
    }
};

int main() {
    vector<int> vec={5,4,1,2,1};
    Solution().nextPermutation(vec);
    for(int i=0;i<vec.size();i++)
        cout<<vec[i];
    return 0;
}