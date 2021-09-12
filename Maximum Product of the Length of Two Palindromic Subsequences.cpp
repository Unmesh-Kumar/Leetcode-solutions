class Solution {
public:
    int maxProduct(string s) {
        int n=s.length();
        if(n==2) return 1;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // dp[i,j]
        
        
        int maxProduct=1;
        
        for(int mask=0;mask<(2<<n);mask++){
            string s1="";
            string s2="";
            
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    s2+=s[j];
                } else {
                    s1+=s[j];
                }
            }
            
            int curr=1;
            
            int x=s1.length();
            int y=s2.length();
            
            
            for(int i=1;i<=x;i++){
                for(int j=1;j<=x;j++){
                    if(s1[i-1]==s1[x-j]){
                        dp[i][j]=1+dp[i-1][j-1];
                    } else {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            
            curr*=dp[x][x];
            
            for(int i=1;i<=y;i++){
                for(int j=1;j<=y;j++){
                    if(s2[i-1]==s2[y-j]){
                        dp[i][j]=1+dp[i-1][j-1];
                    } else {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            
            curr*=dp[y][y];
            
            
            maxProduct=max(maxProduct,curr);
            
        }
        
        return maxProduct;
    }
};
