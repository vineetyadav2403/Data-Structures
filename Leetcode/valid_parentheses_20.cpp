https://leetcode.com/problems/valid-parentheses/

bool isValid(string s) {
        stack<char> st;
        if(s.length()==0) return true;
        for(auto &i:s){
           switch(i){
               case '(':
                   st.push(i);
                   break;
               case '{':
                   st.push(i);
                   break;
               case '[':
                   st.push(i);
                   break;
               case ')':
                   if(!st.empty()&&st.top()=='('){
                       st.pop();
                   }else{
                       return false;
                   }
                   break;
               case '}':
                   if(!st.empty()&&st.top()=='{'){
                       st.pop();
                   }else{
                       return false;
                   }
                   break;
               case ']':
                   if(!st.empty()&&st.top()=='['){
                       st.pop();
                   }else{
                       return false;
                   }
                   break;
               default:
                   break;
           }
        }
        return st.empty();
        
    }
