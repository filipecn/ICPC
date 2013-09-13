void circle_triple(int i, int j, double r)
{
	// se mudar a ordem dos circulos da do outro lado
	double dx = circs[j].x - circs[i].x, dy = circs[j].y - circs[i].y; 
	double D = hypot(dx, dy);  
	double r1 = circs[i].r + r, r2 = circs[j].r + r;
	double E = (r1*r1 - r2*r2 + D*D)/(2*D);
	double F = sqrt(r1*r1 - E*E);
	C c(circs[i].x + (E*dx - F*dy)/D, circs[i].y + (F*dx + E*dy)/D, r);
}
