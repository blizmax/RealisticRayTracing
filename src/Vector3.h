#ifndef VECTOR3_H
#define VECTOR3_H 1

#include <cmath>
#include <istream>
using namespace std;

class Vector3
{
public:
	Vector3() {}
	Vector3(float e0, float e1, float e2);
	Vector3(const Vector3& v) { *this = v; }
	
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }
	
	const Vector3& operator + () const;
	Vector3 operator - () const;

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	float length() const;
	float squaredLength() const;

	void makeUnitVector();

	void setX(float _x) { e[0] = _x; }
	void setY(float _y) { e[1] = _y; }
	void setZ(float _z) { e[2] = _z; }
	float minComponent() const;
	float maxComponent() const;
	float minAbsComponent() const;
	float maxAbsComponent() const;
	int indexOfMinComponent() const;
	int indexOfMaxComponent() const;
	int indexOfMinAbsComponent() const;
	int indexOfMaxAbsComponent() const;

	friend bool operator==(const Vector3& v1, const Vector3& v2);
	friend bool operator!=(const Vector3& v1, const Vector3& v2);

	friend istream& operator>>(istream& in, Vector3& v);
	friend ostream& operator<<(ostream& out, const Vector3& v);

	friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator/(const Vector3& v, float k);
	friend Vector3 operator*(const Vector3& v, float k);
	friend Vector3 operator*(float k, const Vector3& v);

	Vector3& operator=(const Vector3& v);
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(const float t);
	Vector3& operator/=(const float t);

	friend Vector3 unitVector(const Vector3& v);
	friend Vector3 minVec(const Vector3& v1, const Vector3& v2);
	friend Vector3 maxVec(const Vector3& v1, const Vector3& v2);
	friend Vector3 cross(const Vector3& v1, const Vector3& v2);
	friend float dot(const Vector3& v1, const Vector3& v2);
	friend float tripleProduct(
		const Vector3& v1, const Vector3& v2, const Vector3& v3);

	float e[3];
};

inline Vector3::Vector3(float e0, float e1, float e2) {
	e[0] = e0; e[1] = e1; e[2] = e2;
}


inline const Vector3& Vector3::operator + () const {
	return *this;
}

inline Vector3 Vector3::operator - () const {
	return Vector3(-e[0], -e[1], -e[2]);
}


inline float Vector3::length() const {
	return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

inline float Vector3::squaredLength() const {
	return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];	
}

inline void Vector3::makeUnitVector() {
	*this = *this / (this->length());
}

inline float Vector3::minComponent() const {
	float temp = e[0];
	if (e[1] < temp) temp = e[1];
	if (e[2] < temp) temp = e[2];
	return temp;
}

inline float Vector3::maxComponent() const {
	float temp = e[0];
	if (e[1] > temp) temp = e[1];
	if (e[2] > temp) temp = e[2];
	return temp;
}

inline float Vector3::minAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) < temp) temp = fabs(e[1]);
	if (fabs(e[2]) < temp) temp = fabs(e[2]);
	return temp;
}

inline float Vector3::maxAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) > temp) temp = fabs(e[1]);
	if (fabs(e[2]) > temp) temp = fabs(e[2]);
	return temp;
}

inline int Vector3::indexOfMinComponent() const {
	int index = 0;
	int temp = e[0];
	if (e[1] < temp) temp = e[1], index = 1;
	if (e[2] < temp) index = 2;
	return index;
}

inline int Vector3::indexOfMaxComponent() const {
	int index = 0;
	int temp = e[0];
	if (e[1] > temp) temp = e[1], index = 1;
	if (e[2] > temp) index = 2;
	return index;
}
inline int Vector3::indexOfMinAbsComponent() const {
	int index = 0;
	int temp = fabs(e[0]);
	if (fabs(e[1]) < temp) temp = fabs(e[1]), index = 1;
	if (fabs(e[2]) < temp) index = 2;
	return index;
}
inline int Vector3::indexOfMaxAbsComponent() const {
	int index = 0;
	int temp = fabs(e[0]);
	if (fabs(e[1]) > temp) temp = fabs(e[1]), index = 1;
	if (fabs(e[2]) > temp) index = 2;
	return index;	
}

inline bool operator==(const Vector3& v1, const Vector3& v2) {
	if (v1.e[0] != v2.e[0]) return false;
	if (v1.e[1] != v2.e[1]) return false;
	if (v1.e[2] != v2.e[2]) return false;
	return true;
}

inline bool operator!=(const Vector3& v1, const Vector3& v2) {
	return !(v1 == v2);
}

inline Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}

inline Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}

inline Vector3 operator/(const Vector3& v, float k) {
	return Vector3(v.e[0] / k, v.e[1] / k, v.e[2] / k);
}
inline Vector3 operator*(const Vector3& v, float k) {
	return Vector3(v.e[0] * k, v.e[1] * k, v.e[2] * k);
}

inline Vector3 operator*(float k, const Vector3& v) {
	return Vector3(v.e[0] * k, v.e[1] * k, v.e[2] * k);
}

inline Vector3& Vector3::operator=(const Vector3& v) {
	e[0] = v.e[0];
	e[1] = v.e[1];
	e[2] = v.e[2];
	return *this; // ?
}

inline Vector3& Vector3::operator+=(const Vector3& v) {
	*this = *this + v;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& v) {
	*this = *this - v;
	return *this;
}
inline Vector3& Vector3::operator*=(const float t) {
	*this = *this * t;
	return *this;
}

inline Vector3& Vector3::operator/=(const float t) {
	*this = *this / t;
	return *this;
}

inline Vector3 unitVector(const Vector3& v) {
	float length = v.length();
	return v / length;
}

inline Vector3 minVec(const Vector3& v1, const Vector3& v2) {
	Vector3 vec(v1);
	if (v2.x() < v1.x()) vec.setX(v2.x());
	if (v2.y() < v1.y()) vec.setY(v2.y());
	if (v2.z() < v1.z()) vec.setZ(v2.z());
	return vec;
}

inline Vector3 maxVec(const Vector3& v1, const Vector3& v2) {
	Vector3 vec(v1);
	if (v2.x() > v1.x()) vec.setX(v2.x());
	if (v2.y() > v1.y()) vec.setY(v2.y());
	if (v2.z() > v1.z()) vec.setZ(v2.z());
	return vec;
}

inline Vector3 cross(const Vector3& v1, const Vector3& v2) {
	Vector3 temp;
	temp.e[0] = v1.y() * v2.z() - v1.z() * v2.y();
	temp.e[1] = v1.z() * v2.x() - v1.x() * v2.z();
	temp.e[2] = v1.x() * v2.y() - v1.y() * v2.x();
	return temp;
}

inline float dot(const Vector3& v1, const Vector3& v2) {
	return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

#endif