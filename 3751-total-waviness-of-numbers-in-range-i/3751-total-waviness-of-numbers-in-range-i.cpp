class Solution {
public:

    int waviness(int num){
        string s = to_string(num);
        int count =0;
        for(int i=1;i<(int)s.size()-1;i++){
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])){
                count++;
            }
        }
        return count;
    }
    
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            ans += waviness(i);
        }
        return ans;
    }
};