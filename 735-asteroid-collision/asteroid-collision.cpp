class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            int asteroid = asteroids[i];

            while (!st.empty() && st.top() > 0 && asteroid < 0) {

                if (st.top() < -asteroid) {
                    st.pop();
                }
                else if (st.top() == -asteroid) {
                    st.pop();
                    asteroid = 0;
                }
                else {
                    asteroid = 0;
                }
            }

            if (asteroid != 0) {
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};