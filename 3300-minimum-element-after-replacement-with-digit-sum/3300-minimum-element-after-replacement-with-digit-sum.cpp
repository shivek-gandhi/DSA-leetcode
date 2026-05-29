class Solution {
public:
    int minElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int a=0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            // a = a+ num %10;
            // num = num /10;
            while(num != 0){
                a += num %10;
                num = num/10;
            }
            nums[i] = a;
            a = 0;
        }
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};