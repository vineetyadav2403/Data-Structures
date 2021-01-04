https://www.interviewbit.com/problems/woodcutting-made-easy/

int Solution::solve(vector<int> &A, int B) {
    int left = 0,mid,right=INT_MIN,n=A.size();
    long wood = 0;
    int ans = 0;
    for(auto i:A) right = max(right,i);
    while(left<=right){
        mid = left + (right - left)/2;
        wood = 0;
        for(auto i:A){
            if(i-mid>0){
                wood+=(i-mid);
            }
        }
        if(wood>=B){
            left = mid + 1;
            ans = max(ans,mid);
        }else{
            right = mid-1;
        }
    }
    return ans;
}
