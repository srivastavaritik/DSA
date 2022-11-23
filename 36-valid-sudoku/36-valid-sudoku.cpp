class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string ch(1,board[i][j]);
                string row = ch + "Found at row "+ to_string(i);
                string col = ch + "Found at col "+ to_string(j);
                string box = ch + "Found at row "+ to_string(i/3) + to_string(j/3);
                if(s.find(row)!=s.end() || s.find(col)!=s.end() || s.find(box)!=s.end()) return false;
                else {
                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                }
                
            }
        }
        return true;
    }
};