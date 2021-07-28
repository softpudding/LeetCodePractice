#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Brick{
public:
    // row number: xth row
    int x;
    // column number: yth col
    int y;
    int h;
    Brick(int xx, int yy, int hh){
        this->x = xx;
        this->y = yy;
        this->h = hh;
    }
    bool operator<(const Brick & b) const{
        return h > b.h;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // deal with each row first
        int columnSize = heightMap.size();
        int rowSize = heightMap[0].size();
        int res = 0;
        int ops[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        if(columnSize <= 2 || rowSize <= 2)
            return 0;
        priority_queue<Brick> minHeap;
        vector<vector<int>> visited(columnSize,vector<int>(rowSize,0));
        // the external bricks
        for(int i = 0; i < rowSize; i++){
            minHeap.push(Brick(0,i,heightMap[0][i]));
            minHeap.push(Brick(columnSize-1,i,heightMap[columnSize-1][i]));
            visited[0][i] = visited[columnSize-1][i] = 1;
        }
        for(int i = 1; i < columnSize - 1; i++){
            minHeap.push(Brick(i,0,heightMap[i][0]));
            minHeap.push(Brick(i,rowSize-1,heightMap[i][rowSize-1]));
            visited[i][0] = visited[i][rowSize-1] = 1;
        }
        int remaining = columnSize*rowSize - columnSize*2 - rowSize*2 + 4;
        while(remaining > 0){
            Brick top = minHeap.top();
            minHeap.pop();
            int x = top.x;
            int y = top.y;
            int h = top.h;
            // 4 directions
            for(int a = 0; a < 4; a++){
                int newX = x + ops[a][0];
                int newY = y + ops[a][1];
                if(newX >= 0 && newX < columnSize -1 && newY >= 0 && newY < rowSize - 1 && visited[newX][newY] == 0){
                    visited[newX][newY] = 1;
                    remaining--;
                    if(heightMap[newX][newY] > h){
                        minHeap.push(Brick(newX,newY,heightMap[newX][newY]));
                    }
                    else{
                        res += h - heightMap[newX][newY];
                        minHeap.push(Brick(newX,newY,h));
                    }
                }
            }

        }
        return res;
    

        
    }
};