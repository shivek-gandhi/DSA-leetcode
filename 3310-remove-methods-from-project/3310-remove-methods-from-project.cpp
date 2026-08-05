class Solution {
public:
    unordered_set<int> suspicious;

    void dfs(int node,vector<int> &visited, vector<vector<int>> &graph){
        suspicious.insert(node);
        visited[node] = 1;
        for(auto& neighbor : graph[node]){
            if(!visited[neighbor]){
                dfs(neighbor, visited,graph);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<unordered_set<int>> invoked_by(n);

        for(const auto& invocation : invocations){
            int u = invocation[0];
            int v = invocation[1];
            graph[u].push_back(v);
            invoked_by[v].insert(u);
        }

        vector<int> visited(n,0);
        dfs(k,visited,graph);

        bool canRemove = true;
        for(auto& method: suspicious){
            for(auto& invoker : invoked_by[method]){
                if(suspicious.find(invoker) == suspicious.end()){
                    canRemove = false;
                    break;
                }
            }
            if(!canRemove) break;
        }

        vector<int> result;
        if(canRemove){
            for(int i=0;i<n;++i){
                if(suspicious.find(i) == suspicious.end()){
                    result.push_back(i);
                }
            }
        }
        else{
            for(int i=0;i<n;++i){
                result.push_back(i);
            }
        }
        return result;
    }
};