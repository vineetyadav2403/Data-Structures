https://leetcode.com/problems/word-search/
// 79 word search---
void dfs(vector<vector<char>>& board, string &word,int i,int j,int k,bool &ans){
        int n = board.size();
        if(!ans&&i>=0&&i<n&&j>=0){
            int m = board[i].size();
            if(j<m&&board[i][j]==word[k]){
                //cout<<board[i][j]<<" ";
                if(word[k+1]=='\0'){
                    ans = true;
                }
                char ch = board[i][j];
                board[i][j] = '\0';
               
                dfs(board,word,i+1,j,k+1,ans);
                dfs(board,word,i-1,j,k+1,ans);
                dfs(board,word,i,j+1,k+1,ans);
                dfs(board,word,i,j-1,k+1,ans);
                board[i][j] = ch;
            }
            
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> start;
        int j,i;
        for(i=0;i<board.size();i++){
            for(j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    start.push_back({i,j});
                }
            }
        }
        bool ans = false;
        for(auto p:start){
           // cout<<p.first<<p.second<<endl;
            dfs(board,word,p.first,p.second,0,ans);
           // cout<<ans<<endl;
        }
      /*  for(auto i:board){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        } */
        return ans;
        
    }
