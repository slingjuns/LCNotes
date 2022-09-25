// Date: September 25, 2022
class Solution {
public:
    int quickSelect(vector<int> q, int l, int r, int k) {
    if (l >= r) return q[l];
    int pivot_index = l + (r-l) / 2;
    int i = l - 1, j = r + 1, x = q[pivot_index];
    while (i < j)
    {
        do i ++ ; while (q[i] > x);
        do j -- ; while (q[j] < x);
        if (i < j) swap(q[i], q[j]);
    }

    if (j - l + 1 >= k) return quickSelect(q, l, j, k);
    else return quickSelect(q, j + 1, r, k - (j - l + 1));
}
    
  vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> m;
      for (auto num: nums){
          m[num]++;
      }
      
      vector<int> freqs;
      for(auto [k, v]: m) freqs.push_back(v);
      
      // get top k -- quick select
      auto topK_freq = quickSelect(freqs, 0, freqs.size()-1, k);
      cout << topK_freq << endl;
      vector<int> res;
      for(auto [k, v]: m) {
          if(v >= topK_freq) res.push_back(k);
      }
      
      return res;
  }
};
