#include <stdio.h>
#include <stdlib.h>


/**
 * Consider the following:
 * 199  A
 * 200  A B
 * 208  A B C
 * 210    B C D
 * 200      C D
 * 207        D
 *
 * Count all instances where the sum of a set of three numbers is greater than the
 * previous set of three numbers.
 */

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	int nums[3];
	for(int i = 0; i < 3; i++) {
		fscanf(fp, "%d\n", &nums[i]);
	}

	int n;
	int count = 0;
	while(fscanf(fp, "%d\n", &n) == 1) {
		// If the sum of the new set is greater than the sum of the previous set, count it.
		if(nums[1] + nums[2] + n > nums[0] + nums[1] + nums[2]) {
			count++;
		}

		// Shift n into the field
		nums[0] = nums[1];
		nums[1] = nums[2];
		nums[2] = n;
	}

	printf("%d\n", count);

	fclose(fp);

	return 0;
}
