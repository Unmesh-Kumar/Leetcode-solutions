class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // ptr2--> s2+s2+s2......  str2
        // ptr1--> s1+s1+..s1 --> str1
        
        int len1=s1.length();
        int len2=s2.length();
        
        unordered_map<int,int> increase;
        
        for(int i=0;i<len2;i++) {
            int ptr1=0;
            int ptr2=i;
            while(ptr1!=len1) {
                if(s1[ptr1]==s2[ptr2%len2]) {
                    ptr1++;
                    ptr2++;
                } else {
                    ptr1++;
                }
            }
            increase[i]=ptr2-i;
        }
        
        // O(len2*len1)
        
        int ptr=0;
        int totalMatchedLength=0;
        
        for(int i=0;i<n1;i++) {
            totalMatchedLength+=increase[ptr];
            ptr+=increase[ptr];
            ptr%=len2;
        }
        
        // O(n1+len2*len1)
        
        
        return totalMatchedLength/(len2*n2);
    }
};
