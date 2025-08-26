class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int Area = 0, maxDiag = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int currDiag = l * l + w * w;

            if (currDiag > maxDiag || (currDiag == maxDiag && l * w > Area)) {
                maxDiag = currDiag;
                Area = l * w;
            }
        }
        return Area;
    }
};