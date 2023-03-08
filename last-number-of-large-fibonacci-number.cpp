//the main fact is fibonacci numbers last digit maintain a cycle of 60 length
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

vector<vector<int> > multiply(vector<vector<int> > &a , vector<vector<int> > &b)
{  
   int n = a.size() ;
   vector<vector<int> > ans(n , vector<int>(n,0)) ;

   for(int i  = 0  ;i<n  ;i++)
   {
      for(int j =  0 ; j<n ; j++)
      {
         for(int k = 0 ; k<n ; k++)
         {
             ans[i][j]+=a[i][k]*b[k][j] ;
         }
      }
   }
   return ans ;
}

vector<vector<int> >  matrixexp(vector<vector<int> > &a , int n)
{
 
       if(n==0)
       {  
      int sz = a.size() ;
      vector<vector<int > > ans(sz, vector<int>(sz,0)) ;
          for(int i  = 0 ; i<sz ; i ++)
          {
            ans[i][i] = 1 ;
            
          }
          return ans ;
       }
       if(n==1)
       {
         return a ;
       }

       vector<vector<int> > temp  = matrixexp(a,n/2) ;
       vector<vector<int> >ans = multiply(temp,temp) ;

       if(n&1)
       {
         ans = multiply(ans,a) ;
       }


       return ans; 


}

signed main()
{
int n;
cin>>n;
n = n%60 ;


  vector<vector<int> > a(2,vector<int>(2)) ;
  a[0][0] = a[0][1] = a[1][0] = 1 ;
  a[1][1] =0 ;

  vector<vector<int> > ans = matrixexp(a,n) ; 

  cout<<ans[0][1]%10<<endl;

   return 0 ;
}
