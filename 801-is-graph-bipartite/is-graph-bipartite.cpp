class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);  colour[0]=0;
        queue<int>q;
        for(int i=0;i<n;i++){
        q.push(i);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto it: graph[curr]){
                if(colour[it]==-1){
                    colour[it]=1-colour[curr];
                    q.push(it);
                }
                else if(colour[it]==colour[curr]) return false;
            }
        }
        }
        return true;
    }
};