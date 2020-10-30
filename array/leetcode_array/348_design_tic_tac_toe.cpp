class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
       edge=n; 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player==1){
            h_1[row]++;
            v_1[col]++;
            if(row==col){
                d_l_1++;
            }
            if(row==abs(col+1-edge)){
                d_r_1++;
            }
            if(h_1[row]==edge||v_1[col]==edge||d_l_1==edge||d_r_1==edge){
                return 1;
            }
        }else{
            h_2[row]++;
            v_2[col]++;
            if(row==col){
                d_l_2++;
            }
            if(row==abs(col+1-edge)){
                d_r_2++;
            }
            if(h_2[row]==edge||v_2[col]==edge||d_l_2==edge||d_r_2==edge){
                return 2;
            }
        }
        return 0;

    }
private:
    unordered_map<int,int>h_1;
    unordered_map<int,int>h_2;
    unordered_map<int,int>v_1;
    unordered_map<int,int>v_2;
    int d_l_1=0;
    int d_l_2=0;
    int d_r_1=0;
    int d_r_2=0;
    int edge;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */