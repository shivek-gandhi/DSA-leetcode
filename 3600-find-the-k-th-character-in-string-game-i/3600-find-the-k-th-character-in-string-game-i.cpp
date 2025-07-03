class Solution {
public:
    char getChar(int k, int depth) {
    if (k == 1)
        return 'a';
    
    int mid = 1 << (depth - 1);
    
    if (k <= mid)
        return getChar(k, depth - 1);
    else {
        char prevChar = getChar(k - mid, depth - 1);
        
        return (prevChar == 'z') ? 'a' : (prevChar + 1);
    }
}
    char kthCharacter(int k) {
        int depth = 0;
    while ((1 << depth) < k)
        depth++;
    
    return getChar(k, depth);
    }
};