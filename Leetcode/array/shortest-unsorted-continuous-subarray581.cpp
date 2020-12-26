https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -1;
        int minValue = INT_MAX, maxValue = INT_MIN;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) minValue = min(minValue, nums[i+1]);
            if(nums[n-i-1] < nums[n-i-2]) maxValue = max(maxValue, nums[n-i-2]);
        }
        if(minValue == INT_MAX) return 0;
        for(int i = 0; i < n; i++) {
            if(l == -1 && nums[i] > minValue) l = i;
            if(r == -1 && nums[n-i-1] < maxValue) {r = n-i-1;}
        }
        return r-l+1;
    }
