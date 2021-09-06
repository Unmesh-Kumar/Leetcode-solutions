class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n=releaseTimes.size();
        int maxDuration=releaseTimes[0];
        char ans=keysPressed[0];
        
        for(int i=1;i<n;i++){
            int currDuration=releaseTimes[i]-releaseTimes[i-1];
            if(currDuration>maxDuration){
                maxDuration=currDuration;
                ans=keysPressed[i];
            } else if(currDuration==maxDuration){
                if(keysPressed[i]>ans) ans=keysPressed[i];
            }
        }
        
        // O(n)
        // O(1)
        return ans;
        
    }
};
