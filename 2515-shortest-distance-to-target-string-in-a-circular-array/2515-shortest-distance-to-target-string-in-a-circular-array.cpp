class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for (int step = 0; step < n; step++) {
            int r = (startIndex + step) % n;
            int l = (startIndex - step + n) % n;

            if (words[r] == target || words[l] == target) {
                return step;
            }
        }
        return -1;
    }
};