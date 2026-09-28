class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int depth = 0;
        int max_depth = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                depth++;
                if(depth > max_depth) max_depth = depth;
            }
            else if(s[i] == ')') depth--;
        }
        return max_depth;
    }
};