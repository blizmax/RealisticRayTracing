OBJECTS = Image.o Vector3.o ONB.o Triangle.o Sphere.o

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

main.exe: Vector3.h $(OBJECTS)
	g++ main.cpp $(OBJECTS) -o main.exe -O2

clear:
	rm *.o