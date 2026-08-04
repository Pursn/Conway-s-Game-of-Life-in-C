project:
	echo "Building..."
	gcc src/main.c -o bin/cgol
clean:
	echo "Cleaning files.."
	rm -rf bin/cgol
run:
	./bin/cgol
