class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '\0');

        char c = 'a';

        // Step 1: Construct string
        for (int i = 0; i < n; i++) {
            if (s[i] != '\0') continue;

            if (c > 'z') return "";

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = c;
                }
            }
            c++;
        }

        // If any position unfilled → invalid
        for (char ch : s) {
            if (ch == '\0') return "";
        }

        // Step 2: Validate
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    int expected = 1;
                    if (i + 1 < n && j + 1 < n)
                        expected += lcp[i + 1][j + 1];

                    if (lcp[i][j] != expected)
                        return "";
                } else {
                    if (lcp[i][j] != 0)
                        return "";
                }
            }
        }

        return s;
    }
};