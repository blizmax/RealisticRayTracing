// ImageTexture.h

#ifndef _IMAGE_TEXTURE_H_
#define _IMAGE_TEXTURE_H_ 1

#include "Image.h"
#include "Texture.h"

class ImageTexture : public Texture
{
public:
	ImageTexture(char* file_name);
	virtual rgb value(const Vector2& uv, const Vector3& p) const;

	Image* image;
};

#endif
