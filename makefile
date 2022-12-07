CPP_FLAGS='-std=c++11'
main:main.cpp chess.cpp
	g++ main.cpp chess.cpp -o play -I. $(CPP_FLAGS)

.PHONY:clean
clean:
	rm -f play
