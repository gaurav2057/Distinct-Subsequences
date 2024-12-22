class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        int n=s.size();
        int dp[n+1];
        int prefix[n+1];
        int last[26];
        memset(last,-1,sizeof(last));
        prefix[0]=1;
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=prefix[i-1];
            if(last[s[i-1]-'a']!=-1)
            {
               int index=last[s[i-1]-'a'];
               dp[i]-=prefix[index];
            }
            last[s[i-1]-'a']=i-1;
            prefix[i]=(((prefix[i-1]+dp[i])%mod)+mod)%mod;
        }
        return (((prefix[n]-1)%mod)+mod)%mod;
    }
};