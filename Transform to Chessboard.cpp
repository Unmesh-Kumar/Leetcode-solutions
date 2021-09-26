class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size();
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n;j++){
                if(board[i][j]==board[i][j-1]){
                    if(board[i+1][j]!=board[i+1][j-1]) return -1;
                } else {
                    if(board[i+1][j]==board[i+1][j-1]) return -1;
                }
            }
        }
        
        bool possible=false;
        int colSwap=0;
        int ones=0;
        int zeroes=0;
        
        
        
        
        // 0 1 0 1 ..
        
        for(int i=0;i<n;i++){
            if(i%2==0){ // 0
                if(board[0][i]==1){
                    ones++;
                }
            }else{//1
                if(board[0][i]==0){
                    zeroes++;
                }
            }
        }
        
        if(ones==zeroes){
            possible=true;
            colSwap=ones;
        }
        
        
        ones=0;
        zeroes=0;
        
        
        
        
        // 1 0 1 0 1 ..
        
        for(int i=0;i<n;i++){
            if(i%2==0){ // 1
                if(board[0][i]==0){
                    zeroes++;
                }
            }else{//0
                if(board[0][i]==1){
                    ones++;
                }
            }
        }
        
        if(ones==zeroes){
            if(possible){
                colSwap=min(colSwap,ones);
            } else {
                possible=true;
                colSwap=ones;
            }
        }
        
        
        if(!possible) return -1;
        
        
        possible=false;
        int rowSwap=0;
        ones=0;
        zeroes=0;
        
        
        
        
        // 0 1 0 1 ..
        
        for(int i=0;i<n;i++){
            if(i%2==0){ // 0
                if(board[i][0]==1){
                    ones++;
                }
            }else{//1
                if(board[i][0]==0){
                    zeroes++;
                }
            }
        }
        
        if(ones==zeroes){
            possible=true;
            rowSwap=ones;
        }
        
        
        ones=0;
        zeroes=0;
        
        
        
        
        // 1 0 1 0 1 ..
        
        for(int i=0;i<n;i++){
            if(i%2==0){ // 1
                if(board[i][0]==0){
                    zeroes++;
                }
            }else{//0
                if(board[i][0]==1){
                    ones++;
                }
            }
        }
        
        if(ones==zeroes){
            if(possible){
                rowSwap=min(rowSwap,ones);
            } else {
                possible=true;
                rowSwap=ones;
            }
        }
        
        
        if(!possible) return -1;
        
        
        return rowSwap+colSwap;
        
        // O(n*n)
        // O(1)
        
    }
};
