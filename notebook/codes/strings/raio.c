#define NN 100001 // tamanho maximo da string
char str[NN], aux[2*NN+1]; // string de entrada
int len; // tamanho string de entrada
int out[2*NN+1]; // vetor de saida com os raios dos palindromos
void buildAux() // pra simplificar a implementacao
{
	for (int i = 0; i < len; ++i)
		aux[i*2] = '#', aux[i*2+1] = str[i];
	aux[len*2] = '#';
}
void manacher() // Manacher Algorithm, O(n)
{
	buildAux();
	int alen = len*2+1, C = 0, R = 0, m; // tamanho, centro, limite, mirror
	for (int i = 0; i < alen; ++i)
	{
		m = C-(i-C); // mirror de i
		out[i] = R > i ? min(R-i, out[m]) : 0; // raio desta posicao
		while (i-1-out[i] >= 0 && i+1+out[i] < alen && aux[i-1-out[i]] == aux[i+1+out[i]]) 
			out[i]++; // expandindo palindromo
		if (i+out[i] > R) C = i, R = i+out[i];
	}
}

