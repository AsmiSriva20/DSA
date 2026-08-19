class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sumfront=0,sumback=0,maxsum=0;
        for(int i=0;i<k;i++){
            sumfront+=cardPoints[i];
        }
        maxsum=sumfront;
        int rightidx=n-1;
        for(int i= k-1;i>=0;i--){
            sumfront=sumfront-cardPoints[i];
            sumback+=cardPoints[rightidx];
            maxsum=max(maxsum,sumfront+sumback);
            rightidx--;
        }
        return maxsum;
    }
};