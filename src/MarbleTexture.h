// MarbleTexture.h

#ifndef _MARBLE_TEXTURE_H_
#define _MARBLE_TEXTURE_H_ 1

#include <cmath>
#include "Texture.h"
#include "rgb.h"
#include "SolidNoise.h"

class MarbleTexture : public Texture
{
public:
	MarbleTexture(const rgb& _c0, const rgb& _c1, const rgb& _c2, 
		float stripes_per_unit, float _scale = 3.0, int _octaves = 8)
		: c0(_c0), c1(_c1), c2(_c2)
		{
			freq = M_PI * stripes_per_unit;
			scale = _scale;
			octaves = _octaves;
		}
	
	virtual rgb value(const Vector2& uc, const Vector3& p) const;

	float freq, scale;
	int octaves;
	rgb c0, c1, c2;
	SolidNoise noise;
};
#endif
