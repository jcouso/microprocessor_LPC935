#include "ioP89LPC935.h"

BEEP  	DEFINE  P2.7

PILHA   DEFINE  0x60

        ASEG

        ORG 	0
	      JMP	INICIO		;INICIALIZA PERIFÉRICOS
        
        ORG     0X03            ;INTERRUPÇÃO EXTERNA 0
        JMP     BUZZER
        JMP     LOOP

        ORG	0x13		;INTERRUPÇÃO EXTERNA 1
	      JMP	POWERDOWN
	      ORG	0x80
INICIO
        MOV     SP,#PILHA
        MOV	IEN0,#10000101B	;IE1 -> 0X13 E IE0 -> 0X03
LOOP
        ORL     PCON,#01H
        ANL     PCON,#11111101b
        JMP     LOOP
        
BUZZER
        MOV     R1,#20
        SETB    BEEP
TEMP   
        CALL    TEMPO500
        DJNZ    R1,TEMP
        CLR     BEEP
        RETI
        
POWERDOWN
        ORL PCON,#03H
        RETI
        END 
