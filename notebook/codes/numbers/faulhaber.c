struct Num
{
	Num() {}
	Num(LL a, LL b) : a(a), b(b) {}
	LL a, b;
	
	Num operator*(const Num& n) const
	{
		Num ret;
		ret.b = n.b*b;
		ret.a = n.a*a;
		ret.func();
		return ret;
	}
	
	Num operator+(const Num& n) const
	{
		Num ret;
		ret.b = lcm(n.b, b);
		ret.a = (ret.b/b*a) + (ret.b/n.b*n.a);
		ret.func();
		return ret;
	}
	
	void func()
	{
		LL g = gcd(a, b);
		a /= g;
		b /= g;
		LL s = 1;
		if (a < 0) s *= -1;
		if (b < 0) s *= -1;
		a = abs(a);
		b = abs(b);
		a *= s;
	}
	
	void print()
	{
		if (b == 1) printf("%lld", a);
		else printf("%lld/%lld", a, b);
	}
};
Num tab[401][401];
// so chamar pre msm..
void pre()
{
	tab[0][0] = Num(1, 1);
	for (int i = 1; i <= 400; ++i)
	{
		// primeiro calcula outras colunas
		for (int j = 1; j <= i; ++j)
		{
			//printf("%d %d ", i, j);
			//tab[i-1][j-1].print(); printf("\n");
			tab[i][j] = Num(i, j+1)*tab[i-1][j-1];
		}
		// primeira coluna
		Num um(1, 1);
		Num soma(0, 1);
		for (int j = 1; j <= i; ++j)
		{
			soma = soma+tab[i][j];
		}
		soma.a *= -1;
		tab[i][0] = um+soma;
	}
}

