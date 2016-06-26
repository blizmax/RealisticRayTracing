#include "Vector3.h"

istream& operator>>(istream& in, Vector3& v) {
	float temp;
	in >> temp;
	v.e[0] = temp;
	in >> temp;
	v.e[1] = temp;
	in >> temp;
	v.e[2] = temp;
	return in;
}

ostream& operator<<(ostream& out, const Vector3& v) {
	out << '(' 
		<< v.e[0] << ' '
		<< v.e[1] << ' '
		<< v.e[2] << ')';
	return out;
}

float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
	return dot(cross(v1, v2), v3);	
}