class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=-1){
                int count=0;
                int index=i;
                int nextIndex=-1;
                while(nums[index]!=-1){
                    count++;
                    nextIndex=nums[index];
                    nums[index]=-1;
                    index=nextIndex;                    
                }
                
                maxLen=max(maxLen,count);
            }
        }
        
        // O(n)
        // O(1)
        
        return maxLen;
    }
};
