#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
class Solution {
private:
    static inline int INDEX(int n){
        return n-1;
    }
public:
    double _frogPos(int currentVertex, int targetVertex, vector<vector<int>> & edgeMatrix, 
            vector<int> & visitedVertices, double prob,int timeLeft){
        if(timeLeft == 0){
            if(currentVertex == targetVertex)
                return prob;
            else
                return 0.0;
        }
        visitedVertices[currentVertex] = 1;
        int size = edgeMatrix.size();
        int potents = 0;
        for(int i = 0; i < size; i++){
            if(i != currentVertex && visitedVertices[i] == 0 && edgeMatrix[currentVertex][i]){
                potents++;
            }
        }
        // 无路可去的情况
        if(potents == 0){
            visitedVertices[currentVertex] = 0;
            return _frogPos(currentVertex,targetVertex,edgeMatrix,visitedVertices,prob,0);
        }


        double res = 0.0;
        for(int i = 0; i < size; i++){
            if(i != currentVertex && visitedVertices[i] == 0 && edgeMatrix[currentVertex][i]){
                res += _frogPos(i, targetVertex, edgeMatrix, visitedVertices, prob/potents, timeLeft - 1);
            }
        }
        visitedVertices[currentVertex] = 0;
        return res;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> edgeMatrix;
        for(int i = 0; i < n; i++){
            edgeMatrix.push_back(vector<int>(n,0));
        }
        int size = edges.size();
        for(int i = 0; i < size; i++){
            int a = INDEX(edges[i][0]), b = INDEX(edges[i][1]);
            edgeMatrix[a][b] = edgeMatrix[b][a] = 1;
        }
        // 1 visited 0 not visited
        vector<int> visitedVertices(n,0);
        visitedVertices[INDEX(1)] = 1;
        return _frogPos(INDEX(1),INDEX(target),edgeMatrix,visitedVertices,1.0,t);
        
    }
};