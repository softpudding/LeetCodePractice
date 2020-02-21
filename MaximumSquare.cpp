/*
 * 题目：最大正方形 题号：221 16ms 90%
 * 我的方法不好 更好的应该是用动态规划来做
 */
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        vector<vector<char> > possibleHeads;
        if(matrix.size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            vector<char> * current = new vector<char>(cols,1);
            possibleHeads.push_back(*current);
        }
        int maxSquare = 0;
        int currentSquare = 0;
        bool keepFinding = true;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(possibleHeads[i][j] && matrix[i][j] == '1'){
                    currentSquare = 0;
                    while(keepFinding){
                        if(i + maxSquare >= rows || j + maxSquare >= cols)
                            break;
                        int x = i, y = j + currentSquare;
                        for(;x <= i + currentSquare;x++){
                            if(matrix[x][y] == '0') {
                                keepFinding = false;
                                int a = x - maxSquare + 1 > i ? x - maxSquare + 1: i;
                                int b = y - maxSquare + 1 > j ? y - maxSquare + 1: j;
                                for(int m = a; m <= x; m++){
                                    for(int n = b; n <=y; n++){
                                        possibleHeads[m][n] = 0;
                                    }
                                }
                            }
                        }
                        x--;
                        for(;y >= j; y--){
                            if(matrix[x][y] == '0') {
                                keepFinding = false;
                                int a = x - maxSquare + 1 > i ? x - maxSquare + 1: i;
                                int b = y - maxSquare + 1 > j ? y - maxSquare + 1: j;
                                for(int m = a; m <= x; m++){
                                    for(int n = b; n <=y; n++){
                                        possibleHeads[m][n] = 0;
                                    }
                                }
                            }
                        }
                        // which is definetely true
                        if(keepFinding){
                            currentSquare++;
                            maxSquare = maxSquare < currentSquare ? currentSquare : maxSquare;
                        }
                    }
                    keepFinding = true;
                }
            }
        }
        return maxSquare*maxSquare;
    }
};