class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(const string &s : patterns){
            if(word.find(s) != -1){
                count++;
            }
        }
        return count;
    }
};