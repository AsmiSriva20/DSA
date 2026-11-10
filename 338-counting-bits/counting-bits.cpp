class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>bits;
        for(int i=0;i<=n;i++){
           int count=0;
           for(int j=0;j<31;j++){
             int mask=1<<j;
             if(mask&i) count++;
           }
           bits.push_back(count);
        }

       return bits; 
    }
};