#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	

	fclose(fp);

	return 0;
}
