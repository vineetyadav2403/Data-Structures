https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
        int letterCnt[128]; memset(letterCnt, 0, sizeof(letterCnt));

        int left = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
        
        for (char c : t) ++letterCnt[c];
        
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                
                if (++letterCnt[s[left]] > 0) --cnt;
                
                ++left;
            }
        }
        
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
