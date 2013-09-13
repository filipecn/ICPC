int A[N], P[N], pc = 1;
void process()
{
	for (int i = 2; i < N; ++i)
	{
		if (!A[i]) A[i] = pc, P[pc++] = i;
		for (int j = 0; j <= A[i] && i*P[j] < N; ++j) A[i*P[j]] = j;
	}
}
bool prime(int a)
{
	return P[A[a]] == a;
}
void factors(int a)
{
	while (a > 1) printf(" %d", P[A[a]]), a /= P[A[a]];
}
int main()
{
	process();
	
	while (1)
	{
		int a;
		scanf("%d", &a);
		if (prime(a)) printf("PRIME\n");
		else printf("NOT PRIME\n");
		
		printf("FACTORS:");
		factors(a);
		printf("\n");
	}
	
	return 0;
}

