/*
题目：寻找两个有序数组的中位数 题号：4
这道题要求你找出一个log(M+N)的算法，然后我的方法是MAX{log(m),log(n)}的，绝对可以满足要求。
但是事实上，这个程序跑起来52ms，60%，并不是很尽人意。这就让我想起了李国强老师的话，理论上的快不一定是实际上的快。
事实上，我觉得我随便写一个O(M+N)的算法可能跑的都比这个快。
代码结构应该很简洁明了了。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
        public:
            double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                if(nums1.empty())
                {
                    if(nums2.size()%2)
                        return nums2[nums2.size()/2];
                    else return (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2.0;
                }
                if(nums2.empty())
                {
                    if(nums1.size()%2)
                        return nums1[nums1.size()/2];
                    else return (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
                }
                if(nums1.size()==1&&nums2.size()==1)
                    return (nums1[0]+nums2[0])/2.0;

                int step=min(nums1.size()/4,nums2.size()/4);
                int index1=max(nums1.size()/2-1,0),index2=max(nums2.size()/2-1,0);
                if((nums1.size()%2||nums2.size()%2)&&(nums1.size()>2||nums2.size()>2)&&nums1.size()!=1&&nums2.size()!=1){
                    if(nums1.size()>nums2.size())
                        index1++;
                    else
                        index2++;
                }

                if(nums1.size()>nums2.size())
                    return iterativeFind(nums1,index1,nums2,index2,step);
                else
                    return iterativeFind(nums2,index2,nums1,index1,step);


            }
            //suppose I keep that low1+high1==nums1.size() and low2+high2==nums2.size()

            double iterativeFind(vector<int>& nums1,int index1,vector<int>& nums2,int index2,int step){

                int next_step=max(step/2,1);

                if(nums1[index1]>=nums2[index2]){
                    if(index2+1<nums2.size())
                    {
                        if(nums1[index1]<=nums2[index2+1])
                        {
                            if((nums1.size()+nums2.size())%2)
                                return nums1[index1];
                            else
                                if(index1+1<nums1.size())
                                    return (nums1[index1]+min(nums1[index1+1],nums2[index2+1]))/2.0;
                                else return (nums1[index1]+nums2[index2+1]);
                        }
                        else
                            if(index1-next_step>=0)
                                return iterativeFind(nums1,index1-next_step,nums2,index2+next_step,next_step);
                            else
                                if((nums2.size()+nums1.size())%2)
                                    return nums2[index2+1];
                                else if(index2+2<nums2.size())
                                {
                                    return (min(nums2[index2+2],nums1[index1])+nums2[index2+1])/2.0;
                                }
                                else return (nums1[index1]+nums2[index2+1])/2.0;
                    }
                    else{
                        //index2 tail...
                        if((nums1.size()+nums2.size())%2)
                            return nums1[index1];
                        else if(index1+1<nums1.size())
                            return (nums1[index1]+nums1[index1+1])/2.0;
                        else return 5555.0;
                    }
                }
                else{
                    if(index1+1<nums1.size())
                    {
                        if(nums2[index2]<=nums1[index1+1])
                        {
                            if((nums2.size()+nums1.size())%2)
                                return nums2[index2];
                            else if(index2+1<nums2.size())
                                return (nums2[index2]+min(nums2[index2+1],nums1[index1+1]))/2.0;
                            else return (nums2[index2]+nums1[index1+1])/2.0;
                        }
                        else
                            if(index2-next_step>=0)
                                return iterativeFind(nums1,index1+next_step,nums2,index2-next_step,next_step);
                            else
                                if((nums2.size()+nums1.size())%2)
                                    return nums1[index1+1];
                                else
                                    if(index1+2<nums1.size())
                                    {
                                        return (min(nums1[index1+2],nums2[index2])+nums1[index1+1])/2.0;
                                    }
                                    else return (nums2[index2]+nums1[index1+1])/2.0;
                    }
                    else{
                        //index1 tail...
                        if((nums1.size()+nums2.size())%2)
                            return nums2[index2];
                        else if(index2+1<nums2.size())
                            return (nums2[index2]+nums2[index2+1])/2.0;
                        else return 5555.0;
                    }

                }

            }
            int min(int a,int b)
            {
                return a<b?a:b;
            }
            int max(int a,int b)
            {
                return a>b?a:b;
            }
        };
int main (void){
    vector<int> nums1={3,4};
    vector<int> nums2={1,2,5,6};
    cout<<Solution().findMedianSortedArrays(nums1,nums2);
    return 0;
}