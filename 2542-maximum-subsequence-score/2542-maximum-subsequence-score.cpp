class Solution {
    #define ll long long int
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({nums2[i] , nums1[i]});
        }
        ll ans = -1e18;
        ll sum = 0;
        sort(v.rbegin() , v.rend());
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < k; i++){
            pq.push(v[i].second);
            sum += v[i].second;
        }
        ans = sum*(v[k-1].first);
        for(int i = k ; i < n ; i++){
            
            auto it = pq.top();
            pq.pop();
            
            sum -= it;
            sum += v[i].second;
            ll p = v[i].first;
            ll a =  p*sum;

            pq.push(v[i].second);

            ans = max(ans , a);

        }

        return ans;
    }
};