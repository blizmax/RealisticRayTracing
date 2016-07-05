#include "MarbleTexture.h"

rgb MarbleTexture::value(const Vector2& uv, const Vector3& p) const
{
	float temp = scale * noise.turbulence(freq * p, octaves);
	float t = 2.0 * fabs(sin(freq * p.x() + temp));

	if (t < 1.0f)
		return c1 * t + (1.0 - t) * c2;
	else
	{
		t -= 1.0f;
		return c0 * t + (1.0 - t) * c1;
	}
}