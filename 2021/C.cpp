#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()

vector<string> in[100009];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    //freopen("f.txt", "r", stdin);
    //freopen("f_output.txt", "w", stdout);


    int D, I, S, V, F;
    cin>>D>>I>>S>>V>>F;

    for(int i = 0; i < S; i++)
    {
        int u, v; cin>>u>>v;
        string s; cin>>s;
        int l; cin>>l;

        in[v].push_back(s);
    }

    map<string, int> cnt;
    for(int i = 0; i < V; i++)
    {
        int p; cin>>p;
        string str;

        for(int j = 0; j < p; j++)
        {
            cin>>str;
            cnt[str]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < I; i++)
    {
        vector<pair<int, string>> v;
        int total = 0;
        for(string st : in[i])
        {
            if(!cnt[st]) continue;

            v.push_back({cnt[st], st});
            total += cnt[st];
        }

        if(!total || v.size() == 0) continue;
        ans++;
    }

    cout<<ans<<"\n";
    for(int i = 0; i < I; i++)
    {
        vector<pair<int, string>> v;
        int total = 0;
        for(string st : in[i])
        {
            if(!cnt[st]) continue;

            v.push_back({cnt[st], st});
            total += cnt[st];
        }

        if(!total || v.size() == 0) continue;

        cout<<i<<"\n";
        cout<<v.size()<<"\n";


        for(pair<int, string> p : v)
        {
            double per = 1.0 * p.first / total;
            cout<<p.second<<" "<<max(1, (int)(per * 3))<<"\n";
        }
    }
}
