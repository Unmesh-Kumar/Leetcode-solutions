class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        
        for(int num: nums1){
            freq[num]++;
        }
        
        vector<int> intersection;
        for(int num: nums2){
            if(freq[num]>0){
                intersection.push_back(num);
                freq[num]--;
            }
        }
        
        return intersection;
        // O(n+m)
        // O(n)
    }
};
