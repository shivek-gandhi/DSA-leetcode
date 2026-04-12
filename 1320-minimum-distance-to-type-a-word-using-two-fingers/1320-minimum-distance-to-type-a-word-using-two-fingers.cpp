class Solution {
public:

    int dist(char a, char b) {
        int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
        int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        
        int total = 0;
        for(int i = 1; i < n; i++) {
            total += dist(word[i-1], word[i]);
        }
        
        // max saving using second finger
        vector<int> best(26, 0);
        int maxGain = 0;
        
        for(int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i-1] - 'A';
            
            for(int c = 0; c < 26; c++) {
                best[prev] = max(best[prev],
                                 best[c] + dist(word[i-1], word[i]) - dist(char('A'+c), word[i]));
            }
            
            maxGain = max(maxGain, best[prev]);
        }
        
        return total - maxGain;
    }
};