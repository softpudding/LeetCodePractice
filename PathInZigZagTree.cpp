class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int rowNum = 0;
        int n = label;
        while(n){
            rowNum++;
            n = n>>1;
        }
        vector<int> res;
        if(rowNum%2)
            n = label;
        else{
            int min = 1<<(rowNum-1);
            int max = (1<<rowNum) - 1;
            int realPos = min + (max - label);
            n = realPos;
        }
            
        for(int r = 1; r <= rowNum; r++){
            int min = 1<<(r-1);
            int max = (1<<(r)) - 1;
            int pos = (n >> (rowNum - r));
            int val = 0;
            if(r%2){
                val = pos;
            }
            else{
                val = max - (pos - min);
            }
            res.push_back(val);
        }
        return res;
    }
};