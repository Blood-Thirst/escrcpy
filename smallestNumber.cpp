class Solution {
public:
    string smallestNumber(string pattern) 
    {
        pattern='I'+pattern;
        int n=pattern.length();
        vector<int>vis(10,0),arr(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;--i)
        {
            if(pattern[i]=='D')
            {
                ++cnt;
            }
            else
            {
                arr[i]=cnt;
                cnt=0;
            }
        }
        string ans="";
        for(int i=0;i<n;++i)
        {
            if(pattern[i+1]=='D' && pattern[i]=='I')
            {
                int j=1;
                cnt=arr[i];
                while(cnt)
                {
                    if(!vis[j])
                    {
                        --cnt;
                    }
                    ++j;
                }
                while(vis[j])
                {
                    ++j;
                }
                vis[j]=1;
                ans+=to_string(j);
            }
            else if(pattern[i]=='D')
            {
                int j=ans[i-1]-'0';
                while(vis[j])
                {
                    --j;
                }
                vis[j]=1;
                ans+=to_string(j);
            }
            else
            {
                int j=(i==0?1:ans[i-1]-'0');
                while(vis[j])
                {
                    ++j;
                }
                vis[j]=1;
                ans+=to_string(j);
            }
        }
        return ans;
    }
};
