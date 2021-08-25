class Solution {
public:
    unordered_map<int,int> lookup;
    int superEggDrop(int k, int n) {
        if(k==1) return n;
        if(n==0) return 0;
        int key=n*200+k;
        if(lookup.find(key)==lookup.end()){
            int low=1;
            int high=n;
            while(low+1<high) {
                int mid=(low+high)/2;
                int numMoves1=superEggDrop(k-1, mid-1);
                int numMoves2=superEggDrop(k, n-mid);
                if(numMoves1<numMoves2){
                    low=mid;
                } else if(numMoves1>numMoves2) {
                    high=mid;
                } else {
                    low=mid;
                    high=mid;
                    break;
                }
            }
            
            lookup[key]=1+min(max(superEggDrop(k-1, low-1),superEggDrop(k, n-low)),max(superEggDrop(k-1, high-1),superEggDrop(k, n-high)));
        }
        
        return lookup[key];
    }
};
