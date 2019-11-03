#include "m_seq.h"

ap_uint<1> code[4] = {0, 0,0,1};

void m_seq(BIT * y) {
	int i;
	*y = code[0];

	SHIFT_REG:
	for (i = 0; i < 3; i++) {
		code[i] = code[i+1];
	}
	code[3] = *y ^ code[3];
}
