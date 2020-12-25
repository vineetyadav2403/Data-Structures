https://leetcode.com/problems/word-break/

//--recursive--
bool isWord(string s,vector<string>& wordDict){
        for(auto i:wordDict){
            if(i==s) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict){
            if(i==s) return true;
        }
        for(int i=1;i<s.length();i++){
            if(isWord(s.substr(0,i),wordDict)&&wordBreak(s.substr(i),wordDict)){
                return true;
            }
        }
        return false;
    }
