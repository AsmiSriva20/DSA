class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P=pair<double,int>;
        priority_queue<P,vector<P>,greater<P>>heap;int i=0;
        for(auto it:points){
            double dist= it[0]*it[0]+it[1]*it[1];
            heap.push({dist,i});
            i++;
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            int kk=heap.top().second;
            ans.push_back({points[kk][0],points[kk][1]});
            heap.pop();
        } return ans;
    }
};