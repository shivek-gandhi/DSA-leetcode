class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> freq(10001,0);
        for(int i=0;i< nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};