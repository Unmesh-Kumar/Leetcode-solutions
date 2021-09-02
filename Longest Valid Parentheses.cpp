class Solution {
public:
    int longestValidParentheses(string s) {
        //   dp[i]          i-2()  dp[i-2]+2
        //             ((          ))if(i-1-dp[i-1]=='(') dp[i-1]+2+dp[i-1-dp[i-1]-1]
        int n=s.length();
        if(n==0) return 0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(i-1>=0){
                    if(s[i-1]=='('){
                        dp[i]=2+dp[max(i-2,0)];
                    } else {
                        if(i-1-dp[i-1]>=0&&s[i-1-dp[i-1]]=='('){
                            dp[i]=2+dp[i-1]+dp[max(i-1-dp[i-1]-1,0)];
                        }
                    }
                }
            }
        }
        
        // O(n)
        // O(n)
        
        
        
        return *max_element(dp.begin(),dp.end());
    }
};
