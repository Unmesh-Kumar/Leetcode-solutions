class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<int> totalShifts(n,0);
        
        for(int i=0;i<n;i++){
            totalShifts[0]+=shifts[i];
            totalShifts[0]%=26;
            if(i+1<n){
                totalShifts[i+1]-=shifts[i];
                totalShifts[i+1]%=26;
            }
        }
        
        for(int i=1;i<n;i++){
            totalShifts[i]+=totalShifts[i-1];
            totalShifts[i]%=26;
            if(totalShifts[i]<0) totalShifts[i]+=26;
        }
        
        string ans="";
        
        for(int i=0;i<n;i++){
            int val=s[i]+totalShifts[i];
            if(val>'z') val-=26;
            ans+=(char)(val);
        }
        
        return ans;
    }
};
