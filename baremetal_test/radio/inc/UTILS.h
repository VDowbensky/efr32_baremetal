#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>
#include <stdint.h>
#include <math.h>

	uint32_t UTILS_FlipBits(uint32_t input, uint32_t numbits);
  void UTILS_frac2exp (uint32_t max_m, double frac, int32_t *m, int32_t *e);
  float UTILS_CalcModulationIndex(uint32_t dev, uint32_t br);

#endif