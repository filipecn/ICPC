void circle_line()
{
	double dx = x[0]-x[1];
	double dy = y[0]-y[1];
	double dr = sqrt(dx*dx+dy*dy);
	double D = x[0]*y[1]-x[1]*y[0];
	double delta = r*r*dr*dr-D*D; // < 0 => nd; == 0 => 1 ponto; > 0 => 2 pontos
	delta = sqrt(delta);
	double x = (D*dy+sign(dy)*dx*delta)/(dr*dr); // so trocar o + por - no sign, abaixo tbm
	double y = (-D*dx+abs(dy)*delta)/(dr*dr);
}
