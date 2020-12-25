https://leetcode.com/problems/sliding-window-maximum/



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // support variables
        int len = nums.size() - k + 1, higherValues[k], startPos = 0, endPos = 0;
        vector<int> res(len);
        // preparing dq with the first k - 1 elements
        k--;
        for (int i = 0; i < k; i++) {
            while (endPos != startPos && nums[higherValues[endPos - 1]] <= nums[i]) endPos = endPos - 1;
            higherValues[endPos++] = i;
        }
        k++;
        // parsing through nums
        for (int i = 0, n = k - 1; i < len; i++, n++) {
            // popping smaller values
            while (endPos != startPos && nums[higherValues[endPos ? endPos - 1 : k - 1]] <= nums[n]) endPos = endPos ? endPos - 1 : k - 1;
            // adding the current index n
            higherValues[endPos++] = n;
            if (endPos == k) endPos = 0;
            // updating res
            res[i] = nums[higherValues[startPos]];
            // popping the first element out
            if (higherValues[startPos] == i) startPos = (startPos + 1) % k;
        }
        return res;
    }



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> dq;
        int i;
        for(i=0;i<k;i++){
            if(!dq.empty()){
                dq.push_back(i);
            }else{
                while(nums[dq.back()]<=nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            while(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return ans;
    }
