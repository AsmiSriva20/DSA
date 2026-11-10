class Solution {
public:
    bool isPowerOfTwo(int n) {
        int mask=1;
        for(int i=0;i<31;i++){
            mask=1<<i;
            if(mask==n) return true;
        }
        return false;
    }
};