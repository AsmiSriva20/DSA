class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int source= times[i][0];
            int destination=times[i][1];
            int timetaken=times[i][2];
            adj[source].push_back({destination,timetaken});
        }
        using P= pair<int,int>;
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int t=curr.first;
            int node=curr.second;
            for(auto it:adj[node]){
                int new_time=t+ it.second;
                int next_node= it.first;
                if(new_time<time[next_node]){ time[next_node]=new_time;
                pq.push({new_time,next_node});
                }

            }
            

        }

    for(int i=1;i<time.size();i++){
        if(time[i]==INT_MAX) return -1;
    }
     return *max_element(time.begin()+1,time.end());  
    }
};