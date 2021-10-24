class Solution {
public:
    int dfs(vector<vector<int>> & dp, vector<int> & slices, int start, int n, int right){
        //cout<<"dfs:"<<start<<" "<<n<<endl;
        if(start >= slices.size()){
            //cout<<"res: NULL"<<endl;
            return 0;
        }
        if(n == 1){
            //cout<<"res:"<<slices[start]<<endl;
            return slices[start];
        }
        if(dp[start][n] != 0){
            //cout<<"res:"<<dp[start][n]<<endl;
            return dp[start][n];
        }
        int v = slices[start];
        int max = 0;
        for(int i = start+2; i <= right-(2*n-3); i++){
            int ret = dfs(dp,slices,i,n-1,right);
            if(ret + v > max){
                max = ret+v;
            }
        }
        dp[start][n] = max;
        //cout<<"res:"<<max<<endl;
        return max;
    }
    int maxSizeSlices(vector<int>& slices) {
        // 3n = size
        int size = slices.size();
        int n = size/3;
        // dp[x][n]表示
        // 在slices数组(x...3n-1)的范围中选取n片披萨，并且必须选取x作为第一块的最大值
        vector<vector<int>> dp(size,vector<int>(n+1,0));
        dp[size-1][1] = slices[size-1];
        dp[size-2][1] = slices[size-2];
        // 记忆化搜索
        int max = 0;

        for(int i = 0; i <= n+1; i++){
            int ret = i == 0? dfs(dp,slices,i,n,slices.size()-1) : dfs(dp,slices,i,n,slices.size());
            if(i == 0){
                for(int j = 0; j < size; j++)
                    dp[j].assign(n+1,0);
            }
            if(ret > max){
                max = ret;
            }
        }
        return max;
    }
};