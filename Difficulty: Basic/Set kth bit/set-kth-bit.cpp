class Solution {
  public:
    int setKthBit(int n, int k) {
        return (n | 1<<k);
        
    }
};
