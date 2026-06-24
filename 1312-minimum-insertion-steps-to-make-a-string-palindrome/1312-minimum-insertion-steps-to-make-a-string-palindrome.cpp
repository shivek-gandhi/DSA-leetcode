class Solution {
public:
    int lcs(string s,string t){
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = 0;
        
        for(int i=1;i<=n;i++){
            vector<int> cur(m+1,0);
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};