#define  gamma  0.5772156649
double Bn[] = {1.0/6.0, -1.0/30.0, 1.0/42.0, -1.0/30.0, 5.0/66.0};
double Hn(int n) {
    if(n <= 0) return 0;
    double r = 0;
    int i;
    if(n <= 1000) {
        for(i = 1; i <= n; i++) {
            r += (1.0/(double)i);
        }
        return r;
    }
    r = log(n) + gamma;
    r += + 0.5/n;
    for(i = 0; i < 5; i++) {
        r -= (Bn[i] / (2.0*(i+1)*pow(n,2*(i+1)))) ;
    }
    return r;
}

