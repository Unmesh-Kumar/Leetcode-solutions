class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(vector<int> mine: mines){
            grid[mine[0]][mine[1]]=0;
        }
        
        
        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> up(n,vector<int>(n,0));
        vector<vector<int>> down(n,vector<int>(n,0));
        
        // precomputation
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    left[i][j]=1+(j-1>=0?left[i][j-1]:0);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=0){
                    right[i][j]=1+(j+1<n?right[i][j+1]:0);
                }
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]!=0){
                    up[i][j]=1+(i-1>=0?up[i-1][j]:0);
                }
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                if(grid[i][j]!=0){
                    down[i][j]=1+(i+1<n?down[i+1][j]:0);
                }
            }
        }
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int plus=min(left[i][j],right[i][j]);
                plus=min(plus,min(up[i][j],down[i][j]));
                
                ans=max(ans,plus);
            }
        }
        
        return ans;
        
        // O(n^2)
        // O(n^2)
    }
};
