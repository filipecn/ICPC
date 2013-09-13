void inverses()
{
	r[1] = 1;
	for (int i = 2; i < N; ++i) // N eh o maximo q vc quer calcular
		r[i] = (M - (M / i) * r[M % i] % M) % M; // M eh o modulo!
}
LL inverse(LL a, LL mod) // lembre q so vai ter inverso se gcd(a, mod) == 1
{
	LL x, y, g;
	gcdEx(a, mod, x, y, g);
	return ((x%mod)+mod)%mod;
}
// normal gcd, a e b positivos
LL gcd(LL a, LL b)
{
	if (!b) return a;
	return gcd(b, a%b);
}
// extended euclidean, a e b positivos, retorna x0 e y0
void gcdEx(LL a, LL b, LL& x, LL& y, LL& g)
{
	if (!b) { x = 1; y = 0; g = a; return; }
    	gcdEx(b, a%b, x, y, g);
    	LL x1 = y;
    	LL y1 = x-(a/b)*y;
    	x = x1;
    	y = y1;
}

