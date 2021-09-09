class Solution {
public:
    int distinctSubseqII(string s) {
        //  ""
        //  abcdjklc
        //  ""
        //  i=0 "" a
        //  i=1 "" a b ab
        //  i=2 
        //   n     x
        // dp[i]=dp[i-1]+dp[i-1]
        // dp[i]=dp[i-1]+(dp[i-1]-dp[last-1])
        // (dp[n-1]-1)
        
        int n=s.length();
        vector<int> dp(n,0);
        vector<int> last(26,-1);    //0-->a  1-->b  25-->z
        
        const int mod=1e9+7;
        
        // dp[-1]=1
        dp[0]=2;
        last[s[0]-'a']=0;
        
        for(int i=1;i<n;i++){
            dp[i]=2*dp[i-1];
            dp[i]%=mod;
            if(last[s[i]-'a']==0) {
                dp[i]--;
                dp[i]%=mod;
            } else if(last[s[i]-'a']>0){
                dp[i]-=dp[last[s[i]-'a']-1];
                dp[i]%=mod;
            }
            
            last[s[i]-'a']=i;
        }
        
        
        dp[n-1]--;
        dp[n-1]%=mod;
        
        if(dp[n-1]<0) dp[n-1]+=mod;
        return dp[n-1];
        
        // O(n)
        // O(n)
    }
};
