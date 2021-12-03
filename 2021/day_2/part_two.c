#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Calculate the horizontal position and depth you would have after following the planned
 * course. What do you get if you multiply your final horizontal position by your final
 * depth?
 */

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	int hori = 0, depth = 0, aim = 0;
	int temp = 0;
	char direc[8];

	while(fscanf(fp, "%s %d\n", direc, &temp) == 2) {
		if(strncmp(direc, "up", 2) == 0) {
			aim -= temp;
		}
		if(strncmp(direc, "down", 4) == 0) {
			aim += temp;
		}
		if(strncmp(direc, "forward", 7) == 0) {
			hori += temp;
			depth += aim * temp;
		}
	}

	printf("%d\n", hori * depth);

	fclose(fp);
	return 0;
}
