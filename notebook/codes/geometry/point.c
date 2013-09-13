typedef long long CoordType;
struct Point {
	CoordType x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

