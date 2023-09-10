output: main.o cd.o dvd.o livre.o media.o mediatheque.o revue.o RES_NUM.o vhs.o
	g++ main.o cd.o dvd.o livre.o media.o mediatheque.o revue.o RES_NUM.o vhs.o -o main

main.o: main.cpp
	g++ -c main.cpp

cd.o: CD.cpp
	g++ -c CD.cpp

dvd.o: DVD.cpp
	g++ -c DVD.cpp

livre.o: LIVRE.cpp
	g++ -c LIVRE.cpp

media.o: Media.cpp
	g++ -c Media.cpp

mediatheque.o: Mediatheque.cpp
	g++ -c Mediatheque.cpp

revue.o: REVUE.cpp
	g++ -c REVUE.cpp

vhs.o: VHS.cpp
	g++ -c VHS.cpp

ressource_numerique.o: RES_NUM.cpp
	g++ -c RES_NUM.cpp

clean:
	rm *.o main
