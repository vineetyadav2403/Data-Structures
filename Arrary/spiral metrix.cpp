https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A,vector<int>(A,0));
    int left = 0,right = A-1,top = 0,bottom = A-1,k = 1,direction = 0,i;
    while(left<=right && top<=bottom){
        if(direction == 0){
            for(i = left; i <= right;i++){
                ans[top][i] = k++;
            }
            top++;
        }else if(direction == 1){
            for(i = top; i <= bottom;i++){
                ans[i][right] = k++;
            }
            right--;
        }else if(direction == 2){
            for(i = right; i>=left;i--){
                ans[bottom][i] = k++;
            }
            bottom--;
        }else{
            for(i = bottom;i>=top;i--){
                ans[i][left] = k++;
            }
            left++;
        }
       
        direction = (direction + 1) % 4;
    }
    return ans;
    
}
