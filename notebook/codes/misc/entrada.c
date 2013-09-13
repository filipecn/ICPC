#define getcx getchar_unlocked
inline void inp( int &n )
{
	char ch=getcx(); n=0;
	while( ch < '0' || ch > '9' ){ch=getcx();}
	while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
} 

