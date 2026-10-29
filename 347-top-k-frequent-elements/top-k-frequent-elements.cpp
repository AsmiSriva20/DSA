class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
           mpp[it]++;
        }
        using P=pair<int,int>;
        priority_queue<P>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};