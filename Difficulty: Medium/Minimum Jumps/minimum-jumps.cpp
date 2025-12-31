//M4 SO
//1st we will send 0th index step
//from that we will get how many steps we can go forward
//using forloop we will get through each step, find the cost
//from the overall ans, pick up min value and return the ans
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Edge Case 1: Already at the end
        if (n <= 1) return 0;
        
        // Edge Case 2: Stuck at start
        if (arr[0] == 0) return -1;

        // Initialize variables
        int maxReach = arr[0];  // The farthest we can ever reach
        int steps = arr[0];     // Steps remaining in the current jump
        int jumps = 1;          // We took the first jump
        
        // Iterate from index 1 to n-1
        for (int i = 1; i < n; i++) {
            
            // If we have reached the end, return the jumps needed
            if (i == n - 1) return jumps;
            
            // Update the farthest reach possible from the current position
            maxReach = max(maxReach, i + arr[i]);
            
            // We used one step to get to index i
            steps--;
            
            // If steps becomes 0, it means our current jump has ended.
            // We MUST take another jump now.
            if (steps == 0) {
                jumps++;
                
                // Check if we are stuck (cannot reach any further)
                if (i >= maxReach) return -1;
                
                // Re-initialize steps for the new jump
                // The new range is (maxReach - current_index)
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
};