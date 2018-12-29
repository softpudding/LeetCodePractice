/*2018.12.29
题号：50 Pow(x,n)
学过算法的应该都会做，《算法设计技巧与分析》这本书就有相应的例子。
比较tricky的是，原题目有32位长的大输入，所以我选了longlong做数据类型。
因为，0x80000000取负数，仍然会是0x80000000。

*/


#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if(n>0)
            return absolutePow(x,n,1,length(n));
        else if(n==0)
            return 1;
        else{
            return 1/absolutePow(x,-n,1,length(n));
        }
    }
    int length (long long n)
    {
        if(n<0)n=-n;
        int i=1;
        while(n>>i)i++;
        return i;
    }
    double absolutePow(double x, long long n,int cur,int length){
        if(cur==length)
            return x;
        else{
            double result=absolutePow(x,n,cur+1,length);
            if((n>>(cur-1))&0x1)
                return result*result*x;
            else
                return result*result;
        }

    }
};

int main (void) 
{
    cout<<Solution().myPow(2.0,2147483648);
    return 0;
}