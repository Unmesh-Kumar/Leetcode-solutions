class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1&&i%2==0){
                odd.push_back(i);
            } else if(nums[i]%2==0&&i%2==1){
                even.push_back(i);
            }
        }
        
        
        for(int i=0;i<even.size();i++){
            int temp=nums[odd[i]];
            nums[odd[i]]=nums[even[i]];
            nums[even[i]]=temp;
        }
        
        
        return nums;
    }
};
