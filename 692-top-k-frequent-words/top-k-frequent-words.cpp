class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        using x=pair<int,string>;
        auto lambda=[](pair<int,string> p1, pair<int,string>p2){
            if(p1.first==p2.first) return p1.second>p2.second;
            return p1.first<p2.first;
        };
        priority_queue<x,vector<x>,decltype(lambda)>pq;
        for(auto it:words){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});

        }
        vector<string>ans;
        for(int i=0;i<k;i++){
          ans.push_back(pq.top().second);
          pq.pop();
        }
      
      return ans;  
    }
};