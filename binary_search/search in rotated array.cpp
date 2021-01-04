https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    int n = A.size(),left = 0, right,mid;
    right = n-1;
    while(left<=right){
        mid = left + (right - left)/2;
        if(A[mid]==B) return mid;
        else if(A[mid] > A[left]){
            if(A[left]<=B && B<A[mid]){
                    right=mid-1;
                } else {
                    left=mid+1;
                }
        }else{
            if(A[mid]<B && B<=A[right]){
                    left=mid+1;
                } else {
                    right=mid-1;
                }
        }
    }
    return -1;
}
