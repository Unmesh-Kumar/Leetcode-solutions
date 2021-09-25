class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        queue<vector<int>> nodes;
        nodes.push({0,0,k,0});
        visited[0][0][k]=true;
        
        while(!nodes.empty()){
            vector<int> node=nodes.front();
            nodes.pop();
            
            if(node[0]==m-1&&node[1]==n-1){
                return node[3];
            }
            
            if(node[0]-1>=0){
                if(grid[node[0]-1][node[1]]==1){
                    if(node[2]>=1&&!visited[node[0]-1][node[1]][node[2]-1]){
                        visited[node[0]-1][node[1]][node[2]-1]=true;
                        nodes.push({node[0]-1,node[1],node[2]-1,node[3]+1});
                    }
                } else {
                    if(!visited[node[0]-1][node[1]][node[2]]){
                        visited[node[0]-1][node[1]][node[2]]=true;
                        nodes.push({node[0]-1,node[1],node[2],node[3]+1});
                    }
                }
            }
            
            
            if(node[1]-1>=0){
                if(grid[node[0]][node[1]-1]==1){
                    if(node[2]>=1&&!visited[node[0]][node[1]-1][node[2]-1]){
                        visited[node[0]][node[1]-1][node[2]-1]=true;
                        nodes.push({node[0],node[1]-1,node[2]-1,node[3]+1});
                    }
                } else {
                    if(!visited[node[0]][node[1]-1][node[2]]){
                        visited[node[0]][node[1]-1][node[2]]=true;
                        nodes.push({node[0],node[1]-1,node[2],node[3]+1});
                    }
                }
            }
            
            if(node[0]+1<m){
                if(grid[node[0]+1][node[1]]==1){
                    if(node[2]>=1&&!visited[node[0]+1][node[1]][node[2]-1]){
                        visited[node[0]+1][node[1]][node[2]-1]=true;
                        nodes.push({node[0]+1,node[1],node[2]-1,node[3]+1});
                    }
                } else {
                    if(!visited[node[0]+1][node[1]][node[2]]){
                        visited[node[0]+1][node[1]][node[2]]=true;
                        nodes.push({node[0]+1,node[1],node[2],node[3]+1});
                    }
                }
            }
            
            
            if(node[1]+1<n){
                if(grid[node[0]][node[1]+1]==1){
                    if(node[2]>=1&&!visited[node[0]][node[1]+1][node[2]-1]){
                        visited[node[0]][node[1]+1][node[2]-1]=true;
                        nodes.push({node[0],node[1]+1,node[2]-1,node[3]+1});
                    }
                } else {
                    if(!visited[node[0]][node[1]+1][node[2]]){
                        visited[node[0]][node[1]+1][node[2]]=true;
                        nodes.push({node[0],node[1]+1,node[2],node[3]+1});
                    }
                }
            }
            
            
            
            
        }
        
        
        return -1;
    }
};
