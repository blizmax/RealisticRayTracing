#include "Vector2.h"

istream& operator>>(istream& in, Vector2& v) {
	float temp;
	in >> temp;
	v.e[0] = temp;
	in >> temp;
	v.e[1] = temp;
	return in;
}

ostream& operator<<(ostream& out, const Vector2& v) {
	out << '(' 
		<< v.e[0] << ' '
		<< v.e[1] << ')';
	return out;
}
