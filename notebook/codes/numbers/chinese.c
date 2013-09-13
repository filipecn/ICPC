LL chineseRemainder(LL* nums, LL* mods, int n)
{
	LL N = 1, R = 0, a, b, g;
	for (int i = 0; i < n; ++i)
		N *= mods[i];
	for (int i = 0; i < n; ++i)
	{
		gcdEx(mods[i], N/mods[i], a, b, g);
		b = ((b%N)*(N/mods[i]))%N;
		LL A = (b*nums[i])%N;
		R = (R+A)%N;
	}
	return ((R%N)+N)%N;
}

