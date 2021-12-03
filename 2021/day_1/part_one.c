#include <stdio.h>
#include <stdlib.h>

/*
 * Count the number of times a number increases from the previous one.
 */

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	// Store the first number.
	int prevnum;
	fscanf(fp, "%d", &prevnum);

	int num, count = 0;
	while(fscanf(fp, "%d\n", &num) == 1) {

		// If the number is greater than the previous one - count it.
		if(num > prevnum) {
			count++;
		}
		prevnum = num;
	}

	printf("%d\n", count);

	fclose(fp);

	return 0;
}
