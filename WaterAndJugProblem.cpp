/*
题目：水壶问题 题号：365 0ms 100%
前两天刚刚好在学算法有关数字的部分，做这么一道题蛮好的。
这个题目还是蛮锻炼读题能力的，他给出的是z水壶可以用x，y水壶的容量以及
通过“从一个水壶向另外一个水壶倒水，直到装满或者倒空”这种方式装满。当然
最后一种情况暗示了除去x，y之外另一种可能，那就是ax+by，这里ab正负必然
一正一负。如果你也学过数论，你就会知道如果c=ax+by,那么c就是x,y的最大
公约数。只要用Euclid的做法做出最大公约数就可以了，跑得飞快。
*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y)
            return false;
        if(!x&&!y){
            if(!z)
                return true;
            else return false;
        } 
        if(!x)
            return !(z%y);
        if(!y)
            return !(z%x);
    
        return !(z%Euclid(x,y));
        
    }
    int Euclid(int a,int b){
        if(!b)
            return a;
        if(a>b){
            return Euclid(b,a%b);
        }
        else
            return Euclid(a,b%a);
    }
};