class Solution {
public:
    void swap(char& a, char& b){
        char temp=a;
        a=b;
        b=temp;
    }
    
    bool isEnglish(char c){
        return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
    }
    
    
    string reverseOnlyLetters(string s) {
        int n=s.length();
        int l=0;
        int r=n-1;
        
        while(l<r){
            while(l<n&&!isEnglish(s[l])){
                l++;
            }
            
            while(r>=0&&!isEnglish(s[r])){
                r--;
            }
            
            if(l>=r) break;
            
            swap(s[l],s[r]);
            l++;
            r--;
        }
        
        return s;
    }
};
