class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis,
             int& vertices, int& degreeSum) {

        vis[node] = true;

        vertices++;

        degreeSum += graph[node].size();

        for (int next : graph[node]) {
            if (!vis[next]) {
                dfs(next, graph, vis, vertices, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        int answer = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i]) continue;

            int vertices = 0;
            int degreeSum = 0;

            dfs(i, graph, vis, vertices, degreeSum);

            int edgeCount = degreeSum / 2;

            if (edgeCount == vertices * (vertices - 1) / 2) {
                answer++;
            }
        }

        return answer;
    }
};