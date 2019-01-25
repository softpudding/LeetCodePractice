/*
题目：卡牌分组 题号：914
这个题目就统计一下每个数字出线的次数，然后计算他们这些数字之间是否存在一个大于2的最大公约数。
*/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int size=deck.size();
        int max=0;
        for(int i=0;i<size;i++){
            if(deck[i]>max)
                max=deck[i];
        }
        int ct[max+1]={0};
        for(int i=0;i<size;i++){
            ct[deck[i]]++;
        }
        vector<int> nums;
        for(int i=0;i<=max;i++){
            if(ct[i])
                nums.push_back(ct[i]);
        }
        int minX=euclid(nums[0],nums[1]),temp=0;
        if(minX<2)
            return false;
        size=nums.size();
        
        
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                temp=euclid(nums[i],nums[j]);
                temp=euclid(minX,temp);
                if(temp<minX){
                    minX=temp;
                    if(minX==1)
                        return false;
                }
            }
        }
        return true;
        
    }
    int euclid(int a,int b){
        //make sure a>b
        if(b==0){
            return a;
        }
        if(a>b){
            return euclid(b,a%b);
        }
        else return euclid(a,b%a);
    }
};