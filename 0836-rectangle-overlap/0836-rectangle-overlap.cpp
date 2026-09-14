class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int left = max(rect1[0], rect2[0]);
        int right = min(rect1[2],rect2[2]);

        int bottom = max(rect1[1] , rect2[1]);
        int top = min(rect1[3], rect2[3]);

        return left <right && bottom < top;
    }
};