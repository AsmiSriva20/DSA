class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailOwner;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailOwner.find(email) == emailOwner.end()) {
                    emailOwner[email] = i;
                }
                else {
                    unionBySize(i, emailOwner[email]);
                }
            }
        }     
        vector<vector<string>> merged(n);

        for (auto& [email, owner] : emailOwner) {
            int parentAccount = find(owner);
            merged[parentAccount].push_back(email);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i].empty())
                continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> account;
            account.push_back(accounts[i][0]);

            for (auto email : merged[i])
                account.push_back(email);

            ans.push_back(account);
        }

        return ans;
    }
};