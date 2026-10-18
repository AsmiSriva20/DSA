class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0, rightmax=0, l=0, r=height.size()-1;
        int water=0;
        while(l<r){
            if(height[l]>=height[r]){
                if(height[r]>rightmax) rightmax=height[r];
                else water+= rightmax-height[r];
                r--;
            }
            else{
                if(height[l]>leftmax) leftmax=height[l];
                else water+= leftmax-height[l]; l++;
            }
        }

       return water; 
    }
};