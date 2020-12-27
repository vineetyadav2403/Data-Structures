https://leetcode.com/problems/permutations/

vector<vector<int>> ans;
    void dfs(vector<int> nums,int i,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }else{
            for(int j=i;j<n;j++){
                swap(nums[i],nums[j]);
                dfs(nums,i+1,n);
                swap(nums[i],nums[j]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        dfs(nums,0,n);
        return ans;
    }
