#define ll long long int

class Solution {
public:
    
    void rec(int index,const int n,const string& num, string& s,const int target,vector<string>& ans, ll curr, ll prev, ll sum, char sign) {
        if(index==n-1){
            s+=num[n-1];
            curr=curr*10+(num[n-1]-'0');
            if(sign=='+'){
                if(sum+curr==target) ans.push_back(s);
            } else if(sign=='-'){
                if(sum-curr==target) ans.push_back(s);
            } else if(sign=='*') {
                if(sum+prev*curr==target) ans.push_back(s);
            }
            
            s.pop_back();
        }
        else {
            s+=num[index];
            curr=curr*10+(num[index]-'0');
            
            ll newSum=sum;
            if(sign=='+'){
                newSum+=curr;
            } else if(sign=='-'){
                newSum-=curr;
            } else if(sign=='*'){
                newSum+=prev*curr;
            }
            
            // addition
            
            s+="+";
            rec(index+1,n,num,s,target,ans,0,-1,newSum,'+');
            s.pop_back();
            
            
            // subtraction
            
            s+="-";
            rec(index+1,n,num,s,target,ans,0,-1,newSum,'-');
            s.pop_back();
            
            
            // multiplication
            
            s+="*";
            if(sign=='+')
                rec(index+1,n,num,s,target,ans,0,curr,sum,'*');
            else if(sign=='-')
                rec(index+1,n,num,s,target,ans,0,-1*curr,sum,'*');
            else
                rec(index+1,n,num,s,target,ans,0,prev*curr,sum,'*');
            
            s.pop_back();
            
            
            // no operator
            
            if(!(num[index]=='0'&&curr==0)){
                rec(index+1,n,num,s,target,ans,curr,prev,sum,sign);
            }
            
            s.pop_back();
        }
    }
    
    
    
    
    vector<string> addOperators(string num, int target) {
        int n=num.size();
        vector<string> ans;
        string s="";
        int index=0;
        ll curr=0;
        ll prev=0;
        ll sum=0;
        char sign='+';
        rec(0,n,num,s,target,ans,curr,prev,sum,sign);
        
        return ans;
    }
};
