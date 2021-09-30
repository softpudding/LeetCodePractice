class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if(ax1 == ax2 || ay1 == ay2){
            return (bx2-bx1)*(by2-by1);
        }
        if(bx1 == bx2 || by1 == by2){
            return (ax2-ax1)*(ay2-ay1);
        }
        if(ax2 < bx1 || bx2 < ax1 || ay2 < by1 || by2 < ay1){
            return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        }
        int overlapLeft = max(ax1,bx1);
        int overlapRight = min(ax2,bx2);
        int overlapTop = min(by2,ay2);
        int overlapBottom = max(ay1,by1);
        //int width = bx2 > ax2 ? ax2 - bx1 : bx2 - ax1;
        //int height = by2 > ay2 ? ay2 - by1 : by2 - ay1;
        int width = overlapRight - overlapLeft;
        int height = overlapTop - overlapBottom;
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - width*height;
    }
};