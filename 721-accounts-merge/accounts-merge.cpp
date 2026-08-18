class Solution {
public:
    void dfs(string email, unordered_map<string, vector<string>>& graph,
             unordered_set<string>& visited, vector<string>& emails) {
      visited.insert(email);
      emails.push_back(email);

        for (auto next : graph[email]) {
            if (!visited.count(next)) {
                dfs(next, graph, visited, emails);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> name;
        for (auto account : accounts) {
            string firstEmail = account[1];
            name[firstEmail] = account[0];
            for (int i = 2; i < account.size(); i++) {
                name[account[i]] = account[0];
                graph[firstEmail].push_back(account[i]);
                graph[account[i]].push_back(firstEmail);
            }
        }

        vector<vector<string>> ans;
        unordered_set<string> visited;
        for (auto& [email, person] : name) {

            if (visited.count(email))
                continue;
            vector<string> emails;
            dfs(email, graph, visited, emails);
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(person);
            for (auto e : emails)
                account.push_back(e);

            ans.push_back(account);
        }

        return ans;
    }
};