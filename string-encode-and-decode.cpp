//https://neetcode.io/problems/string-encode-and-decode
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto s: strs){
            string len = to_string(s.size());
            res.append(len);
            res.append("#");
            res.append(s);
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> v;
        for(int i=0; i<s.size();){
            int len = 0;
            while(i<s.size() && s[i] >= '0' && s[i] <= '9'){
                len = len*10 + s[i] - '0';
                i++;
            }
            i++;
            string str = "";
            while(len-- && i<s.size()){
                str += s[i];
                i++;
            }
            v.push_back(str);
        }
        return v;
    }
};
//[""]
