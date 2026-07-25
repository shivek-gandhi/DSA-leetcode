class Solution {
public:
    int maxProduct(int n) {
        int first = -1,second = -1;
        while(n!=0){
            int rem = n%10;
            if(first <= rem){
                second = first;
                first = rem;
            }
            else if(second < rem){
                second = rem;
            }
            n = n/10;
        }

        return first * second;
    }
};