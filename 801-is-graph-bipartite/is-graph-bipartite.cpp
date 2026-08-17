class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int startcolor,
             vector<int>& colour, int currnode) {

        colour[currnode] = startcolor;

        for (auto nextnode : graph[currnode]) {

            if (colour[nextnode] == -1) {
                if (!dfs(graph, 1 - startcolor, colour, nextnode))
                    return false;
            }
            else if (colour[currnode] == colour[nextnode]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (colour[i] == -1) {
                if (!dfs(graph, 0, colour, i))
                    return false;
            }
        }

        return true;
    }
};