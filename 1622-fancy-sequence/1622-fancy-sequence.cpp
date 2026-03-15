class Fancy {
public:
    const long MOD = 1e9+7;
    vector<long> arr;
    long a = 1, b = 0;

    long modPow(long x, long n){
        long res = 1;
        while(n){
            if(n&1) res = res*x % MOD;
            x = x*x % MOD;
            n >>= 1;
        }
        return res;
    }

    void append(int val) {
        long inv = modPow(a, MOD-2);
        long x = ((val - b) % MOD + MOD) % MOD;
        x = x * inv % MOD;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        b = (b + inc) % MOD;
    }
    
    void multAll(int m) {
        a = a * m % MOD;
        b = b * m % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * a % MOD + b) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */