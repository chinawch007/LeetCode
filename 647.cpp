//注意中心的2中情况，一种是一个字符，一种是2个字符
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;
        
        for(int i = 0; i < n-1; ++i)
        {
            mid(s, n, i, i, ret);
            cout << ret << endl;
            mid(s, n, i, i+1, ret);
            cout << ret << endl;
        }
        mid(s, n, n-1, n-1, ret);
        
        return ret;
    }
    
    void mid(string& s, int n, int i, int j, int& sum)
    {
        //这地方原来写成++了
        while(i>=0 && j<n && s[i--] == s[j++])sum++;
    }
};
