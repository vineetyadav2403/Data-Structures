https://leetcode.com/problems/partition-labels/


unordered_map<char,int> mp;
    vector<int> partitionLabels(string s) {
        int i,temp = 0,j = 0;
        for(i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            j = max(j,mp[s[i]]);
            
            if(j==i){
                ans.push_back(i-temp+1);
                temp = i+1;
            }
        }
        
        return ans;
    }
