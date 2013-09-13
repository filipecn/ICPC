#define N 2000010
int z[N]; // z[0] = 0
char s[N];
void build(int n)
{
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) 
	{
		if (i > R || z[i-L] >= R-i+1) 
		{
			L = i; R = max(R, i);
			while (R < n && s[R-L] == s[R]) R++;
			z[i] = R---L;
		}
		else z[i] = z[i-L];
	}
}

