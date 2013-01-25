ALL = Run.exe

# Targets



Run.exe :   Pattern.o World.o 
	-g++ -lBox2D -o Run.exe   Pattern.o World.o 
	-[ -e "Build" ] || mkdir "Build"
	-mv *.o *.exe Build

Character.o: Character.cpp Character.h World.h Pattern.h Define.h

	-g++ -c  Character.cpp 


Nutrient.o: Nutrient.cpp

	-g++ -c  Nutrient.cpp



Pattern.o: Pattern.cpp Pattern.h

	-g++ -c  Pattern.cpp 


World.o: World.cpp World.h Pattern.h

	-g++ -c  World.cpp 


clean : 
	-rm *.o *.exe */*.o */*.exe