//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int count=0,ans=0;
    
    int start=0,end=0,flag=0;

    while(end<n)
    {
        flag=0;
        
        while(arr[end]==1)
        {
            end++;
            start=end;
            flag=1;
        }
        if(flag==1) continue;
        
        ans+=end-start+1;
        end++;
    }
    
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends
