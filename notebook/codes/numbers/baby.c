LL solve(LL a, LL b, LL n) // baby step giant step, a^x = b mod n! gcd(a, n) == gcd(b, n) == 1 !!
{
	if (gcd(a, n) != 1 || gcd(b, n) != 1) return -1;
	vector<pair<LL, LL> > v;
	LL m = sqrt(n)+1, aa = 1;
	// baby step
	for (LL j = 0; j < m; ++j)
	{
		v.push_back(mp(aa, j));
		aa = aa*a;
		if (aa > n) aa %= n;
	}
	sort(v.begin(), v.end());
	LL in = inverse(a, n);
	in = modexp(in, m, n);
	// giant step
	LL y = b;
	for (LL i = 0; i < n/m+1; ++i)
	{
		typeof(v.begin()) f = lower_bound(v.begin(), v.end(), mp(y, 0LL));
		if (f != v.end() && f->F == y) return i*m+f->S;
		y = (y*in);
		if (y > n) y %= n;
	}
	return -1;
}

