class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> coloum[9];
        unordered_set<char> box[9];
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                char cell=board[i][j];
                if(cell == '.') continue;
                
                    if (row[i].find(board[i][j])==row[i].end())
                        {
                         row[i].insert(board[i][j]);
                    }else
                     {
                    return false;
                     }
                     if (coloum[j].find(board[i][j])==coloum[j].end())
                {
                        coloum[j].insert(board[i][j]);
                     }else
                    {
                        return false;
                    }
                    int result=(i/3)*3+(j/3);
                    if(box[result].find(board[i][j])==box[result].end())
                    {
                        box[result].insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }


                    
                
            }
        }


        return true;       
    }
};