/*
题目：数字1的个数 题号：233
这题还蛮有意思的，23333.
主要递归思想就是把一个数字从高位往低位一位一位遍历，因为相同位数的值里面含数字1的个数是一样的。
*/

class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)return 0;
        int L[20]={0};
        L[0]=0;L[1]=1;
        int con=10;
        for(int i=2;i<10;i++){
            L[i]=10*L[i-1]+con;
            con*=10;
            cout<<L[i]<<' ';
        }
        //L[x]表示x位数最多L[x]个1
        int res=0,length=length_of(n);
        int temp=n,temp_length=length-1,a=0,t=0;
        while(temp!=0){
            if(temp<10){
                res+=1;
                break;
            }
            t=pow10(temp_length);
            a=temp/t;
            if(a>1){
                res+=a*L[temp_length]+t;
            }
            else if (a==1){
                res+=L[temp_length]+temp-(temp/t)*t+1;
            }
            temp-=(temp/t)*t;
            temp_length--;
        }
        return res;

    }
    int length_of(int k){
        if(k/10==0)
            return 1;
        else return length_of(k/10)+1;
    }
    int pow10(int n){
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        else return pow10(n-1)*10;
    }
};