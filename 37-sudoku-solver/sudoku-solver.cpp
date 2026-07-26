class Solution {
public:
    int rows[9]={0};
    int cols[9]={0};
    int grids[9]={0};

    bool dfs(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    int idx=(i/3)*3+j/3;
                    for(int val=1;val<=9;val++){
                        int bit=1<<(val-1);
                        if((rows[i]&bit)||(cols[j]&bit)||(grids[idx]&bit))
                            continue;
                        board[i][j]=val+'0';
                        rows[i]|=bit;
                        cols[j]|=bit;
                        grids[idx]|=bit;
                        if(dfs(board))
                            return true;
                        board[i][j]='.';
                        rows[i]^=bit;
                        cols[j]^=bit;
                        grids[idx]^=bit;
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val=board[i][j]-'0';
                    int bit=1<<(val-1);
                    rows[i]|=bit;
                    cols[j]|=bit;
                    int idx=(i/3)*3+j/3;
                    grids[idx]|=bit;
                }
            }
        }
        dfs(board);
    }
};