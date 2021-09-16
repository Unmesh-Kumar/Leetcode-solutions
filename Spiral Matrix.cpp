class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int i=0;
        int j=n-1;
        int p=0;
        int q=m-1;
        
        vector<int> ans;
        
        while(i<=j&&p<=q){
            
            for(int k=p;k<=q;k++){
                ans.push_back(matrix[i][k]);
            }
            
            
            for(int k=i+1;k<=j-1;k++){
                ans.push_back(matrix[k][q]);
            }
            
            
            if(i!=j)
                for(int k=q;k>=p;k--){
                    ans.push_back(matrix[j][k]);
                }
            
            
            if(p!=q)
                for(int k=j-1;k>=i+1;k--){
                    ans.push_back(matrix[k][p]);
                }
            
            
            
            i++;
            j--;
            p++;
            q--;
        }
        
        return ans;
    }
};
