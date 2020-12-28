https://leetcode.com/problems/minimum-path-sum/

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> values(m+1, vector<int> (n+1, INT_MAX));
        
		//Starting Point
        values[1][1] = grid[0][0];
        
        for(int i = 1; i <= m; i++){
		
            for(int j = 1; j <= n; j++){                
                
                if(i == 1 && j == 1)
                    continue;
    
                values[i][j] = min(values[i-1][j], values[i][j-1]) + grid[i-1][j-1];    
            }
        }
        return values[m][n];
    }
