//https://neetcode.io/problems/validate-parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(auto ch: s){
            if(ch == '[' || ch == '(' || ch == '{'){
                stck.push(ch);
            }else if(ch == ']'){
                if(!stck.empty() && stck.top() == '['){
                    stck.pop();
                }else{
                    return false;
                }
            }else if(ch == '}'){
                if(!stck.empty() && stck.top() == '{'){
                    stck.pop();
                }else{
                    return false;
                }
            }else{
                if(!stck.empty() && stck.top() == '('){
                    stck.pop();
                }else{
                    return false;
                }
            }
        }
        return stck.empty();
    }
};

// extra:
// s="["
// s="}"
