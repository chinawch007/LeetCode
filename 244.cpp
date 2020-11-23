class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i)
        {
            msv[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& v1 = msv[word1];
        vector<int>& v2 = msv[word2];
        int s1 = v1.size();
        int s2 = v2.size();

        int i1 = 0, i2 = 0;
        int mi = 10000000;
        while(1)
        {
            if(i1 == s1-1)
            {
                for(int i = i2; i < s2; ++i)
                {
                    if(abs(v1[i1]-v2[i]) < mi)
                    {
                        mi = abs(v1[i1]-v2[i]);
                    }
                }
                break;
            }

            if(i2 == s2-1)
            {
                for(int i = i1; i < s1; ++i)
                {
                    if(abs(v2[i2]-v1[i]) < mi)
                    {
                        mi = abs(v2[i2]-v1[i]);
                    }
                }
                break;
            }

            if(v1[i1] <= v2[i2])
            {
                if(v2[i2]-v1[i1] < mi)
                {
                    mi = v2[i2] - v1[i1];
                }
                i1++;
            }
            else
            {
                if(v1[i1]-v2[i2] < mi)
                {
                    mi = v1[i1] - v2[i2];
                }
                i2++;
            }
        }

        return mi;
    }

    map<string, vector<int> > msv;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */