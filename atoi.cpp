//somehow works 

class Solution {
public:
    int strtoint(char x) {
        if (x == '0') return 0;
        if (x == '1') return 1;
        if (x == '2') return 2;
        if (x == '3') return 3;
        if (x == '4') return 4;
        if (x == '5') return 5;
        if (x == '6') return 6;
        if (x == '7') return 7;
        if (x == '8') return 8;
        return 9;
    }

    int myAtoi(string s) {
        
        //init
        int64_t ans = 0;
        int i = 0;
        bool is_positive = true;

        //sign and whitespace iterator
        for (i; i < s.size(); i++) {
            if (!(s[i] == 45 || s[i] == 43 || s[i] == 32)) break; //break if no sign or whitespace
            if (s[i] == 45) {
                is_positive = false; // -ve
                i++;
                break;
            }
            else if (s[i] == 43) {
                is_positive = true; // +ve
                i++;
                break;
            }
        }
        //num 
        for (i; i < s.size(); i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) break; //break if no num
            if (ans == 0) ans += strtoint(s[i]);
            else {
                //overflow and underflow check
                ans *= 10;
                
                if (is_positive == false && ans > INT32_MAX) return INT32_MIN;
                if (ans > INT32_MAX) return INT32_MAX;
                ans += strtoint(s[i]);
            }
        }

        
        //overflow && underflow check (redundant)
        if (is_positive == false && ans > INT32_MAX) return INT32_MIN;
        if (ans > INT32_MAX) return INT32_MAX;

        //implementing signage
        if (is_positive == false) ans *= -1;

        return ans;
    }
};

//create object and call function myAtoi()
//leetcode problem 8
