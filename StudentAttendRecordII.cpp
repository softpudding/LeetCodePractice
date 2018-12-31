/*
2018.12.30 
题目：学生出勤记录II 题号：552 这个版本是36ms，78.95%
我解题第一遍的思路是先不考虑A，只考虑LP构成的合法的序列的数量
记长度为N的以P开头P结尾的合法序列组合数量C[N] 即P***P的数量
那么可以推导出以下几种长度为N的序列的组合：
1.LP**P 以一个L开头P结尾 组合数量C[N-1]
2.LLP*P 以两个L开头P结尾 组合数量C[N-2] 又 这种组合与LP*PL P*PLL 相同
3.LLP*L 两个L开头 一个L结尾 组合数量C[N-3] 又 这种组合与LP*LL相同
4.LLPLL 两个L开头 两个L结尾 书和数量C[N-4]
那么可以得到递归式：
C[N]=max{C[i]*C[N-i]+C[i]*C[N-i-1]+C[i]*C[N-i-2]}(0=<i<=N)
这个递归的含义是：一个长度为N的序列可以由一个i的序列和一个N-i的序列构成
i的序列是一个P***P的序列 N-i的序列既可以是P***P 也可以是LP**P也可以是LLP*P
这里i的N种可能中取最大值
然后第二遍解题的时候我发现这里i必然取1，取1的时候永远是最大的
这里给出证明
#######
[1].C[1]=C[2] 很好理解，C[1]只有P一种可能，C[2]是PP
[2].C[N]是单调递增的序列。我觉得这是一个显而易见的结论。因为取i取1时C[N]就必然大于C[N-1]。
[3]. C[N+1]<=2C[N] 从 C[1]=1 C[2]=1 C[3]=2 C[4]=4 C[5]=7 可以继续归纳出来(N>=2)
[4]. C[N+1]>=7/4C[N] 一样的，也是归纳 但是比上面一步更简单(N>=2)
[5].从[1][2][3][4]下的基础出发。由成立条件N>=2易得结论。
易得结论。      
#######
其余部分就很好理解了
*/


#include<iostream>
using namespace std;


class Solution {
public:
    const long long MOD=1000000007;
    long long checkRecord(int n) {
        switch(n)
        {
            case 1:
                return 3;
            case 2:
                return 8;
            case 3:
                return 19;
            default:
                break;
        }
        //[P*****************P]
        long long P_table[n+1];
        //suppose P_table[0]=0
        calcP(P_table,n);
        long long result=0;
        for(int i=1;i<=n;i++) {
            //i represents that when a is in ith pos
            result += LP(P_table,i - 1)*LP(P_table,n-i);
            result%=MOD;
        }
        result+=LP(P_table,n);
        return result%MOD;

    }
    void calcP(long long * P_table,int n){
        P_table[0]=0;
        P_table[1]=1;//P
        P_table[2]=1;//PP
        P_table[3]=2;//PPP PLP
        P_table[4]=4;//PPPP PLLP PLPP PPLP
        if(n==4)
            return;
        for(int i=5;i<=n;i++)
        {
            P_table[i]=(P_table[1]*P_table[i-1])+(P_table[1]*P_table[i-2])+(P_table[1]*P_table[i-3]);
            P_table[i]%=MOD;
        }
    }
    long long LP(long long * P_table,int n){
        switch(n)
        {
            case 0:
                return 1;
            case 1:
                return 2;
            case 2:
                return 4;
            case 3:
                return 7;
            case 4:
                return 13;
            default:
                return (P_table[n]+P_table[n-1]*2+P_table[n-2]*3+P_table[n-3]*2+P_table[n-4])%MOD;
        }
    }
};


int main (void){
    cout<<Solution().checkRecord(100);
    return 0;
}
