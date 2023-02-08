//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long int count = n*n;
      vector<long long int> ans;
      vector<int> row(n, 0);
      vector<int> col(n, 0);
      int rowOnes = 0;
      int colOnes = 0;
      int j = 0;
      for(auto i : arr){
          int flag1 = 1;
          int flag2 = 1;
          if(row[i[0] - 1] == 1){
              flag1 = 0;
          }
          if(col[i[1] - 1] == 1){
              flag2 = 0;
          }
          if(flag1 == 0 && flag2 == 0){
              ans.push_back(count);
              continue;
          }
          if(flag1 == 0 && flag2 == 1){
              count = count - n + rowOnes;
              colOnes++;
          }
          if(flag1 == 1 && flag2 == 0){
              count = count - n + colOnes;
              rowOnes++;
          }
          if(flag1 == 1 && flag2 == 1){
              count = count - 2*n + colOnes + rowOnes + 1;
              rowOnes++;
              colOnes++;
          }
          ans.push_back(count);
          row[i[0] - 1] = 1;
          col[i[1] - 1] = 1;
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
