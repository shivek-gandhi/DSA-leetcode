class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n= colors.size();
        // int i = 0;
        // int j = n-1;
        int maxi = 0;
        // while(i<j){
        //     if(colors[i] != colors[j]){
        //         maxi = max(maxi, abs(j-i));
        //         j--;
        //     }
        //     else i++;
        // }
        for(int i=n-1;i>=0;i--){
            if(colors[i] != colors[0]){
                maxi = max(maxi, i);
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(colors[i] != colors[n - 1]){
                maxi = max(maxi,n-i-1);
                break;
            }
        }
        return maxi;
    }
};