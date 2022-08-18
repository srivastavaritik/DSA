class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        int sum=0, c=0;
        vector<int> s;
        for(auto it:mpp)
        {
            s.push_back(it.second);
        }
        // if(s.size()==1) return 1;
        sort(s.begin(), s.end());
        for(int i=s.size()-1; i>=0 ;i--)
        {
            if(sum<(arr.size()/2)){
                sum += s[i];
                c++;
            }

        }
        return c;
    }
};