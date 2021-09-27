class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for(string email: emails){
            bool on=true;
            bool domain=false;
            string s="";
            for(char c: email){
                if(c=='+') on=false;
                if(c=='@') {
                    on=true;
                    domain=true;
                }
                
                if(on){
                    if(c!='.') s+=c;
                    else {
                        if(domain) s+=c;
                    }
                }
            }
            
            uniqueEmails.insert(s);
        }
        
        return uniqueEmails.size();
    }
};
