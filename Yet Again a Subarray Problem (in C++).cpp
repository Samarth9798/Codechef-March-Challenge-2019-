#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;

int main()
{
    fast
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        
        int a[n+1];
        int b[n+1];
        
        set<int> s;
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
        } 
        
        memcpy(b,a,sizeof(a));
        
        sort(b,b+n);
        
        if(s.size() == n)
        {
            if(b[0] == 1)
                cout << n << "\n";
            else
                cout << "0\n";
        }
        else
        {
            ll ans = 0;
            
            int c[2001];
            
            for(int i = 0; i < n; i++)
            {
                s.clear();
                memset(c,0,sizeof(c));
                int x;
                int si = 0;
                
                for(int j = i; j < n; j++)
                {
                    si++;
                    s.insert(a[j]);
                    c[a[j]]++;
                    
                    if(si ==  k)
                    {
                        x = *(s.rbegin());
                    }
                    else if(si >= k)
                    {
                        int l = 0;
                        for(auto it = s.begin(); it != s.end(); it++)
                        {
                            l += c[*it];
                            if(l >= k)
                            {
                                x = *it;
                                break;
                            }
                        }
                    }
                    else if(k%si == 0)
                    {
                        x = *(s.rbegin());
                    }
                    else
                    {
                        ll mul = k/si + 1;
                        ll temp = mul * si;
                        
                        for(auto it = s.rbegin(); it != s.rend(); it++)
                        {
                            temp -= (mul * c[*it]);
                            if(temp < k)
                            {
                                x = *it;
                                break;
                            }
                        }
                    }
                    
                    if(c[c[x]] > 0)
                        ans++;
                }
            }
            cout << ans << endl;
        }
    }
}
