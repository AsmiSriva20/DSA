class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int left=0;
        int right=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            sum=sum+cardPoints[i];
        }
        int ans=sum;
        for(int i=1;i<=k;i++){
            sum=sum-cardPoints[k-i];
            sum=sum+cardPoints[cardPoints.size()-i];
            ans=max(ans,sum);

        }
        return ans;
    }
};