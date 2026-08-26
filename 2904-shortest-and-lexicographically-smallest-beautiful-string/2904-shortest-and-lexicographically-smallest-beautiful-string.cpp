class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        int ones = 0;
        string ans = "";

        for(int right = 0;right < n;right++){
            if(s[right] == '1') ones++;

            while(ones > k){
                if(s[left] == '1') ones--; 
                left++;
            }

            if(ones == k){
                while(left < right && s[left]=='0') left++; //remove leading zero

                string cur = s.substr(left,right-left+1);

                if(ans =="" || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)){
                    ans = cur;
                }
            }

        }
        cout<<ans;
        return ans;
    }
};