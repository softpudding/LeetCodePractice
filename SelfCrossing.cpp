/*
题目：路径交叉 题号：335
这段代码思路不复杂，但是展现了我的无敌优化能力（不要脸ing）
完美满足题设O(1)空间并且运行时间0ms，100%超越。无敌了无敌了。
*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size()<4)
            return false;
        else
        {
            int path[6]={0};
            path[0]=x[0];
            path[1]=x[1];
            path[2]=x[2];
            path[3]=x[3];
            if(path[3]>=path[1]&&path[2]<=path[0])
                return true;
            for(int i=4;i<x.size();i++){
                if(i==4){
                    path[4]=x[i];
                    if(path[4]>=path[2]&&path[3]<=path[1])
                        return true;
                    if(path[1]==path[3]&&path[4]>=path[2]-path[0])
                        return true;
                }
                else{
                    int a=(i-5)%6,b=(i-4)%6,c=(i-3)%6,d=(i-2)%6,e=(i-1)%6,f=i%6;
                    path[f]=x[i];
                    if(path[d]>=path[b]){
                        if(path[e]<path[c]-path[a]&&path[f]>=path[d])
                            return true;
                        if(path[e]>=path[c]-path[a]&&path[e]<=path[c]&&path[f]>=path[d]-path[b])
                            return true;
                    }
                    else{
                        if(path[f]>=path[d])
                            return true;
                    }
                    
                }
            }
        }
        return false;
    }
};
