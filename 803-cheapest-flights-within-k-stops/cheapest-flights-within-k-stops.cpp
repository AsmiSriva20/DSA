class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int from=it[0];
            int to_dest=it[1];
            int price=it[2];
            adj[from].push_back({to_dest,price});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
       vector<int>minprice(n,INT_MAX);
       int stops=0;
       while(!q.empty()&& stops<=k){
        int size=q.size();
        while(size--){
            auto curr=q.front();
            q.pop();
            int node=curr.first;
            int cost=curr.second;
            for(auto it: adj[node]){
                int nex_node=it.first;
                int new_cost=it.second+cost;
                if(new_cost<minprice[nex_node]){
                    minprice[nex_node]=new_cost;
                    q.push({nex_node,new_cost});
                }
            }

        }
        stops++;
       }
       return (minprice[dst]==INT_MAX)? -1: minprice[dst];
    }
};