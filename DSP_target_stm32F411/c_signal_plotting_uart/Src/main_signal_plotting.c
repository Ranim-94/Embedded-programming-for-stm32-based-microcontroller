



#include"stm32f411xe.h"

#include "signals.h"

extern float _5hz_signal[HZ_5_SIG_LEN];

// Declaring function prototype
static void plot_input_signal(void);
static void pseudo_dly(int dly);


float g_in_sig_sample ; // global variable to store samples

int main(){


 // Enabling FPU by setting 11 to CP11 and CP10 in FPU
 // see section 4.6 on arm cortex M4 generic user guide
 SCB->CPACR |= (1U <<20); // shift bit to position bit 20

 SCB->CPACR |= (1U <<21); // shift bit to position bit 20

 SCB->CPACR |= (1U <<22); // shift bit to position bit 20

 SCB->CPACR |= (1U <<23); // shift bit to position bit 20

 while(1)
 	{
 		plot_input_signal();
 	}


} // End main


static void plot_input_signal(void)
{
	int i;


	for( i = 0; i < HZ_5_SIG_LEN; i++)
	{

		// store each sample of our signal into
			// the global variable g_in_sig_sample
		g_in_sig_sample = _5hz_signal[i];

		// insert some delay
		pseudo_dly(9000);
	}
}

static void pseudo_dly(int dly)
{
	for( int i = 0; i < dly; i++ ){}
}

