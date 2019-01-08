/*
题目：分发糖果 题号：135
这个很慢很慢 慢到我不想记录......有时间再看看有没有更快的办法。
*/
class Solution {
public:
    int candy(vector<int> &ratings)
    {
        return my_candy(ratings,false,0,ratings.size()-1);
    }
    int my_candy(vector<int> &ratings, bool iter, int low, int high) {
        int res = 0;
        int *height = new int[high-low+1];
        height[0] = 0;
        int cur_height = 0;
        int min = 0;
        int min_index = low;
        for (int i = low; i <= high; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cur_height++;
            } else if (ratings[i] < ratings[i - 1]) {
                cur_height--;
                if (cur_height < min) {
                    min = cur_height;
                    min_index = i;
                }
            }
            height[i-low] = cur_height;
        }
        for (int i = 0; i <= high-low; i++)
            height[i] -= min;
        //from min_index to right
        int r_i, cur_candy = 0;
        for (r_i = min_index + 1; r_i <= high && height[r_i - 1 -low] == 0; r_i++) {
            if (height[r_i-low] == 0) {
                continue;
            } else break;
        }
        //now height[r_i] is absolutely bigger than min
        for (; r_i <= high ; r_i++) {
            if (height[r_i-low] > height[r_i - 1-low]) {
                cur_candy++;
                res += cur_candy;
            }
            else {
                res += my_candy(ratings, true, r_i, high);
                break;
            }
        }
        int l_i;
        cur_candy = 0;
        for (l_i = min_index - 1; l_i >= low && height[l_i + 1 -low] == 0; l_i--) {
            if (height[l_i-low] == 0) {
                continue;
            } else break;
        }
        //now height[l_i] is positive
        for (; l_i >= low; l_i--) {
            if (height[l_i-low] > height[l_i + 1-low]) {
                cur_candy++;
                res += cur_candy;
            }
            else {
                res += my_candy(ratings, true, low, l_i);
                break;
            }
        }
        if (!iter)
            return res + ratings.size();
        else return res;
    }
};
