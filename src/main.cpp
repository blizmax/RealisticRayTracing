#include <vector>
#include <iostream>
#include <fstream>
#include "common.h"
#include "Vector3.h"
#include "rgb.h"
#include "Image.h"
#include "Shape.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Sample.h"
#include "Camera.h"
#include "DynSphere.h"

using namespace std;

int main() {
	HitRecord rec;
	bool is_a_hit;
	float tmax;
	Vector3 dir(0, 0, -1);

	std::vector<Shape*> shapes;
	// shapes.push_back( new Sphere(Vector3(250, 250, -1000), 150, 
	// 	rgb(0.2, 0.2, 0.8) ) );
	// shapes.push_back( new Triangle( Vector3(300.0f, 600.0f, -800),
	// 								Vector3(0.0f, 100.0f, -1000),
	// 								Vector3(450.0f, 20.0f, -1000),
	// 								rgb(0.8, 0.2, 0.2) ) );

	shapes.push_back( new DynSphere(Vector3(250, 250, -1000), 150, 
		rgb(0.2, 0.2, 0.8), 0.0, 10.0) );

	Image img(500, 500);

	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; ++j)
		{
			tmax = 100000.0f;
			is_a_hit = false;
			Ray r(Vector3(i, j, 0), dir);

			// loop over list of shapes
			for (int k = 0; k < shapes.size(); ++k)
			{
				if (shapes[k]->hit(r, .00001f, tmax, int(drand48()*10), rec))
				{
					tmax = rec.t;
					is_a_hit = true;					
				}
			}

			if (is_a_hit)
				img.set(i, j, rec.color);
			else
				img.set(i, j, rgb(.2, .2, .2));
		}

	img.writePPM(cout);
	return 0;
}