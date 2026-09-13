class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;
        ones1.reserve(n * n);
        ones2.reserve(n * n);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) ones1.emplace_back(i, j);
                if (img2[i][j]) ones2.emplace_back(i, j);
            }
        
        int size = 2 * n - 1;
        vector<int> count(size * size, 0);
        int best = 0;
        
        for (auto& [x1, y1] : ones1) {
            for (auto& [x2, y2] : ones2) {
                int dx = x2 - x1 + n - 1;
                int dy = y2 - y1 + n - 1;
                int idx = dx * size + dy;
                int c = ++count[idx];
                if (c > best) best = c;
            }
        }
        
        return best;
    }
};