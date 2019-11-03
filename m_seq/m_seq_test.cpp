#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "m_seq.h"

int main()
{
	const int SAMPLES = 600;
	FILE *fp;
	int i;
	BIT out;
	char c;

	fp = fopen("out.dat", "w");

	for (i = 0;i < SAMPLES; i++) {
		m_seq(&out);
		c = out;
		fprintf(fp, "%c\n", c + '0');
		printf("%c\n", c + '0');
	}
	fclose(fp);

	printf("Comparing against output data \n");
	if (system("diff -w out.dat out.gold.dat")) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
		return 1;
	}
	else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
		return 0;
	}
	return 0;
}
