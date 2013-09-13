/* intersecao de linhas dado dois pontos da linha, 
   reta na forma = s*u+v; u = (p2-p1)/norm; v = p1
   D = DET |DET |x1 1| DET |y1 1||
           |    |x2 1|     |y2 1||
           |DET |x3 1| DET |y3 1||
           |	|x4 1|     |y4 1||
   X = DET |DET |x1 y1| DET |x1 1|| / D
           |    |x2 y2|     |x2 1||
           |DET |x3 y3| DET |x3 1||
           |	|x4 y4|     |x4 1||
   Y = DET |DET |x1 y1| DET |y1 1|| / D
           |    |x2 y2|     |y2 1||
           |DET |x3 y3| DET |y3 1||
           |	|x4 y4|     |y4 1||
*/
void lines_inter(P& p1, P& p2, P& p3, P& p4)
{
	double d = (p1.x-p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*(p3.x-p4.x);
	if (fabs(d) < EPS) return; // paralelas
	double x = ((p1.x*p2.y-p1.y*p2.x)*(p3.x-p4.x)-(p1.x-p2.x)*(p3.x*p4.y-p3.y*p4.x))/d;
	double y = ((p1.x*p2.y-p1.y*p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*(p3.x*p4.y-p3.y*p4.x))/d;
	//if (x < min(p1.x,p2.x) || x > max(p1.x,p2.x)) return false;
	//if (x < min(p3.x,p4.x) || x > max(p3.x,p4.x)) return false;
	//if (y < min(p1.y,p2.y) || y > max(p1.y,p2.y)) return false;
	//if (y < min(p3.y,p4.y) || y > max(p3.y,p4.y)) return false;
}
