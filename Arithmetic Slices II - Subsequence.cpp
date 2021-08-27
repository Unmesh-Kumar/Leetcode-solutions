#define ll long long int

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i][diff]+=dp[j][diff]+1 j<i  diff=nums[i]-nums[j]
        int n=nums.size();
        // key = diff*2000+i
        unordered_map<ll,ll> subscount;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=nums[i]*1l-nums[j]*1l;
                ll keyCurr = diff*2000+i;
                ll keyPrev= diff*2000+j;
                subscount[keyCurr]+=subscount[keyPrev]+1;
            }
        }
        
        ll total=0;
        for(auto itr=subscount.begin();itr!=subscount.end();itr++){
            total+=itr->second;
        }
        
        // O(n*n)
        
        return (int)(total-(n*(n-1))/2);
    }
};
