ALL = Run.exe

# Targets



Run.exe :   Pattern.o World.o Nutrient.o main.o
	-g++ -o Run.exe Pattern.o World.o Nutrient.o main.o -I/usr/local/include/Box2D/ -lBox2D
	-[ -e "Build" ] || mkdir "Build"
	-mv *.o *.exe Build

Character.o: Character.cpp Character.h World.h Pattern.h Define.h

	-g++ -c  Character.cpp 


Nutrient.o: Nutrient.cpp

	-g++ -c  Nutrient.cpp



Pattern.o: Pattern.cpp Pattern.h World.h

	-g++ -c  Pattern.cpp 


World.o: World.cpp World.h Pattern.h

	-g++ -c  World.cpp 


main.o: main.cpp World.h Pattern.h

	-g++ -c  main.cpp 


clean : 
	-rm *.o *.exe */*.o */*.exe