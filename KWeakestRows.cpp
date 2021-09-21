#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
struct solPosNIndex{
    int pos,index;
    solPosNIndex(int p,int i){
        pos = p;
        index = i;
    }
};
bool operator<(solPosNIndex s1, solPosNIndex s2){
    return s1.pos < s2.pos || (s1.pos == s2.pos && s1.index < s2.index);
}   

class Solution {
private:
    int findLastSoldierPos(vector<int> & row){
        if(row.size() == 1)
            return row[0] == 1;
        int low = 0;
        int high = row.size()-1;
        int mid = (low+high)/2;
        while(true){
            if(mid >= high){
                if(row[mid] == 1)
                    return mid;
                else
                    return mid-1;
            }
            if(row[mid] == 1 && row[mid+1] == 0){
                return mid;
            }
            else if(row[mid] == 1 && row[mid+1] == 1){
                low = mid+1;
                high = high;
                mid = (low+high)/2;
            }
            else if(row[mid] == 0 && row[mid+1] == 0){
                high = mid - 1;
                low = low;
                mid = (low+high)/2;
            }
        }
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<solPosNIndex,vector<solPosNIndex>> pq;
        int size = mat.size();
        for(int i = 0; i < size; i++){
            pq.push(solPosNIndex(findLastSoldierPos(mat[i]),i));
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().index);
            pq.pop();
        }
        return res; 
    }
};