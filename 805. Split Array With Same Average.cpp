class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {        
        int n=nums.size();
        int sum=0;
        for(int num: nums) sum+=num;
        
        vector<unordered_set<int>> possibleSums((n/2)+1);
        possibleSums[0].insert(0);
        for(int num: nums) {
            for(int i=n/2;i>=1;i--){
                for(int elem: possibleSums[i-1]){
                    possibleSums[i].insert(elem+num);
                }
            }
        }
        
        for(int i=1;i<=n/2;i++){
            if((i*sum)%n==0){
                if(possibleSums[i].find((i*sum)/n)!=possibleSums[i].end()) return true;
            }
        }
        
        return false;
    }
};
