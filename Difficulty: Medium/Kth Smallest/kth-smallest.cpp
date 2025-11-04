class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        //1st put in the k elements in the maxHeap
        for(int i=0; i<k; i++)pq.push(arr[i]);
        
        //now push in the rest if its less than the top
        for(int i=k; i<=arr.size()-1; i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
        
    }
};