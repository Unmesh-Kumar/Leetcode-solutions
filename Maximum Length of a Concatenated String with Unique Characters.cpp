class Solution {
public:
    int dp(const int index, const int mask, const int n,const vector<string>& arr, unordered_map<int,int>& lookup){
        if(index==n) return 0;
        int key=mask*20+index;
        if(lookup.find(key)==lookup.end()){
            int newMask=mask;
            bool possible=true;
            for(char c: arr[index]){
                if(newMask&(1<<(c-'a'))){
                    possible=false;
                    break;
                } else {
                    newMask^=(1<<(c-'a'));
                }
            }
            
            int ans=dp(index+1,mask,n,arr,lookup);
            
            if(possible) {
                ans=max(ans,(int)arr[index].size()+dp(index+1,newMask,n,arr,lookup));
            }
            
            lookup[key]=ans;
        }
        
        return lookup[key];
    }
    
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        unordered_map<int,int> lookup;
        // mask*20+index
        return dp(0,0,n,arr,lookup);
    }
};
