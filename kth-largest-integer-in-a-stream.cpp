//https://neetcode.io/problems/kth-largest-integer-in-a-stream
class KthLargest {
public:
    int k_th;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        k_th = k;
        v = nums;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        int index = v.size()-k_th;
        return v[index];
    }
};
