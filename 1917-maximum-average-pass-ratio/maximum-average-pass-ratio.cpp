class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& class1, int ex) {
        int n = class1.size();
        priority_queue<pair<double,int>> pq;
        double ans=0;
        for(int i=0;i<n;i++){
            if(class1[i][0]!=class1[i][1]){
            double r1 = double(class1[i][0])/double(class1[i][1]);
            double r2 = double(class1[i][0]+1)/double(class1[i][1]+1);
            double diff = r2-r1;
            pq.push({diff,i});
            }else{ans++;}
        }
        while(!pq.empty() && ex>0){
            pair<double,int> k = pq.top();pq.pop();
            int i = k.second;
            class1[i][0]++;class1[i][1]++;
            double r1 = double(class1[i][0])/double(class1[i][1]);
            double r2 = double(class1[i][0]+1)/double(class1[i][1]+1);
            double diff = r2-r1;
            ex--;
            pq.push({diff,i});
        }
        for(int i =0;i<n;i++){
             if(class1[i][0]!=class1[i][1]){
            double r = double(class1[i][0])/double(class1[i][1]);
            ans+=r;
             }
        }
        return double(ans/n);
    }
};