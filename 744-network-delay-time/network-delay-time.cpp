class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it: times){
            int u = it[0];
            int v=it[1];
            int tt=it[2];//time taken hai yeh
            adj[u].push_back({v,tt});
        }
        vector<int>dist(n+1,INT_MAX);
        using P=pair<int,int>;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int d=curr.first;
            int node=curr.second;
            for(auto it: adj[node]){
                int next_node=it.first;
                int timet=it.second;
                int new_distance=d+timet;
                if(new_distance<dist[next_node]){
                    dist[next_node]=new_distance;
                    pq.push({new_distance,next_node});
                }

            }
        }
        return (*max_element(dist.begin()+1, dist.end())==INT_MAX)? -1: *max_element(dist.begin()+1, dist.end());
        
    }
};