class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        if(n==0)return 0;
        
        int sz = dec[n];
        int* dp = new int[sz];
        dp[0] = 0;
        int* tmp = new int[n];
        
        for(int i = 1; i < sz; ++i)
        {
            int mi = 0;
            
            //计算每个物品的数量
            bool flag = false;
            int sum = i;
            for(int j = 0; j < n; ++j)
            {
                tmp[j] = sum % 7;
                if(tmp[j] > needs[j]){flag = true;break;}
                
                sum -= tmp[j];
                sum /= 7;
                
                mi += tmp[j] * price[j];
                //cout << tmp[j] << "|";
            }
            if(flag)continue;
            
            
            //逐个大礼包尝试
            for(int k = 0; k < special.size(); ++k)
            {
                bool flag = false;
                for(int l = 0; l < n; ++l)
                {
                    if(special[k][l] > tmp[l])
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag)continue;
                
                int m = 0;
                for(int j = n-1; j >= 1; --j)
                {
                    m += special[k][j];
                    m *= 7;
                }
                m += special[k][0];
                
                if(special[k][n] + dp[i-m] < mi)
                {
                    mi = special[k][n] + dp[i-m];
                }
            }
            
            dp[i] = mi;
            //cout << mi << endl;
        }
        
        int m = 0;
        for(int j = n-1; j >= 1; --j)
        {
            m += needs[j];
            m *= 7;
        }
        m += needs[0];
        //cout << "m:" << m << endl;
        
        return dp[m];
    }
    
    int dec[7] = {1,7,49,343,2401,16807,117649};
};
