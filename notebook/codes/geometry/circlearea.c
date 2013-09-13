double circle_area()
{
	double D = sqrt(sqr(c1.x-c2.x) + sqr(c1.y-c2.y));
	if (c1.r+c2.r < D) return; // sem intersecao
	double maior = max(c1.r, c2.r);
	double menor = min(c1.r, c2.r);
	if (maior > menor+D); // um esta contido no outro
	
	double R1 = c1.r;
	double R2 = c2.r;
	double area = PI*R2*R2/2;
	double teta = 2*acos((D*D + R1*R1 - R2*R2)/(2*R1*D));
	double phi = 2*acos((D*D + R2*R2 - R1*R1)/(2*R2*D));
	double S1 = teta*R1*R1/2;
	double S2 = phi*R2*R2/2;
	double H1 = R1*cos(teta/2);
	double H2 = R2*cos(phi/2);
	double S = sqrt(R1*R1 - H1*H1);
	double T1 = H1*S;
	double T2 = H2*S;
	double area = S1-T1+S2-T2; // area final
}

