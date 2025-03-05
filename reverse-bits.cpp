//https://neetcode.io/problems/reverse-bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 0;
        while(count < 32){
            uint32_t last = n&1;
            if(count > 0){
                res = res << 1;
            }
            res = res | last;
            n = n >> 1;
            count++;
        }
        return res;
    }
};

// extra:
// 10101000000000000000000000000000
// 10000000000000000000000000110101
