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
        using P= pair<int,pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{src,0}});

        vector<vector<int>> minprice(n, vector<int>(k + 2, INT_MAX));
        minprice[src][0] = 0;


        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int price=curr.first;
            int node=curr.second.first;
            int stops=curr.second.second;
            if(node==dst) return price;
            if(stops>k) continue;

            for(auto it: adj[node]){
                int next_node=it.first;
                int new_price=it.second+price;
                int new_stops=stops+1;
                if(new_price < minprice[next_node][new_stops]) {
                     minprice[next_node][new_stops] = new_price;
                    pq.push({new_price, {next_node, new_stops}});
                }
            }
        }

      return -1;
    }
};