#ifndef _VECTOR2_H_
#define _VECTOR2_H_ 1

#include <cmath>
#include <istream>
using namespace std;

class Vector2
{
public:
	Vector2() {}
	Vector2(float e0, float e1);
	Vector2(const Vector2& v) { *this = v; }
	
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	
	const Vector2& operator + () const;
	Vector2 operator - () const;

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	float length() const;
	float squaredLength() const;

	void makeUnitVector();

	void setX(float _x) { e[0] = _x; }
	void setY(float _y) { e[1] = _y; }
	float minComponent() const;
	float maxComponent() const;
	float minAbsComponent() const;
	float maxAbsComponent() const;
	int indexOfMinComponent() const;
	int indexOfMaxComponent() const;
	int indexOfMinAbsComponent() const;
	int indexOfMaxAbsComponent() const;

	friend bool operator==(const Vector2& v1, const Vector2& v2);
	friend bool operator!=(const Vector2& v1, const Vector2& v2);

	friend istream& operator>>(istream& in, Vector2& v);
	friend ostream& operator<<(ostream& out, const Vector2& v);

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator-(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator/(const Vector2& v, float k);
	friend Vector2 operator*(const Vector2& v, float k);
	friend Vector2 operator*(float k, const Vector2& v);

	Vector2& operator=(const Vector2& v);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(const float t);
	Vector2& operator/=(const float t);

	friend Vector2 unitVector(const Vector2& v);
	friend Vector2 minVec(const Vector2& v1, const Vector2& v2);
	friend Vector2 maxVec(const Vector2& v1, const Vector2& v2);
	friend float cross(const Vector2& v1, const Vector2& v2);
	friend float dot(const Vector2& v1, const Vector2& v2);

	float e[2];
};

inline Vector2::Vector2(float e0, float e1) {
	e[0] = e0; e[1] = e1;
}


inline const Vector2& Vector2::operator + () const {
	return *this;
}

inline Vector2 Vector2::operator - () const {
	return Vector2(-e[0], -e[1]);
}


inline float Vector2::length() const {
	return sqrt(e[0]*e[0] + e[1]*e[1]);
}

inline float Vector2::squaredLength() const {
	return e[0]*e[0] + e[1]*e[1];
}

inline void Vector2::makeUnitVector() {
	*this = *this / (this->length());
}

inline float Vector2::minComponent() const {
	float temp = e[0];
	if (e[1] < temp) temp = e[1];
	return temp;
}

inline float Vector2::maxComponent() const {
	float temp = e[0];
	if (e[1] > temp) temp = e[1];
	return temp;
}

inline float Vector2::minAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) < temp) temp = fabs(e[1]);
	return temp;
}

inline float Vector2::maxAbsComponent() const {
	float temp = fabs(e[0]);
	if (fabs(e[1]) > temp) temp = fabs(e[1]);
	return temp;
}

inline int Vector2::indexOfMinComponent() const {
	int index = 0;
	int temp = e[0];
	if (e[1] < temp) index = 1;
	return index;
}

inline int Vector2::indexOfMaxComponent() const {
	int index = 0;
	int temp = e[0];
	if (e[1] > temp) index = 1;
	return index;
}
inline int Vector2::indexOfMinAbsComponent() const {
	int index = 0;
	int temp = fabs(e[0]);
	if (fabs(e[1]) < temp) index = 1;
	return index;
}
inline int Vector2::indexOfMaxAbsComponent() const {
	int index = 0;
	int temp = fabs(e[0]);
	if (fabs(e[1]) > temp) index = 1;
	return index;	
}

inline bool operator==(const Vector2& v1, const Vector2& v2) {
	if (v1.e[0] != v2.e[0]) return false;
	if (v1.e[1] != v2.e[1]) return false;
	return true;
}

inline bool operator!=(const Vector2& v1, const Vector2& v2) {
	return !(v1 == v2);
}

inline Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	return Vector2(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1]);
}

inline Vector2 operator-(const Vector2& v1, const Vector2& v2) {
	return Vector2(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1]);
}

inline Vector2 operator/(const Vector2& v, float k) {
	return Vector2(v.e[0] / k, v.e[1] / k);
}
inline Vector2 operator*(const Vector2& v, float k) {
	return Vector2(v.e[0] * k, v.e[1] * k);
}

inline Vector2 operator*(float k, const Vector2& v) {
	return Vector2(v.e[0] * k, v.e[1] * k);
}

inline Vector2& Vector2::operator=(const Vector2& v) {
	e[0] = v.e[0];
	e[1] = v.e[1];
	return *this; // ?
}

inline Vector2& Vector2::operator+=(const Vector2& v) {
	*this = *this + v;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& v) {
	*this = *this - v;
	return *this;
}
inline Vector2& Vector2::operator*=(const float t) {
	*this = *this * t;
	return *this;
}

inline Vector2& Vector2::operator/=(const float t) {
	*this = *this / t;
	return *this;
}

inline Vector2 unitVector(const Vector2& v) {
	float length = v.length();
	return v / length;
}

inline Vector2 minVec(const Vector2& v1, const Vector2& v2) {
	Vector2 vec(v1);
	if (v2.x() < v1.x()) vec.setX(v2.x());
	if (v2.y() < v1.y()) vec.setY(v2.y());
	return vec;
}

inline Vector2 maxVec(const Vector2& v1, const Vector2& v2) {
	Vector2 vec(v1);
	if (v2.x() > v1.x()) vec.setX(v2.x());
	if (v2.y() > v1.y()) vec.setY(v2.y());
	return vec;
}

inline float cross(const Vector2& v1, const Vector2& v2) {
	float temp;
	temp = v1.x() * v2.y() - v1.y() * v2.x();
	return temp;
}

inline float dot(const Vector2& v1, const Vector2& v2) {
	return v1.x() * v2.x() + v1.y() * v2.y();
}

#endif