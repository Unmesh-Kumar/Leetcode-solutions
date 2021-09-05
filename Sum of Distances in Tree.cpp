class Solution {
public:
    void dfsRoot(int node, int parent, int n, vector<vector<int>>& adj, vector<int>& count, vector<int>& sum){
        for(int child: adj[node]){
            if(child!=parent){
                dfsRoot(child,node,n,adj,count,sum);
                count[node]+=count[child];
                sum[node]+=sum[child]+count[child];
            }
        }
    }
    
    void dfsAll(int node, int parent, int n, vector<vector<int>>& adj, vector<int>& count, vector<int>& sum){
        for(int child: adj[node]){
            if(child!=parent){
                sum[child]=sum[node]-count[child]+n-count[child];
                dfsAll(child,node,n,adj,count,sum);
            }
        }
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // totalSumA=totalSumB-count(a)+count(b)
        // totalSumB-count(a) =sum(a)+sum(b)
        
        // sum(node)=sum(a)+count(a)+sum(b)+count(b)+...
        
        vector<vector<int>> adj(n);
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(n,1);
        vector<int> sum(n,0);
        
        dfsRoot(0,-1,n,adj,count,sum);
        dfsAll(0,-1,n,adj,count,sum);
        
        return sum;
    }
};
