class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1,0});
        r.push_back({n,n-1});
        sort(r.begin(), r.end());

        for(int i = 1; i < r.size(); i++)
            r[i][1] = min(r[i][1], r[i-1][1] + r[i][0] - r[i-1][0]);

        for(int i = r.size()-2; i >= 0; i--)
            r[i][1] = min(r[i][1], r[i+1][1] + r[i+1][0] - r[i][0]);

        int ans = 0;
        for(int i = 0; i + 1 < r.size(); i++) {
            int d = r[i+1][0] - r[i][0];
            ans = max(ans, (r[i][1] + r[i+1][1] + d) / 2);
        }

        return ans;
    }
};