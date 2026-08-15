class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        int len = nums.size();
        bool nonZero = false;
        for(int i=0;i<len;i++){
            nonZero |= (nums[i] > 0);
            total ^= nums[i];
        }

        if(total != 0) return len;
        if(nonZero) return len-1;
        return 0;
    }
};