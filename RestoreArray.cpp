#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size()+1;
        vector<vector<int>> graphMatrix;
        vector<int> uniqueNumbers;
        for(int i = 0; i < n; i++){
            graphMatrix.push_back(vector<int>(n,0));
        }
        vector<int> degrees(n,0);
        for(int i = 0; i < n; i++){
            int first = adjacentPairs[i][0], second = adjacentPairs[i][1];
            graphMatrix[first][second] = adjacentPairs[second][first] = 1;
            degrees[first]++;
            degrees[second]++;
        }
        int starter = 0;
        for(int i = 0; i < n; i++){
            if(degrees[i] == 1){
                starter = i;
                break;
            }
        }
        vector<int> res;
    
    }
};