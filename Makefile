all:
	g++ src/main.cpp src/BfsPathFinder.cpp src/Cell.cpp src/FileReader.cpp \
	src/Map.cpp src/Move.cpp src/Path.cpp src/UcsPathFinder.cpp \
	-Iinclude -L/usr/lib/x86_64-linux-gnu -lboost_system -o find_path

clean:
	rm find_path -f