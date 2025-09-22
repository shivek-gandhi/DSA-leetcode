class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        int n=nums.size();
        for (int i=0;i<n;i++) {
            count[nums[i]]++;
        }
        
        int maxFreq = 0;
        for (auto &p : count) {
            maxFreq = max(maxFreq, p.second);
        }
        
        int result = 0;
        for (auto &p : count) {
            if (p.second == maxFreq) {
                result += p.second; 
            }
        }
        
        return result;
    }
};