class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            int curr=asteroids[i];
            while(!st.empty() && st.top()>0 && curr<0 ){
                if(st.top()<-curr){
                    st.pop();
                }
                else if(st.top()==-curr){
                    st.pop();
                    curr=0;
                }
                else curr=0;
                
            }
            if(curr!=0){
                st.push(curr);
            }
        }
     while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

    reverse(ans.begin(), ans.end());
        return ans;
        
    }
};