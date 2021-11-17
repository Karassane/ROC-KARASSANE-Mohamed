#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"


int main(void) {
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entr�es sorties
    /****************************************************************************************************/
    InitIO();

    LED_BLANCHE = 1;
    LED_BLEUE = 1;
    LED_ORANGE = 1;

    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    InitTimer23();
    InitTimer1();
    InitPWM();
    InitADC1();
    //PWMSetSpeed(20,MOTEUR_DROIT);
      //  PWMSetSpeed(20,MOTEUR_GAUCHE);
    //PWMSetSpeedConsigne(20,MOTEUR_DROIT);
    //PWMSetSpeedConsigne(20,MOTEUR_GAUCHE);

    
   

    while (1) {
       // _T1Interrupt();
       // _T3Interrupt();
        //LED_BLANCHE = !LED_BLANCHE;
        //LED_BLEUE = !LED_BLEUE;
    } // fin main
}