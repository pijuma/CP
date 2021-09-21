#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5 ; 
const int inf = 1e9 ; 

typedef pair<int, pair<int, int> > piii;

void print(piii a) { printf("%d %d %d\n", a.first, a.second.first, a.second.second); }

struct line {
	int x1, y1, x2, y2;

	bool operator <(const line& ot) const {
		if (x1 != ot.x1) return x1 < ot.x1;
		return y1 < ot.y1;
	}

	void print() { printf("%d %d %d %d\n", x1, y1, x2, y2) ; }
};

int N, M;
vector<int> g[maxn];
piii vert[maxn], hor[maxn];
line bb[maxn];

void join(piii* vet) {

	sort(vet, vet + N);
	int k = 0;
	
	for(int i = 0 ; i < N ; i++) {
		int ff = vet[i].first, first = vet[i].second.first, l = vet[i].second.second;

		while (i < N && vet[i + 1].first == ff &&
			vet[i + 1].second.first == l) {
			l = vet[i + 1].second.second;
			++i;
		}
		vet[k++] = { ff, {first, l} };
	}
}

int s(int xmn, int ymn, int xmx, int ymx, const piii* vet, int n, piii* res) {
	int v = 0;
	for(int i = 0 ; i < n ; i++) {
		auto& val = vet[i]; int X = val.first, Y1 = val.second.first, Y2 = val.second.second;
		if (X > xmn && X < xmx && Y1 < ymx && Y2 > ymn) {
			res[v++] = { X, {max(Y1, ymn), min(Y2, ymx)} };
		}
	}
	return v;
}

piii vertt[maxn][maxn], vhorr[maxn][maxn];

int r(int xmn, int ymn, int xmx, int ymx, const piii* vetv, int n, const piii* veth, int m) {
	
	auto& vert = vertt[M]; auto& hor = vhorr[M];
	int v = s(xmn, ymn, xmx, ymx, vetv, n, vert); int h = s(ymn, xmn, ymx, xmx, veth, m, hor);

	if (v == 0 && h == 0) return -1;
	int u = M++;

	bool achei = false; int u1 = -1, u2 = -1;

	for(int i = 0 ; i < h ; i++){
		if (hor[i].second.first == xmn && hor[i].second.second == xmx) {
			achei = true; bb[u] = { xmn, hor[i].first, xmx, hor[i].first };
			u1 = r(xmn, ymn, xmx, hor[i].first, vert, v, hor, h); u2 = r(xmn, hor[i].first, xmx, ymx, vert, v, hor, h);
			break;
		}
	}
	if (!achei) {
		for(int i = 0 ; i < v ; i++){
			if (vert[i].second.first == ymn && vert[i].second.second == ymx) {
				achei = true; bb[u] = { vert[i].first, ymn, vert[i].first, ymx };
				u1 = r(xmn, ymn, vert[i].first, ymx, vert, v, hor, h); u2 = r(vert[i].first, ymn, xmx, ymx, vert, v, hor, h);
				break;
			}
		}
	}

	if (u1 >= 0) g[u].push_back(u1);
	if (u2 >= 0) g[u].push_back(u2);

	return u;
}

void dfs(int u) {

	set<pair<line, int> > in = { {bb[u], u} };

	while (!in.empty()) {
		auto cur = *in.begin(); in.erase(in.begin());
		cur.first.print(); u = cur.second;
		for (auto v : g[u]) { in.insert({bb[v], v }); }
	}
}

int main() {

	int X1, Y1, X2, Y2, xmn, xmx, ymn, ymx;

	while (true){
		
		scanf("%d", &N); 
		if(!N) return 0;

		xmn = ymn = inf; xmx = ymx = -inf;

		for(int i = 0 ; i < N ; i++){
			scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
			vert[i] = {X2, {Y1, Y2}};	hor[i] = {Y2, {X1, X2}};
			xmn = min(xmn, X1); xmx = max(xmx, X2); ymn = min(ymn, Y1); ymx = max(ymx, Y2);
			g[i].clear();
		}

		join(vert); join(hor);

		M = 0;
		r(xmn, ymn, xmx, ymx, vert, N, hor, N);
		dfs(0);
		printf("\n");
	}
}
