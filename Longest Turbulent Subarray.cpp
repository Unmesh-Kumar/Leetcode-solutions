class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int curr=1;
        int ans=1;
        for(int i=1;i<n;i++){
            //arr[i-1] arr[i]
            if((i-1)%2==0){
                if(arr[i-1]<arr[i]){
                    curr=curr+1;
                    ans=max(ans,curr);
                } else {
                    curr=1;
                    ans=max(ans,curr);
                                    
                }
            } else {
                if(arr[i-1]>arr[i]){
                    curr=curr+1;
                    ans=max(ans,curr);
                } else {
                    curr=1;
                    ans=max(ans,curr);
                }
            }
        }
        
        curr=1;
        
        for(int i=1;i<n;i++){
            //arr[i-1] arr[i]
            if((i-1)%2==0){
                if(arr[i-1]>arr[i]){
                    curr=curr+1;
                    ans=max(ans,curr);
                } else {
                    curr=1;
                    ans=max(ans,curr);
                }
            } else {
                if(arr[i-1]<arr[i]){
                    curr=curr+1;
                    ans=max(ans,curr);
                } else {
                    curr=1;
                    ans=max(ans,curr);
                }
            }
        }
        
        return ans;
    }
};
