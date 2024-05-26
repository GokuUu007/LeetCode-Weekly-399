class Solution {
public:
    
    using ll = long long;
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, int> cnt;
        for (auto &x : nums2)
            x *= k, cnt[x] += 1;
        
        ll ans = 0;
        for (auto &x : nums1) {
            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    ans += cnt[i];
                    if (x / i != i)
                        ans += cnt[x / i];
                }
            }
        }
        return ans;
    }
};
