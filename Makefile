LDLIBS=-lsqlite3

hm3301runner: hm3301runner.cpp hm3301.cpp hm3301.h

clean:
	rm *.o
