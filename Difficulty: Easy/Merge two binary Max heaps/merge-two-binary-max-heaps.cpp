//1st we will bring all the vectors together in 1 vector
//then we will apply heapify property on this new vector
class Solution {
public:

    void heapify(vector<int>& MergedHeapsVector, int i, int n){
        int largest = i;
        int left = 2*i +1;
        int right = 2*i +2;

        if(left < n && MergedHeapsVector[largest]<MergedHeapsVector[left]) largest = left;
        if(right < n && MergedHeapsVector[largest]<MergedHeapsVector[right]) largest = right;

        if(largest != i){
            swap(MergedHeapsVector[i], MergedHeapsVector[largest]);
            //do it for the remaining because there are still some chances
            heapify(MergedHeapsVector, largest, n);
        }
    }


    vector<int> mergeHeaps(vector<int> &heap1, vector<int> &heap2, int n1, int m1) {
        vector<int> MergedHeapsVector(heap1.begin(), heap1.end());
        MergedHeapsVector.insert(MergedHeapsVector.end(), heap2.begin(), heap2.end());


        //heapify
        int n = MergedHeapsVector.size();
        for(int i=n/2-1; i>=0; i--){ //half because we do swaping in heapify
            heapify(MergedHeapsVector, i, n);
        }

        return MergedHeapsVector;
    }
};