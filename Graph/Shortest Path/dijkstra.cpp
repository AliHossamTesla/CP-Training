/*
Description : shortest path using Dijkstra algorithm's implementation
by : @Tesla
Verification : https://codeforces.com/contest/20/problem/C
*/
template<class T,bool directed>
struct dijkstra{
	using pii = pair<T,int> ;
	int N ,s;
	const long long INF = 1e18 ;
	vector<T>dis;
	vector<int>par;
	vector<vector<pii>> adj;
	dijkstra(){}
	dijkstra(int N){
		this->N = N ;
		dis = vector<T>(N + 1,INF);
		par = vector<int>(N + 1,-1);
		adj = vector<vector<pii>>(N + 1);
	}
	void edge(int u,int v,T w){
		adj[u].push_back({w,v}) ;
		if(!directed) adj[v].push_back({w,u});
	}
	void run(int s){
		this->s = s ;
		priority_queue<pii, vector<pii>, greater<pii>> Q;
		auto add = [&](int u,int v,T d){
			if(dis[v] <= d) return ;
			par[v] = u ;
			Q.push({dis[v] = d,v}) ;
		};
		add(-1,s,0) ;
		while(!Q.empty()){
			int u = Q.top().second ;
			T dist = Q.top().first ;
			Q.pop() ;
			if(dis[u] < dist) continue ;
			for(auto [w,v] : adj[u]) add(u,v,dist + w) ;
		}
	}
	vector<int> path(int v){
		if(dis[v] == INF) return {-1} ;
		vector<int>ans ;
		for(;v != s;v = par[v]) ans.push_back(v);
		ans.push_back(s) ;
		reverse(ans.begin(),ans.end()) ;
		return ans ;
	}
};