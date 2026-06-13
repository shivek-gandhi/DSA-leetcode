class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        int wt = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                wt = wt + weights[words[i][j]-'a'];
                
            }
            wt = wt % 26;
            char ch = 'a' + (25 - wt);
            ans.push_back(ch);
            wt=0;
        }
        return ans;
    }
};