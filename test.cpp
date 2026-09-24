#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5+5;
long long n, m, k;
struct tuan{
    public:
        long long u, w;
        tuan(){}
        tuan(long long u, long long w){
            this->u=u; this->w=w;
        }
};
struct tuan2{
    public:
        long long w, v;
        tuan2(){}
        tuan2(long long w, long long v){
            this->w=w; this->v=v;
        }
        bool operator<(const tuan2& other) const{
            return w>other.w;
        }
};
vector<tuan> adj[maxn];
priority_queue<long long> d[maxn];
void dijkstra(){
    d[1].push(0);
    priority_queue<tuan2> pq;
    pq.push(tuan2(d[1].top(), 1));
    while(!pq.empty()){
        auto [dist, u] = pq.top(); pq.pop();
        for (auto [v, w]:adj[u]){
            if(d[v].size()>=10 && dist+w>=d[v].top()) continue;
            if(d[v].size()>=10){
                d[v].pop();
            }
            d[v].push(dist+w);
            pq.push(tuan2(dist+w, v));
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for (long long i=1, u, v, w; i<=m; i++){
        cin>>u>>v>>w;
        adj[u].push_back(tuan(v, w));
    }
    dijkstra();
    long long cnt=0;
    vector<long long> res;
    while(!d[n].empty()){
        res.push_back(d[n].top()); d[n].pop();
    }
    sort(res.begin(), res.end());
    for (long long i=0; i<k; i++) cout<<res[i]<<' ';
    return 0;
}