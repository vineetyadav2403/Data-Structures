https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    vector< int >res ;
int N = A.size();

 if( N == 0 )return res ;
 
 
 int s = 0 ; int mx = INT_MIN ; 
 int l = 0 , r = 0  , L ,R ;
 int cnt = 0 ; 
 for( int i = 0 ; i < N ; i++  )
  {
      int x ; 
      if( A[i] == '1')x = -1 ; 
      else x = 1 ; 
      
      if( A[i] == '1')cnt++;
      
      if( x > s + x )
      {
          l = i ; r = i ;
          s = x ;
      }
      else
      {
          s = s+x ;
      }
      
      
      if( s > mx )
      {
          L = l ; 
          R = r ;
          mx = s ; 
      }
      
      r++; 
      
  }
  
 if( cnt == N )return res ;
 res.push_back(L+1);
 res.push_back(R+1);
 
 return res ;
}
