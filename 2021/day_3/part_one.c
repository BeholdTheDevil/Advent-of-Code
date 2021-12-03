#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	int line_length = 12;
	char line[line_length + 1];

	int one_bit[line_length];
	for(int i = 0; i < line_length; i++) {
		one_bit[i] = 0;
	}

	int f_length = 0;
	while(fscanf(fp, "%s\n", line) == 1) {
		for(int i = 0; i < line_length; i++) {
			if(line[i] == '1') {
				one_bit[i]++;
			}
		}
		f_length++;
	}


	unsigned int res = 0;
	for(int i = 0; i < line_length; i++) {
		if(one_bit[i] > f_length / 2) {
			res <<= 1;
			res |= 1;
		}
		else {
			res <<= 1;
		}

		printf("%d: %d\n", i+1, res);
	}

	unsigned int rev = (~res);
	rev &= ((1 << line_length) - 1);
	printf("\n\nResult: %u\nInverse: %u\nPower Consumption: %u\n", res, rev, res*rev);

	fclose(fp);
	return 0;
}
