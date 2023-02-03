//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0,r=1,c=0;
        while(i<R && j<C && i>=0 && j>=0){
            if(matrix[i][j]==0){
                if(r && c==0 ) j++;
                else if(r==1 && c==1)i++;
                else if(r==0 && c) j--;
                else i--;
            }
            else{
                matrix[i][j]=0;
                if(r && c==0) i++,c=1,r=1;
                else if(r==0 && c==1) i--,c=0,r=0;
                else if(r&& c) j--,c=1,r=0;
                else j++, r=1,c=0;
                
            }
        }
        if(i>=R) i--;
        if(j>=C) j--;
        if(i<0) i++;
        if(j<0) j++;
        return {i,j};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
