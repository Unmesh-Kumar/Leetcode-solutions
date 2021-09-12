class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> graph(n);
        for(vector<int> edge: edges){
            graph[edge[0]].push_back({edge[1],edge[2]+1});
            graph[edge[1]].push_back({edge[0],edge[2]+1});
        }
        
        const int inf=1e9+7;
        
        vector<int> dist(n,inf);
        set<pair<int,int>> activePoints;
        dist[0]=0;
        activePoints.insert({0,0}); // distance, node
        
        while(!activePoints.empty()){
            auto itr=*activePoints.begin();
            activePoints.erase(itr);
            int distance = itr.first;
            int node = itr.second;
            for(auto neigh: graph[node]){
                if(dist[neigh.first]>dist[node]+neigh.second){
                    activePoints.erase({dist[neigh.first],neigh.first});
                    dist[neigh.first]=dist[node]+neigh.second;
                    activePoints.insert({dist[neigh.first],neigh.first});
                }
            }
        }
        
        int count=0;
        for(int val: dist){
            if(val<=maxMoves) count++;
        }
        
        
        for(vector<int>& edge: edges){
            int reachableFromFirstNode=min(edge[2],max(0,maxMoves-dist[edge[0]]));
            int reachableFromSecondNode=min(edge[2],max(0,maxMoves-dist[edge[1]]));
            count+=min(edge[2],reachableFromFirstNode+reachableFromSecondNode);
        }
        
        return count;
    }
};
