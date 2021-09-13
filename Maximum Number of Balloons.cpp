class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26,0); // 0-->'a'  1-->'b'   
        for(char c: text){
            freq[c-'a']++;
        }
        
        string balloon="balon";
        vector<int> reqCount={1,1,2,2,1};
        vector<int> nums(5,0);
        
        for(int i=0;i<5;i++){
            nums[i]=freq[balloon[i]-'a']/reqCount[i];
        }
        
        return *min_element(nums.begin(),nums.end());
    }
};
