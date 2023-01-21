//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int k = __builtin_popcount(b);      //num_of_bits_in_b
        int x = 0;
        for(int i = 30;i >= 0&&k; i--){
            if(a&(1 << i)){
                x |= (1 << i);
                k--;
            }
        }
        
        for(int i = 0;i <30&&k;i++){
            if((x&(1<<i))==0){
                x |= (1<<i);
                k--;
            }
        }
        
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
