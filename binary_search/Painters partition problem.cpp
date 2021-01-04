https://www.interviewbit.com/problems/painters-partition-problem/

bool isPossible(int mid, vector<int> &c, int a) {
    long long Time = 0, numPainters = 1, n = c.size();
    for(int i = 0; i < n; i++) {
        Time += c[i];
        if(Time > mid) {
            Time = c[i];
            numPainters++;
            if(numPainters > a) return false;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    long long maxTime = 0;
    long long lo = 0, hi, mid, ans;
    for(int i = 0; i < n; i++){
        maxTime += C[i];
        lo = max(lo,(long long)C[i]);
    } 
    hi = maxTime;
    while(lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if(isPossible(mid, C, A)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return (ans * B) % 10000003;
}
