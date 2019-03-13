#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;

int main()
{
    fast
    
    int n;
    
    cin >> n;
    
    string s[n+1],temp;
    
    multimap<char,int> m;
    vector<int> v;
    
    int max_length = 0;
        
    int f = 0;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    
        if(s[i].length() > max_length)
            max_length = s[i].length();
            
        v.push_back(i);
        
    }
    
    f = 0;
    for(int i = 0; i < max_length; i++)
    {
        m.clear();
        for(int j = 0; j < v.size(); j++)
        {
            int k = v[j];
            if(s[k].length() > i)
            {
                m.insert(make_pair(s[k][i],k));
            }
        }
        
        if(f == 0)
        {
            for(auto it = m.begin(); it != m.end(); it++)
            {
                cout << it->second << ' ';
            }
            f = 1;
        }
        else
        {
            for(auto it = m.rbegin(); it != m.rend(); it++)
            {
                cout << it->second << ' ';
            }
            f = 0;
        }
    }
    
}
