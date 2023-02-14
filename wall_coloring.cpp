//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
       vector<vector<int>>ans(N,vector<int>(3,0));
        for(int i=0;i<3;i++)ans[N-1][i]=colors[N-1][i];
        for(int i=N-2;i>=0;i--){
            ans[i][0]=colors[i][0]+min(ans[i+1][1],ans[i+1][2]);
            ans[i][1]=colors[i][1]+min(ans[i+1][0],ans[i+1][2]);
            ans[i][2]=colors[i][2]+min(ans[i+1][0],ans[i+1][1]);
        }
        return min(ans[0][0],min(ans[0][1],ans[0][2]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
