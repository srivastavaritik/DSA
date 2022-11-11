class Solution {
public:
    bool canPlace(int B, int N, vector<int> pos, int sep)
    {
        int balls = 1;
        int location = pos[0];
        for(int i=1;i<=N-1;i++)
        {
            int curr_location = pos[i];
            if(curr_location - location >= sep)
            {
                balls++;
                location = curr_location;
                if(balls == B) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int N = position.size();
        int s=0, e=position[N-1]-position[0];
        int ans=-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(canPlace(m,N,position,mid))
            {
                ans = mid;
                s = mid +1;
            }
            else e=mid-1;
        }
        return ans;
    }
};