//Perfect Tree Problem

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

const ll mod = 1e9+7;

vector<ll> v[200005];
ll id[200005];
ll n;
vector<ll> nodes;
ll vis[200005];

void init()
{
    for(ll i = 0; i <= n; i++)
        id[i] = i;
}

void dfs(ll s)
{
    stack<ll> st;
    
    vis[s] = 1;
    
    id[s] = s;
    
    st.push(s);
    
    while( ! st.empty())
    {
        ll p = st.top();
        
        st.pop();
        
        for(ll i = 0; i < v[p].size(); i++)
        {
            if( vis[ v[p][i] ] == 0)
            {
                id[ v[p][i] ] = p;
                vis[ v[p][i] ] = 1;
                st.push( v[p][i] );
            }
        }
    }
}
void bfs(ll x)
{
    queue<ll> q;
    
    q.push(x);
    
    vis[x] = 1;
    
    while( ! q.empty())
    {
        ll temp = q.front();
        q.pop();
        for(ll i = 0; i < v[temp].size(); i++)
        {
            if( vis[ v[temp][i] ] == 0 and id[ temp ] != v[temp][i] )
            {
                nodes.push_back( v[temp][i] );
                
                vis[ v[temp][i] ] = 1;
                
                q.push( v[temp][i] );
            }
        }
    }
    
}

int main()
{
    fast
    
    int t;
    
    cin >> t;
    
    while(t--)
    {
        ll q;
        ll ans = 0;
        
        cin >> n >> q;
        
        ll x,y;
        for(ll i = 0; i <= n; i++)
            v[i].clear();
           
        init();
         
        for(ll i = 0; i < n-1; i++)
        {
            cin >> x >> y;
            
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        memset(vis,0,sizeof(vis));
        dfs(1);
        
        while(q--)
        {
            cin >> x >> y;
            
            x = x ^ ans;
            y = y ^ ans;
            
            nodes.clear();
            memset(vis,0,sizeof(vis));
            
            bfs(x);
            
            ans = 0;
            
            if(nodes.size())
            {
                vector<ll> dist;
                ll distance[200005];
                memset(distance, 0 , sizeof(distance));
                
                for(ll j = 0; j < nodes.size(); j++)
                {
                    distance[ nodes[j] ] = distance[ id[ nodes[j] ] ] + 1;
                    
                    dist.push_back( distance[ nodes[j] ]);
                }
                
                //sort(dist.begin(), dist.end());
                
                ll temp,p;
                
                p = y;
                
                for(ll j = 0; j < dist.size(); j++)
                {
                    temp = (dist[j] * p)%mod;
                    
                    ans = (ans + temp)%mod;
                
                    p = (y * p)%mod;
                }
                
                cout << ans << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
    
}
