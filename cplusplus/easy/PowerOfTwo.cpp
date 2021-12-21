class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){ return false; }
        return (n == (1 << (int)floor(log2(n))));
    }
};

// Other Better Solution
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};
*/