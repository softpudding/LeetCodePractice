class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int i = 0;
        int w = 0;
        for(i = 1; i*i <= area; i++){
            if(area % i == 0)
                w = i;
        }
        res.push_back(area/w);
        res.push_back(w);
        return res;
    }
};