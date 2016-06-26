#ifndef IMAGE_H
#define IMAGE_H 1

#include <cmath>
#include <string>
#include <fstream>
#include "rgb.h"
using namespace std;

class Image
{
public:
	Image();
	Image(int width, int height);
	Image(int width, int height, rgb background);
	~Image();
	
	bool set(int x, int y, const rgb& color);
	void gammaCorrect(float gamma);
	void writePPM(ostream& out);
	void readPPM(string file_name);

private:
	rgb** raster;
	int nx;
	int ny;
};

#endif