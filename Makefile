project:
	echo "Building..."
	gcc main.c -o cgol
clean:
	echo "Cleaning files..."
	rm -rf cgol
run:
	./cgol
