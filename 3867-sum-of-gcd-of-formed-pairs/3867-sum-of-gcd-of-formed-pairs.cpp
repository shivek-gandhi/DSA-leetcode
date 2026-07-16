class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        vector<ll> prefixGCD;
        ll  mx = 0;
        for(int i=0;i<nums.size();i++){
            // long long mx = *max_element(nums.begin(), nums.begin()+i);
            mx = max(mx,(ll)nums[i]);
            prefixGCD.push_back(gcd((ll)nums[i],mx));
        }
        int n = prefixGCD.size();
        sort(prefixGCD.begin(), prefixGCD.end());
        int left = 0;
        int right = n-1;
        long long count = 0;
        while(left<right){
            count += gcd(prefixGCD[left],prefixGCD[right]);
            left++;
            right--;
        }
        return count;   
    }
};