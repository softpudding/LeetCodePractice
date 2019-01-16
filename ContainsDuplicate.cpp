/*
题目：存在重复元素 题号：217
这里是我的第一版可以通过提交的代码，24ms，94.86%.像这种简单难度的题主要是考效率...
我的方法是手写的一个redix sort排一遍序再遍历，检查一下重复。
理论上是线性时间，但我看评论里都说20ms以内是真大神。看来我果然还不是大神...
要加油哦。
*/
void countingSort (vector<unsigned int> & ar,int n, int low, int high)
{
    //use 8 digits as a redix
    unsigned int new_ar[high-low+1];
    for(int i=0;i<=high;i++)
    {
        new_ar[i]=(ar[i]<<(sizeof(unsigned int)*8-n*8))>>(sizeof(unsigned int)*8-8);
        new_ar[i]=new_ar[i]&(0xFF<<8*(n-1));
    }
    int c_size=0;
    for(int i=low;i<=high;i++)
    {
        new_ar[i]>c_size?c_size=new_ar[i]:0;
    }
    unsigned int C[c_size+1]={0};
    unsigned int B[high-low+1];
    for(int i=low;i<=high;i++)
    {
        C[new_ar[i]]++;
    }
    for(int i=1;i<=c_size;i++)
    {
        C[i]+=C[i-1];
    }
    for(int i=high;i>=low;i--)
    {
        B[--C[new_ar[i]]]=ar[i];
    }
    for(int i=low;i<=high;i++)
        ar[i]=B[i];
}
void redixSort (vector<unsigned int> & ar, int low, int high)
{
    if(high<=0)return;
    for(int i=1;i<=sizeof(unsigned int);i++)
        countingSort(ar,i,low,high);
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())return false;
        vector<unsigned int> pos;
        vector<unsigned int> neg;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]>=0)
                pos.push_back(+nums[i]);
            else
                neg.push_back(-nums[i]);
        }
        redixSort(pos,0,pos.size()-1);
        redixSort(neg,0,neg.size()-1);
        for(int i=1;i<pos.size();i++){
            if(pos[i]==pos[i-1])
                return true;
        }
        for(int i=1;i<neg.size();i++){
            if(neg[i]==neg[i-1])
                return true;
        }
        return false;
    }

};