void circle_circle(double x1, double y1, double r1, double x2, double y2, double r2)
{
	double d = sqrt(sqr(x1-x2)+sqr(y1-y2));
	//if (r1+r2 < d) // too far
	//if (abs(r1-r2) > d) // inside
	double a = (r1*r1-r2*r2+d*d)/(2*d);
	double px = x1+a*(x2-x1)/d;
	double py = y1+a*(y2-y1)/d;
	double h = sqrt(r1*r1-a*a);
	double X1 = px+h*(y2-y1)/d;
	double Y1 = py-h*(x2-x1)/d;
	double X2 = px-h*(y2-y1)/d;
	double Y2 = py+h*(x2-x1)/d;
}
