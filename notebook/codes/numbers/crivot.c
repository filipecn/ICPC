const int MAX = 20000000 + 1, LMT = sqrt(MAX)+1; // MAX eh o maximo
int flag[(MAX>>6)+1];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31))) // chamar ifc pra testar se eh primo, se retornar falso eh primo (if composite)
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31))) // seta x como composite
void sieve() // da pra por numa linha..
{
        for(int i = 3; i < LMT; i += 2) 
                if(!ifc(i)) 
                        for(int j = i*i, k = i<<1; j < MAX; j += k) 
                                isc(j);
}
