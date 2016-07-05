// SimpleTexture.h
#ifndef _SIMPLE_TEXTURE_H
#define _SIMPLE_TEXTURE_H 1

#include "Texture.h"

class SimpleTexture : public Texture
{
public:
	SimpleTexture(rgb c) { color = c; }
	virtual rgb value(const Vector2&, const Vector3&) const { return color; }

	rgb color;
};

#endif
