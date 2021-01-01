https://www.interviewbit.com/problems/largest-number/

bool compare(int a,int b){
        string x = to_string(a);
        string y = to_string(b);
        return ((x+y)>(y+x));
    }

string Solution::largestNumber(const vector<int>& A) {
        vector<int> vec;
        
        for(int i = 0;i<A.size();i++)
        {
            vec.push_back(A[i]);
        }
        int n = vec.size();
        if(n==0) return "";
        sort(vec.begin(),vec.end(),compare);
        int count=0;
        string ans;
        for(int i=0;i<n;i++){
            if(vec[i]==0) count++;
            ans+=to_string(vec[i]);
            
        }
        if(vec.size()==count) return ans="0";
        else return ans;
}
