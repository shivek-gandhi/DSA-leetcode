class Solution {
public:
    typedef long long ll;
    ll sumAndMultiply(int n) {
        ll ans = 0;
        ll sum = 0;
        ll multiplier = 1;
        while(n>0){
            if(n%10 == 0){
                while(n%10 == 0) n=n/10;
            }
            sum += n%10;
            ans += (n%10)*multiplier;
            multiplier *=10;
            n /= 10;
        }
        return ans*sum;
    }
};