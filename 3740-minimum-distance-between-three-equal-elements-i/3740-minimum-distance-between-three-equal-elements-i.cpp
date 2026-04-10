class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int best = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    bool good = nums[i] == nums[j] && nums[j] == nums[k];

                    if (good) {
                        best = min(best, (abs(i-j)+abs(j-k)+abs(k-i)));
                    }
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};