#include "radio_proc.h"

void CRC_init(void);

typedef struct
{
	uint32_t poly;
	uint32_t seed;
	uint32_t inputinv: 1;
	uint32_t outputinv: 1;
	uint32_t width: 2;
	uint32_t inputbitorder: 1;
	uint32_t bytereverse: 1;
	uint32_t bitreverse: 1;
	uint32_t bitsperword: 4;
	uint32_t padcrcinput: 1;
}CRCsettings_t;

