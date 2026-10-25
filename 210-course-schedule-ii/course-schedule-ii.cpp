class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
          graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
          indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:graph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
       return ans.size()==numCourses ?ans: vector<int>{}; 
    }
};