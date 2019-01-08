/*
题目：Excel表格序号 题号：171 4ms 100%
这题目谁都做的出来，关键是效率。我做了两遍，顺便验证了一下最近学的一点知识。
第一遍用的是Hornor的多项式算法，理论上来说比下面这个代码更高效。
但是事实上并没有...和并行运算有关系。
*/
class Solution {
public:
    int titleToNumber(string s) {
        int exp=1;
        int res=s[s.size()-1]-'A'+1;
        for(int i=s.size()-2;i>=0;i--)
        {
            exp*=26;
            res+=(s[i]-'A'+1)*exp;
        }
        return res;
        
    }
    
};