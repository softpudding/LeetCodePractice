/*
题目：戳气球 题号：312
这个题目用的是动态规划的思想，方法和矩阵链相乘的那个算法非常接近。
如果用C[i..j]表示戳完[i,j]内所有气球的得分，那么可以得到结论：
MAX{C[i..j]}=MAX{C[i..k]+C[k+1..j]+R}(i=<k<=j,R表示戳掉k带来的得分)
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//dynamic programming
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if(!size)return 0;
        int table[size][size]={};
        for(int i=0;i<size;i++)
            table[i][i]=(i-1<0? 1: nums[i-1])*nums[i]*(i+1>=size? 1:nums[i+1]);
        for(int div=1;div<size;div++)
        {
            for(int i=0;i<size-div;i++)
            {
                int max=INT32_MIN;
                for(int k=i+1;k<i+div;k++)
                {
                    if((table[i][k-1]+table[k+1][i+div]+(i-1<0? 1: nums[i-1])*nums[k]*(i+div+1>=size? 1:nums[i+div+1]))>max)
                        max=(table[i][k-1]+table[k+1][i+div]+(i-1<0? 1: nums[i-1])*nums[k]*(i+div+1>=size? 1:nums[i+div+1]));
                }
                if(table[i+1][i+div]+(i-1<0?1:nums[i-1])*nums[i]*(i+div+1>=size? 1:nums[i+div+1])>max)
                    max=table[i+1][i+div]+(i-1<0?1:nums[i-1])*nums[i]*(i+div+1>=size? 1:nums[i+div+1]);
                if(table[i][i+div-1]+(i-1<0?1:nums[i-1])*nums[i+div]*(i+div+1>=size? 1:nums[i+div+1])>max)
                    max=table[i][i+div-1]+(i-1<0?1:nums[i-1])*nums[i+div]*(i+div+1>=size? 1:nums[i+div+1]);
                table[i][i+div]=max;
            }
        }
        return table[0][size-1];
    }
    int max(int a,int b)
    {
        return a>b?a:b;
    }
};

int main (void) 
{
    vector<int> nums={3,1,5,8};
    cout<<Solution().maxCoins(nums);
    return 0;
}