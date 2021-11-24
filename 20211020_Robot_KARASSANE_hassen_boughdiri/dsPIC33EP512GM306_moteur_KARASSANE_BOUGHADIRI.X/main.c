#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"
unsigned int valeurrec1;
unsigned int valeurrec2;
unsigned int valeurrec3;

int main(void)
{
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entrées sorties
    /****************************************************************************************************/
    InitIO();


    //LED_BLANCHE = 1;
    //LED_BLEUE = 1;
    //LED_ORANGE = 1;

    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    InitADC1();
    InitPWM();
    InitTimer23();
    InitTimer1();

    //PWMSetSpeed(20,MOTEUR_DROIT);
    //  PWMSetSpeed(20,MOTEUR_GAUCHE);
    //PWMSetSpeedConsigne(20,MOTEUR_DROIT);
    //PWMSetSpeedConsigne(20,MOTEUR_GAUCHE);




    while (1)
    {
        if (ADCIsConversionFinished() == 1)
        {
            ADCClearConversionFinishedFlag();
            unsigned int * result = ADCGetResult();
            valeurrec1 = result[0]; // Read the AN-scan input 1 conversion result
            valeurrec2 = result[1]; // Read the AN3 conversion result
            valeurrec3 = result[2];
            
            if (valeurrec1 >= 380)
            {
                LED_ORANGE = 1;
            }
            else
                LED_ORANGE = 0;

            if (valeurrec2 >= 380)
            {
                LED_BLEUE = 1;
            }
            else
                LED_BLEUE = 0;

            if (valeurrec3 >= 380)
            {
                LED_BLANCHE = 1;
            }
            else
                LED_BLANCHE = 0;
        }
    }


}


