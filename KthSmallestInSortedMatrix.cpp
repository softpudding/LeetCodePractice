class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> unsortedCands;
        if(k <= n){
            for(int i = 0; i < k; i++){
                int r = k-i;
                for(int j = 0; j < r; j++){
                    unsortedCands.push_back(matrix[i][j]);
                }
            }
        }
        else if(k <= 2*n){
            for(int i = 0; i < k-n; i++){
                for(int j = 0; j < n; j++){
                    unsortedCands.push_back(matrix[i][j]);
                }
            }
            for(int i = n - 1; i >= k- n; i--){
                int r = n - (i - (k - n));
                for(int j = 0; j < r; j++){
                    unsortedCands.push_back(matrix[i][j]);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    unsortedCands.push_back(matrix[i][j]);
                }
            }
        }
        sort(unsortedCands.begin(),unsortedCands.end());
        return unsortedCands[k-1];
    }
};