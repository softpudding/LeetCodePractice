/*
题目：最小差值II 题号：910
先用了一个redixSort排序，然后按照一个思想：前k个值都加上K，后面的值全都减去K，这样子来做。
*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if(A.size()==1)
            return 0;
        redixSort(A,0,A.size()-1);
        int min=A[0],max=A[A.size()-1],temp=0,res=0;
        res=max-min;
        for(int i=0;i<A.size()-1;i++){
            temp=Max(A[i]+K,A[A.size()-1]-K)-Min(A[i+1]-K,A[0]+K);
            if(temp<res)
                res=temp;
        }
        return res;

    }
    int Max(int a,int b){
        return a>b?a:b;
    }
    int Min(int a,int b){
        return a<b?a:b;
    }
    void countingSort (vector<int> & ar,int n, int low, int high)
    {
        //use 8 digits as a redix
        int new_ar[high-low+1];
        for(int i=0;i<=high;i++)
        {
            new_ar[i]=(ar[i]<<(sizeof(int)*8-n*8))>>(sizeof(int)*8-8);
            new_ar[i]=new_ar[i]&0xFF;
        }
        int c_size=0;
        for(int i=low;i<=high;i++)
        {
            new_ar[i]>c_size?c_size=new_ar[i]:0;
        }
        int C[c_size+1]={0};
        int B[high-low+1];
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
    void redixSort (vector<int> & ar, int low, int high)
    {
        if(high<=0)return;
        for(int i=1;i<=sizeof(int);i++)
            countingSort(ar,i,low,high);
    }

};
