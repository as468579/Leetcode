class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): pq(nums.begin(), nums.end()), max_size(k){      
        // O(n + (n-k)lg(n-k)) 
        while(pq.size() > k){
            pq.pop();
        }
    }
    int add(int val){
        if(pq.size() < max_size){
            pq.push(val);
        }else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int max_size;
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// 2 3 4 4 5 5 8 9 10
