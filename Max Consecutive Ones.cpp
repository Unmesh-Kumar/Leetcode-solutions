class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int maxOnes=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr++;
            } else {
                maxOnes=max(maxOnes,curr);
                curr=0;
            }
        }
        
        maxOnes=max(maxOnes,curr);
        
        
        return maxOnes;
    }
};
