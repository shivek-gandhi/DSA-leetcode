class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        if(n<= 999) return 0;
        ll comma = 0;
        ll start = 1000;
        while(start <= n){
            comma += n - start + 1;
            start *= 1000;
        }
        
        return comma;
    }
};