// SolidNoise.h_
#ifndef _SOLID_NOISE_H_
#define _SOLID_NOISE_H_ 1

#include "Vector3.h"
#include <cmath>

class SolidNoise {
public:
    SolidNoise();
    float noise(const Vector3&) const;
    float turbulence(const Vector3& p, int depth) const;
    float dturbulence(const Vector3& p, int depth, float d) const;
    float omega(float t) const;
    Vector3 gamma(int i, int j, int k) const;
    int intGamma(int i, int j) const ;
    float knot(int i, int j, int k, Vector3&) const;

    Vector3 grad[16];
    int phi[16];
};

inline float SolidNoise::omega(float t) const {
    t = (t > 0) ? t : -t;
    // we can assume t is in [-1:1] in this code so no extra 'if' needed 
    return (-6.0*t*t*t*t*t*t + 15.0*t*t*t*t - 10.0*t*t*t + 1.0f);
}

inline Vector3 SolidNoise::gamma(int i, int j, int k) const {
    int idx;
    idx = phi[(int)abs(k) % 16];
    idx = phi[(int)abs(j + idx) % 16];
    idx = phi[(int)abs(i + idx) % 16];
    return grad[idx];
}

inline float SolidNoise::knot(int i, int j, int k, Vector3& v) const {
    return (omega(v.x()) * omega(v.y()) * omega(v.z()) * 
        (dot(gamma(i, j, k), v)));
}

inline int SolidNoise::intGamma(int i, int j) const {
    int idx;
    idx = phi[(int)abs(j) % 16];
    idx = phi[(int)abs(i + idx) % 16];
    return idx;
}

#endif // _SOLID_NOISE_H_