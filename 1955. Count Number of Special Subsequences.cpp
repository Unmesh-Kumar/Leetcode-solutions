#define ll long long int
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        // 0000         ---> count[0]
        // 000011111    ---> count[1]
        // 000011112222 --> special subsequence--> count[2]
        // [0.....i-1]
        // i
        // nums[i]==0
        //  newcount[0]=count[0]+count[0]+1
        // nums[1]==1
        //  newcount[1]=count[1]+count[1]+count[0]
        // nums[2]==2
        // newcount[2]=count[2]+count[2]+count[1]
        // time -  O(n)  space -  O(1)
        
        const ll mod=1e9+7;
        
        int n=nums.size();
        vector<ll> count(3,0);
        vector<ll> newcount(3,0);
        for(int num: nums) {
            if(num==0) {
                newcount[0]=(count[0]+count[0]+1)%mod;
                newcount[1]=count[1];
                newcount[2]=count[2];
            } else if(num==1){
                newcount[0]=count[0];
                newcount[1]=(count[1]+count[1]+count[0])%mod;
                newcount[2]=count[2];
            } else {
                newcount[0]=count[0];
                newcount[1]=count[1];
                newcount[2]=(count[2]+count[2]+count[1])%mod;
            }
            
            count[0]=newcount[0];
            count[1]=newcount[1];
            count[2]=newcount[2];
        }
        
        return (int)count[2];
    }
};
