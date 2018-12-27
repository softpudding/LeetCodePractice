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