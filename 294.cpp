class Solution {
public:
    //对于先发手来说，有一种选择，能让所有子选择都返回true就行
    //而对于后发手，必须所有的选择都是输才返回true
    bool dfs(string& s, int times)
    {
        if( mWin[times].find(s) != mWin[times].end() )
        {
            return mWin[times][s];
        }

        bool found = false;
        bool allTrue = true;
        bool oneTrue = false;

        for(int i = 0; i < s.size()-1; ++i)
        {
            if(s[i] == '+' && s[i+1] == '+')
            {
                found = true;

                s[i] = s[i+1] = '-';
                bool ret = dfs(s, (times+1)%2 );
                s[i] = s[i+1] = '+';

                if(!ret)allTrue = false;
                if(ret)oneTrue = true;
            }
        }

        bool ret;

        if(!found && times == 1)ret = true;
        else if(found && allTrue && times == 1)ret = true;
        else if(found && oneTrue && times == 0)ret = true;
        else ret = false;

        //cout << s << "|" << times << "|" << ret << endl;
        mWin[times][s] = ret;
        return ret;
    }

    bool canWin(string s) {
        if(s == string(""))return false;

        return dfs(s, 0);
    }

    map<string, bool> mWin[2];
};