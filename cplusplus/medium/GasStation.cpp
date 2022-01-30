/* First solution comes into my mind
diff[i] = gas[i] - cost[i]
prefix_sum[0] = diff[0]
prefix_sum[i] = prefix_sum[i-1] + diff[i]
min_left[i]  = min(prefix_sum[0], ..., prefix_sum[i])
min_right[i] = min(prefix_sum[i], ..., prefix_sum[n])

for i=1 to n
if (min_right[i] - prefix_sum[i-1]) >= 0) && 
   ((min_left[i-1] + prefix_sum[prefix_sum.size()-1] - prefix_sum[i-1]) >= 0)
    return i

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(gas.size() == 1) { return (gas[0] >= cost[0]) ? 0 : -1; }
        
        vector<int> diff(gas.size(), 0);
        for(int i=0; i<gas.size(); ++i){
            diff[i] = gas[i] - cost[i];
        }
        
        vector<int> prefix_sum(diff.size(), 0);
        vector<int> min_left(diff.size(), 0);
        prefix_sum[0] = diff[0];
        min_left[0]   = diff[0];
        int minimal   = diff[0];
        int success   = (prefix_sum[0] >= 0); 
        for(int i=1; i<prefix_sum.size(); ++i){
            prefix_sum[i] = prefix_sum[i-1] + diff[i];
            minimal = min(minimal, prefix_sum[i]);
            min_left[i] = minimal;
            success     = success && (prefix_sum[i] >= 0);
        }
        
        // Success when start from index 0
        if(success){ return 0; }
        
        // Can't travel around the circuit
        if(prefix_sum[prefix_sum.size()-1] < 0){ return -1; }
        
        vector<int> min_right(diff.size(), 0);
        min_right[min_right.size()-1] = prefix_sum[prefix_sum.size() - 1];
        minimal                       = prefix_sum[prefix_sum.size() - 1];
        for(int i=prefix_sum.size()-1; i>=0; --i){
            minimal = min(minimal, prefix_sum[i]);
            min_right[i] = minimal;
        }
        
        for(int i=1; i<prefix_sum.size(); ++i){
            if(((min_right[i] - prefix_sum[i-1]) >= 0) && ((min_left[i-1] + prefix_sum[prefix_sum.size()-1] - prefix_sum[i-1]) >= 0)){
                return i;
            }
        }
        return -1;
    }
};
*/


// Optimal Solution
// If both sum(diff[i]), sum(diff[i] + diff[i+1]) are greater than or equal (>=) to 0, 
// and sum(diff[i], diff[i+1], diff[i+2]) is less than (<) 0.
// It means that i is not the legal start position at the first sec.
// And then we can figure out diff[i+2] < 0.
// Therefore, i+2 is not a legal start position.
// Furthermore, we can find out that 
//     1. diff[i] >= 0 
//     2. sum(diff[i], diff[i+1]) < (-1 * diff[i+2])
// Thus, diff[i+1] < (-1 *  diff[i+2])
// So we knows that i, i+1 and i+2 are not legal start positions
// Then we move the start position to i+3
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(gas.size() == 1) { return (gas[0] >= cost[0]) ? 0 : -1; }
        
        vector<int> diff(gas.size(), 0);
        for(int i=0; i<gas.size(); ++i){
            diff[i] = gas[i] - cost[i];
        }
        
        int current = 0, total = 0, start=0;
        for(int i=0; i<diff.size(); ++i){
            total   += diff[i];
            current += diff[i];
            
            if(current < 0){
                start = i+1;
                current = 0;
            }
        }
        
        return (total >= 0) ? start : -1;
    }
};