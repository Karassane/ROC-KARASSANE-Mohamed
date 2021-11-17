

#ifndef PWM_H
#define	PWM_H
#define MOTEUR_GAUCHE 0
#define MOTEUR_DROIT 1
void InitPWM(void);
//void PWMSetSpeed(float vitesseEnPourcents, unsigned char nbMotor);
void PWMUpdateSpeed(void);
void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur);






#endif



