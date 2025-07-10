//https://neetcode.io/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n < 3)
            return 1;
        int t_0 = 0;
        int t_1 = 1;
        int t_2 = 1;
        int val = 0;
        for(int i=3; i<=n; i++){
            val = t_2 + t_1 + t_0;
            t_0 = t_1;
            t_1 = t_2;
            t_2 = val;
        }

        return val;
    }
};
