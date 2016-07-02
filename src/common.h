#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef __WIN32__

#include <cstdlib>
inline float Rand( float a_Range ) { return ((float)rand() / RAND_MAX) * a_Range; }

#define drand48() Rand(1.0)

#endif // __WIN32__

#endif