class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i = 0;
        long long m = mass;
        while(i<asteroids.size()){
            if(m >= asteroids[i]){
                m += asteroids[i];
            }
            else{
                return false;
            }
            i++;
        }
        return true;
    }
};