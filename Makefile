main: FileOp.o BasicDBOp.o MainFile.o
	gcc -o bin FileOp.o BasicDBOp.o MainFile.o