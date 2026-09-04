class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix="";

        for(int i=0;strs[0][i]!='\0';i++)
        {
            char s=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
            if(i >= strs[j].size() || strs[j][i] != s) return prefix;
            }
            prefix+=s;
        }
        return prefix;
    }
};