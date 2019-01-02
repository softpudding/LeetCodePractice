/*
题目：通配符匹配 题号：44
这题我的代码不是很好 跑起来是44ms 60%这样子
动态规划写的 思路不是很难 但写起来很费劲 因为有很多的cornor case我在一开始没有想到
*/

#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {

        int S=s.size()+1,P=p.size()+1;

        //Cover case in which s=="" or p==""
        if(s==p)
            return true;
        if(S==1){
            for(int i=0;i<P-1;i++)
                if(p[i]=='*')
                    continue;
                else
                    return false;
            return true;
        }
        if(P==1)
            return false;

        int MatchTable[S][P]={0};


        if(p[0]=='*'){
            int lem=0;
            for(int i=1;i<S;i++)
                MatchTable[i][1]=i;
            if(p[1]=='?'||p[1]==s[0])
                MatchTable[1][2]=1;
            for(lem=1;lem<P&&p[lem]=='*';lem++)
                MatchTable[1][lem+1]=1;
            if(lem<P&&p[lem-1]=='*'&&(p[lem]==s[0]||p[lem]=='?'))
                MatchTable[1][lem+1]=1;
        }
        else if(p[0]=='?'||p[0]==s[0])
            MatchTable[1][1]=1;

        int temp=0,max=0;
        for(int j=2;j<P;j++){
            if (p[j-1] =='*'&&MatchTable[1][j-1])
            {
                MatchTable[1][j]=MatchTable[1][j-1];
            }
        }

        for(int i=2;i<S;i++)
            for(int j=2;j<P;j++) {
                max=0;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    temp= (MatchTable[i-1][j-1] + 1)== i? i:0;
                    if(temp ==i)
                    {
                        MatchTable[i][j]=i;
                        continue;
                    }
                }
                if (p[j - 1] == '*')
                {
                    temp=(MatchTable[i-1][j] + 1==i|| MatchTable[i-1][j-1] + 1==i||MatchTable[i][j-1]==i)?i:0;
                    if(temp ==i)
                    {
                        MatchTable[i][j]=i;
                        continue;
                    }

                }
                if (p[j - 2] =='*' && (p[j-1]=='?'||p[j-1]==s[i-1]))
                {
                    for(int k=j-2;k>=0&&p[k]=='*';k--)
                    {
                        temp=MatchTable[i-1][k]==i-1?i:0;
                        if(temp ==i)
                        {
                            MatchTable[i][j]=i;
                            continue;
                        }
                    }
                }

            }
        cout<<MatchTable[S-1][P-1]<<'\n';
        return MatchTable[S-1][P-1]==S-1;
    }
    int Max(int a,int b)
    {
        return a>b?a:b;
    }
};

int main (void){
    cout<<Solution().isMatch("ababbb","**??a*");
    return 0;
}
