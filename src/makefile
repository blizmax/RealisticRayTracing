OBJECTS = Image.o Vector3.o ONB.o Triangle.o Sphere.o Vector2.o Sample.o DynSphere.o

Image.o: Image.cpp Image.h rgb.h
	g++ -c Image.cpp -O2

Vector3.o: Vector3.cpp Vector3.h
	g++ -c Vector3.cpp -O2

ONB.o: ONB.cpp ONB.h Vector3.h Vector3.cpp
	g++ -c ONB.cpp -O2

Triangle.o: Triangle.cpp Triangle.h Shape.h Vector3.h rgb.h Ray.h
	g++ -c Triangle.cpp -O2

Sphere.o: Shape.h Sphere.cpp Sphere.h Vector3.h rgb.h Ray.h
	g++ -c Sphere.cpp -O2

Vector2.o: Vector2.cpp Vector2.h
	g++ -c Vector2.cpp -O2

Sample.o: Sample.cpp Sample.h Vector2.cpp Vector2.h
	g++ -c Sample.cpp -O2

DynSphere.o: DynSphere.cpp DynSphere.h
	g++ -c DynSphere.cpp -O2

SolidNoise.o: SolidNoise.cpp SolidNoise.h
	g++ -c SolidNoise.cpp -O2

NoiseTexture.o: NoiseTexture.cpp NoiseTexture.h Texture.h
	g++ -c NoiseTexture.cpp -O2
    
main.exe: main.cpp $(OBJECTS) Camera.h
	g++ main.cpp $(OBJECTS) -o main.exe -O2

clear:
	rm *.o