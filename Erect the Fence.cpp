class Solution {
public:
    int inOrder(vector<int> a, vector<int> b, vector<int> c){
        int ab_x=b[0]-a[0];
        int ab_y=b[1]-a[1];
        int bc_x=c[0]-b[0];
        int bc_y=c[1]-b[1];
        return ab_x*bc_y-ab_y*bc_x;
    }
    
    int distance(vector<int> a, vector<int> b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    
    
    void swap(vector<int>& a, vector<int>& b){
        vector<int> temp=a;
        a=b;
        b=temp;
    }
    
    
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        if(n<=3) return trees;
        
        vector<int> pivot=trees[0];
        for(vector<int> point: trees){
            if(point[1]<pivot[1]){
                pivot=point;
            }
        }
        
        vector<vector<int>> points;
        for(vector<int> point: trees){
            if(point[0]!=pivot[0]||point[1]!=pivot[1]){
                points.push_back(point);
            }
        }
        
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int> b){
            int direction=inOrder(pivot,a,b);
            if(direction==0){
                return distance(pivot,a)<distance(pivot,b);
            }
            
            return (direction>0);
        });
        
        
        int i=n-2;
        while(i>=0&&inOrder(pivot,points[n-2],points[i])==0){
            i--;
        }
        
        int l=i+1;
        int r=n-2;
        while(l<n-1&&r>=0&&l<r){
            swap(points[l],points[r]);
            l++;
            r--;
        }
        
        stack<vector<int>> perimeter;
        perimeter.push(pivot);
        perimeter.push(points[0]);
        
        
        for(int i=1;i<n-1;i++){
            vector<int> topmost=perimeter.top();
            perimeter.pop();
            while(inOrder(perimeter.top(),topmost,points[i])<0){
                topmost=perimeter.top();
                perimeter.pop();
            }
            
            perimeter.push(topmost);
            perimeter.push(points[i]);
        }
        
        vector<vector<int>> fence;
        while(!perimeter.empty()){
            fence.push_back(perimeter.top());
            perimeter.pop();
        }
        
        
        return fence;   
        
        // nlogn
        // n
        
    }
};
