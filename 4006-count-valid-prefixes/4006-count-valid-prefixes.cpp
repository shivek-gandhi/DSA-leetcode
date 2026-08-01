class Solution {
public:
    int countValidPrefixes(string s) {
        int result = 0;
        int diff = 0;
        for(auto c: s){
            diff += c=='1' ? 1 : -1;
            result += abs(diff) <= 1;
        }
        return result;
    }
};