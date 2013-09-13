#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define F first
#define S second
const int MAXN = 1 << 17;
int N, delta;
char text[MAXN];
pair<int, int> sa[MAXN];
int pos[MAXN];
int tmp[MAXN];
int lcp[MAXN];
bool sufCmp(pair<int, int> a, pair<int, int> b)
{
	int i = a.F, j = b.F;
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += delta; j += delta;
	if (i < N && j < N) return pos[i] < pos[j];
	return i > j;
}
int main()
{
	scanf( "%[^\n]", text );
	
	// init
	N = strlen(text);
	REP(i, N) sa[i] = mp(i, i), pos[i] = text[i];
	
	// suffix array
	for (delta = 1;; delta *= 2)
	{
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N) pos[sa[i].F] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
	
	// LCP
	for (int i = 0, k = 0; i < N; i++) if (pos[i] != N - 1)
	{
		int j = sa[ pos[i] + 1 ].F;
		while (text[j + k] == text[i + k]) k++;
		lcp[pos[i]] = k;
		if (k > 0) k--;
	}

	REP(i, N) printf( "%d %s %d\n", lcp[i], text + sa[i].F, sa[i].S );

	return 0;
}

