//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int sum(vector<int> arr)
    {
        int s =0;
        for(auto it:arr) s+=it;
        return s;
    }
    void solve(int ind, vector<int>&arr, int n, vector<int>&temp, vector<int>&ans)
    {
        if(ind==n)
        {
            ans.push_back(sum(temp));
            return;
        }
        temp.push_back(arr[ind]);
        solve(ind+1, arr, n, temp, ans);
        temp.pop_back();
        solve(ind+1, arr, n, temp, ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> temp;
        solve(0, arr, N, temp, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends