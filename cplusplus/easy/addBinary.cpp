
class Solution {
public:
    string addBinary(string a, string b) {
        
        int ind_a = a.length()-1, ind_b = b.length()-1;
        int int_a = 0, int_b = 0, carry = 0, tmp = 0;
        string res = "";
        
        while((ind_a >= 0) || (ind_b >= 0)){
            
            if((ind_a >= 0) && (a[ind_a] == '1')) { int_a = 1; }
            else                                  { int_a = 0; }
            
            if((ind_b >= 0) && (b[ind_b] == '1')) { int_b = 1; }
            else                                  { int_b = 0; }
            
            tmp   = (int_a + int_b + carry) % 2;
            carry = (int_a + int_b + carry) / 2;
            
            res = tmp ? ("1" + res) : ("0" + res);
            if(ind_a >= 0) { ind_a--; }
            if(ind_b >= 0) { ind_b--; }
        }
        
        if(carry) { res = "1" + res; }
        
        return res;
        
    }
};