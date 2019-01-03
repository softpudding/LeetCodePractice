/*
2018.12.27
题目：至少有K个重复字符的最长子串 题号：395 
解决思想：通过划分不断把原本的字符串变小
统计原本字符串中每个字符出现的次数，把那些次数少于k的标记出来，简称d♂b
假如原字符串是这样：aaabbbcdefcdefgggggggggggggggcde， 然后k是3
在这里，f只出现了两次，就会被我们标记为db
aaabbbcde*cde*gggggggggggggggcde
然后递归地调用，每次对于一个新的字串继续查找db
最后找到db间最长的字串即可
*/
#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length()==0)
            return 0;
        else if(k==1)
            return s.length();
        int CountSet[26]={0};
        for(int i=0;i<s.length();i++)
            CountSet[s[i]-'a']++;
        int l=0;
        int max=0,temp=0;
        for(int i=0;i<s.length();i++)
        {
            if(CountSet[s[i]-'a']<k)
            {
                temp=recursiveFind(s,l,i-1,k);
                if(temp>max){
                    max=temp;
                }
                l=i+1;
            }
        }
        temp=recursiveFind(s,l,s.length()-1,k);
        if(temp>max)
            max=temp;
        return max;
    }
    int recursiveFind(string s, int low, int high,int k)
    {
        if(low>=high)
            return 0;
        int CountSet[26]={0};
        for(int i=low;i<=high;i++)
            CountSet[s[i]-'a']++;
        int l=low;int temp=0,max=0;
        for(int i=low;i<=high;i++)
        {
            if(CountSet[s[i]-'a']<k)
            {
                temp=recursiveFind(s,l,i-1,k);
                if(temp>max)
                    max=temp;
                l=i+1;
            }
        }
        if(l==low)
        {
            return high-low+1;
        }
        else{
            temp=recursiveFind(s,l,high,k);
            if(temp>max)
                max=temp;
        }
        return max;
    }
};

int main() {
    string line="aaabbbcdefcdefgggggggggggggggcde";
    cout<< Solution().longestSubstring(line,3);
    return 0;
}