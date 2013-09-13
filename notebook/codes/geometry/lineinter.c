/* intersecao de linhas, na forma ax + by + c = 0:
   X = DET |B1 C1| / DET |A1 B1|
   	   |B2 C2|       |A2 B2|
   Y = DET |A1 C1| / DET |B1 A1|
           |A2 C2|       |B2 A2|
*/
void lines_inter(L& l1, L& l2)
{
	if (fabs(l1.a*l2.b-l2.a*l1.b) < EPS) return; // paralelas
	double x = (l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b);
	double y = (l1.a*l2.c-l2.a*l1.c)/(l1.b*l2.a-l2.b*l1.a);
}
