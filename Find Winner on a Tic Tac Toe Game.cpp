class Solution {
public:
    int verdict(vector<vector<char>> grid){
        if(grid[0][0]=='X'&&grid[0][1]=='X'&&grid[0][2]=='X'){
            return 0;
        }
        
        if(grid[1][0]=='X'&&grid[1][1]=='X'&&grid[1][2]=='X'){
            return 0;
        }
        
        if(grid[2][0]=='X'&&grid[2][1]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        if(grid[0][0]=='X'&&grid[1][0]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        if(grid[0][1]=='X'&&grid[1][1]=='X'&&grid[2][1]=='X'){
            return 0;
        }
        
        
        if(grid[0][2]=='X'&&grid[1][2]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        
        if(grid[0][0]=='X'&&grid[1][0]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        if(grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        if(grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]=='X')
            }
        }
        
        
        if(grid[0][0]=='X'&&grid[0][1]=='X'&&grid[0][2]=='X'){
            return 0;
        }
        
        if(grid[1][0]=='X'&&grid[1][1]=='X'&&grid[1][2]=='X'){
            return 0;
        }
        
        if(grid[2][0]=='X'&&grid[2][1]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        if(grid[0][0]=='X'&&grid[1][0]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        if(grid[0][1]=='X'&&grid[1][1]=='X'&&grid[2][1]=='X'){
            return 0;
        }
        
        
        if(grid[0][2]=='X'&&grid[1][2]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        
        if(grid[0][0]=='X'&&grid[1][0]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        if(grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X'){
            return 0;
        }
        
        if(grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X'){
            return 0;
        }
        
        
        
        
        
        return -1;
    }
    
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3,vector<char>(3,' '));
        bool A=true;
        for(vector<int> move: moves){
            if(A){
                grid[move[0]][move[1]]='X';
            } else {
                grid[move[0]][move[1]]='O';
            }
            
            if(verdict(grid)==0){
                return "A";
            } else if(verdict(grid)==1){
                return "B";
            } 
            
            A=!A;
        }
        
        if(moves.size()==9){
            return "Draw";
        } else {
            return "Pending";
        }
    }
};
