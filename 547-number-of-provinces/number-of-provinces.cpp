class dsu{
    vector<int> parent,size;
    public:
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node]= findUParent(parent[node]);
    }
    void unionbys(int n, int m){
        int u_n=findUParent(n);
        int u_m=findUParent(m);
        if(u_n==u_m) return;
        if(size[u_n]<size[u_m]){
            parent[u_n]=u_m;
            size[u_m]+=size[u_n];
        }
        else if(size[u_m]<size[u_n]){
            parent[u_m]=u_n;
            size[u_n]+=size[u_m];
        }
        else{
            parent[u_m]=u_n;
            size[u_n]+=size[u_m];
        }
       
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        dsu ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j])
                ds.unionbys(i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUParent(i)==i) cnt++;
        }
        return cnt;
    }
};