/*
题目：最多能完成排序的块II 题号：768
这道题让我明白了一个道理...不可以过度迷信动态规划...
现在好像动态规划做多了，我满脑子都是动态规划，拿到这道题也是，拿过来就啪啪啪地写了个动态规划。
即Solustion0。然后发现...在输入大小为2000的时候时间炸了。
确使，动态规划做的话时间复杂度是O(n^3)...
后来看了一些blog，写了Solution里面的代码。
这是一个贪心算法的思想，每次保持当前的一个区间。这个区间只有当他的最小值大于它左边的所有值，
并且他的最大值大于他右边的所有值的时候，才可以成为一个新的“题目要求的块”。
*/
class Solution0 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int S=arr.size();
        /*int max_table[S][S]={0};
        int min_table[S][S]={0};
        int ct_table[S][S]={0};*/
        int ** max_table=new int *[S];
        int ** min_table=new int *[S];
        int ** ct_table=new int *[S];
        for(int i=0;i<S;i++)
        {
            max_table[i]=new int [S];
            min_table[i]=new int [S];
            ct_table[i]=new int [S];
        }
        for(int i=0;i<S;i++)
        {
            max_table[i][i]=min_table[i][i]=arr[i];
            ct_table[i][i]=1;
        }
        for(int x=1;x<S;x++)
            for(int y=0;y+x<S;y++) {
                cout<<"Working on "<<y<<" "<<y+x<<'\n';
                max_table[y][y + x] =
                        max_table[y][y] > max_table[y + 1][y + x] ? max_table[y][y] : max_table[y + 1][y + x];
                min_table[y][y + x] =
                        min_table[y][y] < min_table[y + 1][y + x] ? min_table[y][y] : min_table[y + 1][y + x];
                int max = 0;
                int temp = 0;
                for (int t = 0; t < x; t++) {
                    temp=(max_table[y][y + t] <= min_table[y + t + 1][y + x])?ct_table[y][y + t] + ct_table[y + t + 1][y + x]:1;
                    if(temp>max)
                        max=temp;
                }
                ct_table[y][y + x] = max;
            }
        return ct_table[0][S-1];
    }
};
class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            if(arr.size()==1)
                return 1;

            int ct=0;int S=arr.size();
            int max_table[S]={0};
            int min_table[S]={0};
            max_table[0]=arr[0];
            min_table[S-1]=arr[S-1];
            for(int i=1;i<S;i++)
            {
                max_table[i]=max(max_table[i-1],arr[i]);
            }
            for(int i=S-2;i>=0;i--)
            {
                min_table[i]=min(min_table[i+1],arr[i]);
            }


            int cur_min=arr[0],cur_max=arr[0],cur_min_index=0,cur_max_index=0;
            for(int i=0;i<S;i++){
                if(i==S-1){
                    if(ct>=1){
                        if(arr[i]<cur_min){
                            cur_min=arr[i];
                        }
                        if(arr[i]>cur_max){
                            cur_max=arr[i];
                        }
                        if(cur_min>=min_table[cur_min_index-1>=0?cur_min_index-1:0])
                        {
                            ct++;
                        }
                        break;
                    }
                    else{
                        if(arr[i]>=max_table[i-1])
                            ct=2;
                        else
                            ct=1;
                        break;
                    }
                }
                else if(i==0){
                    if(cur_max<=min_table[cur_max_index+1])
                    {
                        ct++;
                        cur_min=cur_max=arr[i+1];
                        cur_min_index=cur_max_index=i+1;
                    }
                    continue;
                }


                cur_max_index=i;
                if(arr[i]<cur_min){
                    cur_min=arr[i];
                }
                if(arr[i]>cur_max){
                    cur_max=arr[i];
                }
                if(ct>=1){
                    if(cur_min>=max_table[cur_min_index-1>=0?cur_min_index-1:0]&&cur_max<=min_table[cur_max_index+1])
                    {
                        ct++;
                        cur_min=cur_max=arr[i+1];
                        cur_min_index=cur_max_index=i+1;
                    }
                }
                else{
                    if(cur_max<=min_table[cur_max_index+1])
                    {
                        ct++;
                        cur_min=cur_max=arr[i+1];
                        cur_min_index=cur_max_index=i+1;
                    }
                }
            }

            return ct;
        }
        int max (int a,int b)
        {
            return a>b?a:b;
        }
        int min (int a,int b)
        {
            return a<b?a:b;
        }
    };