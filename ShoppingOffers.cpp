class Solution {
private:
    // 输入是一个大礼包的vector(n+1个元素) 只考虑前n个元素
    inline int getDPIndex(vector<int> v){
        int f = 1;
        int size = v.size() - 1;
        int res = 0;
        for(int i = 0; i < size; i++){
            res += v[i]*f;
            f *= 11;
        }
        return res;
    }
    void displayNeed(vector<int> & v){
        cout<<"current need:";
        for(int i = 0; i < v.size() - 1; i++){
            cout<<v[i]<<' ';
        }
        cout << endl;
    }
    int dfs(vector<int> & dp, vector<vector<int>> & avaiSpecials,vector<int> currentNeed, vector<int> & price){
        //displayNeed(currentNeed);
        int ret = dp[getDPIndex(currentNeed)];
        // 记忆化搜索，判断之前有没有处理过这个数据
        if(ret != 0){
            //cout<<"ret:"<<ret<<endl;
            return ret; 
        }
        // 根据大礼包来搜索
        int specialSize = avaiSpecials.size();
        int min = 0;
        int n = price.size();
        for(int i = 0; i < n; i++){
            min += price[i]*currentNeed[i];
        }
        bool valid = true;
        for(int i = 0; i < specialSize; i++){
            // 检查一下 当前这个currentNeed里面各项物品数量均大于等于这个大礼包的数量
            for(int j = 0; j < n; j++){
                if(avaiSpecials[i][j] <= currentNeed[j]){
                    continue;
                }
                else{
                    valid = false;
                    break;
                }
            }
            if(!valid){
                valid = true;
                continue;
            }
            // 进行下一步搜索
            vector<int> newCurrentNeed(currentNeed);
            for(int j = 0; j < n; j++)
                newCurrentNeed[j] -= avaiSpecials[i][j];
            ret = dfs(dp,avaiSpecials,newCurrentNeed,price) + avaiSpecials[i][n];
            if(ret < min){
                min = ret;
            }
        }
        dp[getDPIndex(currentNeed)] = min;
        //cout<<"ret:"<<min<<endl;
        return min;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 过滤掉没有意义的大礼包
        vector<vector<int>> filteredSpecial;
        int specialSize = special.size();
        int n = price.size();
        for(int i = 0; i < specialSize; i++){
            vector<int> & currentSpecial = special[i];
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += currentSpecial[j]*price[j];
            }
            if(sum >= currentSpecial[n]){
                filteredSpecial.push_back(currentSpecial);
            }
        }
        // 动态规划
        // 因为最多6种物品 每种物品的数量最多10个 所以可以用十一进制数来表示对每种物品的需求
        vector<int> dp(1771560,0);

        vector<int> currentNeed(n+1,0);
        // 先把单独购买每个物品的基础情况写出来
        for(int i = 0; i < n; i++){
            currentNeed[i] = 1;
            dp[getDPIndex(currentNeed)] = price[i];
            currentNeed[i] = 0;
        }
        // 大礼包的情况
        specialSize = filteredSpecial.size();
        for(int i = 0; i < specialSize; i++){
            dp[getDPIndex(filteredSpecial[i])] = filteredSpecial[i][n];
        }
        
        for(int i = 0; i < n; i++){
            currentNeed[i] = needs[i];
        }
        // 记忆化搜索
        dp[getDPIndex(currentNeed)] = 0;
        return dfs(dp,filteredSpecial,currentNeed,price);
    }
};