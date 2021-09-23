class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1) return "";
        bool isReplaced=false;
        
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                isReplaced=true;
                break;
            }
        }
        
        
        if(!isReplaced){
            palindrome[n-1]='b';
        }
        
        
        return palindrome;
        // O(n)
        // o(1)
    }
};
