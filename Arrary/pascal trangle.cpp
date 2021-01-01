https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    if(A==0) return ans;
    vector<int> first_row;
    first_row.push_back(1);
    ans.push_back(first_row);
    
    for(int i = 1; i < A;i++){
        vector<int> row;
        row.push_back(1);
        for(int j = 1;j<i;j++){
            row.push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        row.push_back(1);
        ans.push_back(row);
    }
    return ans;
}
