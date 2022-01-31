struct SegmentNode{
    int m_sum;
    int m_start;
    int m_end;
    SegmentNode *m_left;
    SegmentNode *m_right;
    SegmentNode(
        int sum, 
        int start,
        int end, 
        SegmentNode *left=nullptr,
        SegmentNode *right=nullptr
    ):
        m_sum(sum),
        m_start(start),
        m_end(end),
        m_left(left),
        m_right(right){}
};

// Implement Segment Tree
class NumArray {
public:
    NumArray(vector<int>& nums){
        m_root = buildTree(nums, 0, nums.size()-1);
    }
    SegmentNode* buildTree(vector<int>& nums, int start, int end){
        if(start == end){ return new SegmentNode(nums[start], start, end); }
        
        int mid = (start + end) / 2;
        SegmentNode *left  = buildTree(nums, start, mid);
        SegmentNode *right = buildTree(nums, mid+1, end);
        return new SegmentNode(
                        (left->m_sum) + (right->m_sum),
                        start,
                        end,
                        left,
                        right
                    );
    }
    
    void update(int index, int val){
        update(index, val, m_root);
        return;
    }
    
    int sumRange(int start, int end){
        return sumRange(start, end, m_root);
    }
    
    void deleteTree(SegmentNode *root){
        if(!root){ return; }
        deleteTree(root->m_left);
        deleteTree(root->m_right);
        delete root;
    }
    
    ~NumArray(){
        deleteTree(m_root);
    }
private:
    void update(int index, int val, SegmentNode *root){
        // cout << "index: " << index << endl;
        // cout << "m_start: " << root->m_start << ", m_end: " << root->m_end << endl;
        if(((root->m_start) == index) && ((root->m_end) == index)){
            root->m_sum = val;
            return;
        }
        
        int mid = ((root->m_start) + (root->m_end)) / 2;
        SegmentNode *updatedNode = ((index <= mid) ? (root->m_left) : (root->m_right)); 
        update(index, val, updatedNode);
        root->m_sum = (root->m_left->m_sum) + (root->m_right->m_sum);
        return;
    }
    
    int sumRange(int start, int end, SegmentNode *root){
        if(((root->m_start) == start) && ((root->m_end) == end)){
            return root->m_sum;
        }
        
        int mid = ((root->m_start) + (root->m_end)) / 2;
        if(start > mid){
            return sumRange(start, end, root->m_right);
        }else if(end <= mid){
            return sumRange(start, end, root->m_left);
        }
        return sumRange(start, mid, root->m_left) + 
               sumRange(mid+1, end, root->m_right);
    }
private:
    SegmentNode *m_root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
/* Two Layer Search
class NumArray {
public:
    NumArray(vector<int>& nums):rowsNumbers(300), numPrefix(ceil(nums.size()/rowsNumbers)+1), prefix(numPrefix, vector<int>(rowsNumbers, 0)) {
        arr = nums;
        
        int n_prefix=0, n_row=0;
        for(int i=0; i<arr.size(); ++i){
        
            n_prefix = i / rowsNumbers;
            n_row    = i % rowsNumbers;
            if(n_row == 0){
                prefix[n_prefix][0] = arr[i];       
            }
            else{
                prefix[n_prefix][n_row] = (arr[i] + prefix[n_prefix][n_row-1]);           
            }
        }
    }
    
    void update(int index, int val) {
        int diff = (arr[index] - val);
        
        int n_prefix = index / rowsNumbers;
        int n_row    = index % rowsNumbers; 
        
        arr[index] = val;
        for(int i=n_row; i<rowsNumbers; ++i){
            prefix[n_prefix][i] = prefix[n_prefix][i] - diff; 
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int left_prefix = left / rowsNumbers;
        int left_row    = left % rowsNumbers; 
        
        int right_prefix = right / rowsNumbers;
        int right_row    = right % rowsNumbers;
        
        
        if(left_prefix == right_prefix){
            if(left_row == 0){ return prefix[left_prefix][right_row]; }
            else{ return prefix[left_prefix][right_row] - prefix[left_prefix][left_row-1]; }
        }
        
        
        if(left_row == 0){ sum += prefix[left_prefix][rowsNumbers-1]; }
        else{ sum += prefix[left_prefix][rowsNumbers-1] - prefix[left_prefix][left_row-1]; }        
        left_prefix += 1;
        
        while(left_prefix < right_prefix){
            sum += prefix[left_prefix][rowsNumbers-1];
            left_prefix = left_prefix + 1;
        }
        
        sum += prefix[left_prefix][right_row];
        return sum;

    }
private:
    const int rowsNumbers;
    int numPrefix;
    vector<int> arr;
    vector<vector<int>> prefix;
};
*/

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

