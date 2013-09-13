double point_segment(pt& a, pt& b, pt& q)
{
	double dot1 = (b-a)*(q-b); // dot
	if (dot1 > 0) return dist(b, q);
	double dot2 = (a-b)*(q-a); // dot
	if (dot2 > 0) return dist(a, q);
	return fabs(ccw(a, b, q))/distance(a, b);
}

