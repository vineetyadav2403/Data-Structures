void rotate(vector<vector<int>>& matrix) {
        int temp;
        int rowsize=matrix.size();
        for(int i=0; i<rowsize;i++){
            for(int j=i; j<rowsize-i-1; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[rowsize-1-j][i];
                matrix[rowsize-1-j][i] = matrix[rowsize-1-i][rowsize-1-j];
                matrix[rowsize-1-i][rowsize-1-j] = matrix[j][rowsize-1-i];
                matrix[j][rowsize-1-i] = temp;
            }
        }
        return;
    }
