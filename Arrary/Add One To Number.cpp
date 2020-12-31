https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size()-1;
    bool flag = false;
    vector<int> ans;
    for(int i = n;i>=0;i--){
        if(A[i]==9){
            A[i] = 0;
            if(i==0) flag = true;
        }else{
            A[i]+=1;
            break;
        }
    }
    if(flag){
        flag = false;
        ans.push_back(1);
        for(int i = 0; i<=n;i++ ){
            ans.push_back(A[i]);
        }
    }else{
        flag = false;
        for(int i = 0; i<=n;i++ ){
            if(A[i]==0&&!flag){
                continue;
            }else{
                ans.push_back(A[i]);
                flag = true;
            }
        }
    }
    return ans;
}
