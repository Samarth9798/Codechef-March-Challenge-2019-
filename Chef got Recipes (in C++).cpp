#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fast
    
    int t;
    cin >> t;
    
    map<string, set<string>> pre;
    set<string> pres,pres1;
    string temp,temp1,sss;
    map<string,string> ssss;
    map<string,int> count;
    
    sss = "aeiou";
    int sc = sss.length();
    int sub = pow(2,sc) - 1;
    int cc = 0;
    
    while(sub)
    {
        int tsub = sub;
        int c = 0;
        temp = "";
        
        while(tsub)
        {
            if(tsub&1)
            {
                temp += sss[c];
            }
            c++;
            tsub >>= 1;
        }
        sub--;
        pres.insert(temp);
    }
    
    for(auto it = pres.begin(); it != pres.end(); it++)
    {
        sss = *it;
        sc = sss.length();
        sub = pow(2,sc) - 1;
        pres1.clear();

        while(sub)
        {
            int tsub = sub;
            int c = 0;
            temp = "";
            
            while(tsub)
            {
                if(tsub&1)
                {
                    temp += sss[c];
                }
                c++;
                tsub >>= 1;
            }
            sub--;
            pres1.insert(temp);
        }
        
        pre[*it] = pres1;
    }
    
    for(auto it = pres.begin(); it != pres.end(); it++)
    {
        temp = "aeiou";
        temp1 = "";
        sss = *it;
        
        for(int j = 0; j < temp.length(); j++)
        {
            int f = 0;
            for(int k = 0; k < sss.length(); k++)
            {
                if(sss[k] == temp[j])
                {
                    f = 1;
                    break;
                }
            }
            if(f == 0)
                temp1 += temp[j];
        }
        ssss[sss] = temp1;
        count[sss] = cc;
        cc++;
    }
    
    while(t--)
    {
        ll n;
        cin >> n;
        
        unordered_map<char,int> s;
        string ss[n+1];
        
        for(ll i = 0; i < n; i++)
        {
            cin >> temp;
            ss[i] = "";
            s.clear();
            
            for(ll j = temp.length() - 1; j >= 0; j--)
            {
                if(!s[temp[j]])
                {
                    s[temp[j]] = 1;
                    ss[i] += temp[j];
                }
                if(ss[i].length() == 5)
                    break;
            }
        }
        for(ll i = 0; i < n; i++)
            sort(ss[i].begin(), ss[i].end());
        
        ll ccc[33];
        memset(ccc,0,sizeof(ccc));
        ll ans = 0;
        
        for(ll i = n-1; i >= 0; i--)
        {
            temp = ss[i];
            if(temp.length() < 5)
            {
                for(auto it = pre[temp].begin(); it != pre[temp].end(); it++)
                    ccc[count[*it]]++;
            }
            else
            {
                for(int j = 0; j <= 32; j++) 
                    ccc[j]++;
            }
            if(temp.length() < 5)
            {
                temp1 = ssss[temp];
                sc = ccc[count[temp1]];
                ans += sc;
            }
            else
            {
                ans = ans + (n - (i+1));
            }
        }
        
        cout << ans << "\n";
    }
}
