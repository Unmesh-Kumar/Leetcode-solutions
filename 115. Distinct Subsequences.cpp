class Solution {
public:
    unordered_map<int,int> lookup;
    int dp(int i, int j, int n, int m, string& s, string& t){
        if(j==0) return 1;
        if(i<j) return 0;
        int key=i*2000+j;
        if(lookup.find(key)==lookup.end()){
            int ans=dp(i-1,j,n,m,s,t);
            if(s[i-1]==t[j-1]){
                ans+=dp(i-1,j-1,n,m,s,t);
            }
            
            lookup[key]=ans;
        }
        
        return lookup[key];
    }
    
    
    int numDistinct(string s, string t) {
        // dp[i,j] = dp[i-1][j]+dp[i-1][j-1]
        int n=s.length();
        int m=t.length(); 
        
        // O(n^2)
        // O(n^2)
        return dp(n,m,n,m,s,t);
    }
};
