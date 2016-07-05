#include "Image.h"
#include <iostream>
#include <cstdlib> // for exit(-1)
using namespace std;

Image::Image() {}

Image::Image(int width, int height) {
	nx = width;
	ny = height;

	raster = new rgb*[nx];
	for (int i = 0; i < nx; ++i)
		raster[i] = new rgb[ny];
}

Image::Image(int width, int height, rgb background) {
	nx = width;
	ny = height;

	raster = new rgb*[nx];
	for (int i = 0; i < nx; ++i)
	{
		raster[i] = new rgb[ny];
		for (int j = 0; j < ny; ++j)
			raster[i][j] = background;
	}
}

Image::~Image() {
	// need release memory of raster
}

bool Image::set(int x, int y, const rgb& color) {
	if (0 > x || x > nx) return false;
	if (0 > y || y > ny) return false;
	raster[x][y] = color;
	return true;
}

void Image::gammaCorrect(float gamma) {
	rgb temp;
	float power = 1.0 / gamma;
	for (int i = 0; i < nx; ++i)
	{
		for (int j = 0; j < ny; ++j)
		{
			temp = raster[i][j];
			raster[i][j] = rgb(
				pow(temp.r(), power),
				pow(temp.g(), power),
				pow(temp.b(), power)
				);
		}
	}
}

void Image::writePPM(ostream& out) {
	out << "P6\n";
	out << nx << ' ' << ny << '\n';
	out << "255\n";

	int i, j;
	unsigned int ired, igreen, iblue;
	unsigned char  red, green, blue;

	for (i = ny - 1; i >= 0; i--)
		for (j = 0; j < nx; j++)
		{
			ired = (unsigned int)(256 * raster[i][j].r());
			igreen = (unsigned int)(256 * raster[i][j].g());
			iblue = (unsigned int)(256 * raster[i][j].b());
			if (ired > 255) ired = 255;
			if (igreen > 255) igreen = 255;
			if (iblue > 255) iblue = 255;
			red = (unsigned char) ired;
			green = (unsigned char) igreen;
			blue = (unsigned char) iblue;
			out.put(red);
			out.put(green);
			out.put(blue);
		}
}

void Image::readPPM(string file_name) {
	ifstream in;
	in.open(file_name.c_str());
	if (!in.is_open()) {
		cerr << " Error -- Could not open file \'" << file_name << "\'\n";
		exit(-1);
	}

	char ch, type;
	char red, green, blue;
	int i, j, cols, rows;
	int num;

	in.get(ch);
	in.get(type);
	in >> cols >> rows >> num;

	nx = cols;
	ny = rows;

	raster = new rgb*[nx]; // need check and release memory
	for (int i = 0; i < nx; ++i)
	{
		raster[i] = new rgb[ny];
	}

	in.get(ch);
	for (int i = ny-1; i >= 0; ++i)
	{
		for (int j = 0; j < nx; ++j)
		{
			in.get(red);
			in.get(green);
			in.get(blue);
			raster[i][j] = rgb(
				(float)((unsigned char)red)/255.0,
				(float)((unsigned char)green)/255.0,
				(float)((unsigned char)blue)/255.0
				);
		}
	}
}

rgb Image::getPixel(int x, int y) const
{
	return raster[x][y];
}
