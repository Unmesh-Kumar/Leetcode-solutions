class Solution {
public:
    int calc(int l, int r, string& s, unordered_map<int,int>& pairs){
        int val=0;
        int sign=1;
        
        
        for(int i=l;i<=r;i++){
            if(s[i]=='('){
                val+=sign*calc(i+1,pairs[i]-1,s,pairs);
                i=pairs[i];
            } else if(s[i]=='+'){
                sign=1;
            } else if(s[i]=='-'){
                sign=-1;
            } else if(s[i]>='0'&&s[i]<='9'){
                int num=0;
                for(;i<=r;i++){
                    if(s[i]>='0'&&s[i]<='9'){
                        num*=10;
                        num+=s[i]-'0';
                    } else {
                        i--;
                        break;
                    }
                }
                
                val+=sign*num;
            }
        }
        
        return val;
    }
    
    
    
    int calculate(string s) {
        unordered_map<int,int> pairs;
        stack<int> openings;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openings.push(i);
            } else if(s[i]==')'){
                pairs[openings.top()]=i;
                openings.pop();
            }
        }
        
        return calc(0,s.length()-1,s,pairs);
    }
};
