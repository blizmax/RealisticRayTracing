#ifndef _SHAPE_H_
#define _SHAPE_H_ 1

#include "Ray.h"
#include "Vector2.h"
#include "Vector3.h"
#include "rgb.h"
#include "Texture.h"

class Ray;
class rgb;

struct HitRecord
{
	float t;
	Vector3 normal;
	Vector2 uv;
	Vector3 hit_p;
	Texture* hit_tex;
	rgb color;
};

class Shape
{
public:
	virtual bool hit(const Ray& r, float tmin, float tmax, float time,
		HitRecord& record) const = 0;
	virtual bool shadowHit(const Ray& r, float tmin, float tmax, 
		float time) const = 0;
};

#endif
