CFLAGS = -Ofast -march=native -pipe

prog: obj/Main.o
	$(CXX) $(CFLAGS) obj/Main.o -o prog

obj/Main.o: src/Main.cpp
	$(CXX) $(CFLAGS) -c src/Main.cpp -o obj/Main.o


clean:
	rm -f obj/* prog

install:
	@echo "Installing ain't supported!"

run:
	gnome-terminal -e ~/Projekte/cpptest/prog
