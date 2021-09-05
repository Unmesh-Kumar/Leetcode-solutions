class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.length();
        if(k==1){
            string ans=s;
            
            for(int i=1;i<n;i++){
                string temp="";
                for(int j=0;j<n;j++){
                    temp+=s[(i+j)%n];
                }
                
                
                bool flag=true;
                for(int j=0;j<n;j++){
                    if(ans[j]<temp[j]){
                        flag=false;
                        break;
                    } else if(ans[j]>temp[j]){
                        break;
                    }
                }
                
                if(flag) ans=temp;
            }
            
            return ans;
        }
        
        sort(s.begin(),s.end());
        return s;
    }
};
