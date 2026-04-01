class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(robots.begin(), robots.end()); // sort by position
        
        stack<int> st; // stores indices of robots in 'robots' vector
        
        for(int i = 0; i < n; i++){
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R'){
                st.push(i);
            } else {
                // moving left
                while(!st.empty() && health > 0){
                    auto &[pos2, health2, dir2, idx2] = robots[st.top()];
                    
                    if(health2 < health){
                        st.pop();
                        health -= 1;
                        health2 = 0;
                    }
                    else if(health2 == health){
                        st.pop();
                        health = 0;
                        health2 = 0;
                        break;
                    }
                    else {
                        health2 -= 1;
                        health = 0;
                        break;
                    }
                }
            }
        }
        
        vector<pair<int,int>> survivors;
        
        for(int i = 0; i < n; i++){
            auto &[pos, health, dir, idx] = robots[i];
            if(health > 0){
                survivors.push_back({idx, health});
            }
        }
        
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for(auto &p : survivors){
            result.push_back(p.second);
        }
        
        return result;
    }
};