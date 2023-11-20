#include "UTILS.h"

	/******************UTILS****************************/

    uint32_t UTILS_FlipBits(uint32_t input, uint32_t numbits)
	{
		//flips the order of bits in an input numbits wide
		//Bits are flipped within the field defined by numbits
		uint32_t output = 0;
		uint32_t i;

		for (i = 0; i < numbits; i++) //bitnum in range(numbits)
		{
            if (input & (1 << i)) output |= (1 << (numbits - 1 - i));
 		}
        return output;
	}

  void UTILS_frac2exp (uint32_t max_m, double frac, int32_t *m, int32_t *e)//(max_m, frac)
	{
    //convert fraction into mantissa and exponent format
		int32_t i,j;

		double best_diff = 99e9;
		double diff;
		if(frac > 0)
		{
        // start with the highest allowed mantissa and find best m, e pair
        //for m in xrange(max_m, 0, -1)
		for(i = max_m; i >= 0; i--)
			{
				j = (int32_t)(log2(frac/i));
				diff = fabs(frac - i * exp2(j));
				if (diff < best_diff)
				{
					best_diff = diff;
					*e = j;
					*m = i;
					if(best_diff == 0)
					{
						return;
					}
				}
			}
		}
		else
		{
      *m = 0;
			*e = 0;
		}
		
	}



    float UTILS_CalcModulationIndex(uint32_t dev, uint32_t br)
	{
		return (float)dev*2/br;
	}

/*
    def calc_oversampling_val(self, model):
        """
        calculate oversampling rate in the receive chain

        Args:
            model (ModelRoot) : Data model to read and write variables from
        """

        model.vars.oversampling_rate_actual.value = 2.0 * model.vars.rxbrfrac_actual.value
*/



