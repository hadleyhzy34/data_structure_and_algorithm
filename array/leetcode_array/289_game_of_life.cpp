class Solution {
public:
	bool checkborder(int i,int j,vector<vector<int>>&board){
		if(i<0||j<0||i>=board.size()||j>=board[i].size()){
			return false;
		}else{
			return true;
		}
	}
    void gameOfLife(vector<vector<int>>& board) {
        //current state 0(dead) -> 2(live), -2(dead)
        //current state 1(live) -> 3(live), -3(dead)

    	for(int i=0;i<board.size();i++){
    		for(int j=0;j<board[i].size();j++){
    			int n_live=0,n_dead=0;
    			if(checkborder(i-1,j,board)){
                    if(board[i-1][j]==1||board[i-1][j]==3||board[i-1][j]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i+1,j,board)){
    				if(board[i+1][j]==1||board[i+1][j]==3||board[i+1][j]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i,j-1,board)){
    				if(board[i][j-1]==1||board[i][j-1]==3||board[i][j-1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i,j+1,board)){
    				if(board[i][j+1]==1||board[i][j+1]==3||board[i][j+1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i-1,j-1,board)){
    				if(board[i-1][j-1]==1||board[i-1][j-1]==3||board[i-1][j-1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i-1,j+1,board)){
    				if(board[i-1][j+1]==1||board[i-1][j+1]==3||board[i-1][j+1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i+1,j-1,board)){
    				if(board[i+1][j-1]==1||board[i+1][j-1]==3||board[i+1][j-1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
    			if(checkborder(i+1,j+1,board)){
    				if(board[i+1][j+1]==1||board[i+1][j+1]==3||board[i+1][j+1]==-3){
                        n_live++;
                    }else{
                        n_dead++;
                    }
    			}
                
    			if(board[i][j]==1){
    				if(n_live<2){
    					board[i][j]=-3;
    				}else if(n_live==2||n_live==3){
    					board[i][j]=3;
    				}else{
    					board[i][j]=-3;
    				}
    			}else{
    				if(n_live==3){
    					board[i][j]=2;
    				}else{
    					board[i][j]=-2;
    				}
    			}
                // cout<<i<<" "<<j<<" "<<n_live<<" "<<n_dead<<" "<<board[i][j]<<endl;
    		}
    	}

    	for(int i=0;i<board.size();i++){
    		for(int j=0;j<board[i].size();j++){
    			if(board[i][j]==2||board[i][j]==3){
    				board[i][j]=1;
    			}else{
    				board[i][j]=0;
    			}
    		}
    	}
    }
};