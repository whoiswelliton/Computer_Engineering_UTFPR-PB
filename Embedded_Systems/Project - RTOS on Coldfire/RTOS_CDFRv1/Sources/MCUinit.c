/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE INTERRUPT SERVICE ROUTINES
**     OR EXPLICITLY MARKED SECTIONS
**
**     Project   : Coldfare_v1t
**     Processor : MCF51QE128CLK
**     Version   : Component 01.012, Driver 01.07, CPU db: 3.00.076
**     Datasheet : MCF51QE128RM, Rev. 3, 9/2007
**     Date/Time : 06/10/2020, 19:11
**     Abstract  :
**         This module contains device initialization code 
**         for selected on-chip peripherals.
**     Contents  :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

/* MODULE MCUinit */

#include <mcf51qe128.h>                /* I/O map for MCF51QE128CLK */
#include "MCUinit.h"

/* pragma to disable "possibly unassigned ISR handler" message generated by compiler on definition of ISR without vector number */
#pragma warn_absolute off

/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51QE128_80)
**
**     Description :
**         Initialization code for CPU core and a clock source.
** ===================================================================
*/
void __initialize_hardware(void)
{
  /* ### MCF51QE128_80 "Cpu" init code ... */
  /*  PE initialization code after reset */

  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,WAITE=1,RSTOPE=0,BKGDPE=1,RSTPE=0 */
  SOPT1 = 0x52;                                      
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBE=0 */
  SPMSC1 = 0x1C;                                      
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  SPMSC2 = 0x02;                                      
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  SPMSC3 &= (unsigned char)~0x38;                     
  /* Initialization of CPU registers */
  asm {
    /* VBR: ADDRESS=0 */
    clr.l d0
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,FSD=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*  System clock initialization */
  if (*(unsigned char*far)0x03FF != 0xFF) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*far)0x03FF; /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*far)0x03FE) & (unsigned char)0x01); /* Initialize ICSSC register from a non volatile memory */
  }
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=0,IREFSTEN=0 */
  ICSC1 = 0x04;                        /* Initialization of the ICS control register 1 */
  /* ICSC2: BDIV=1,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  ICSC2 = 0x40;                        /* Initialization of the ICS control register 2 */
  while(!ICSSC_IREFST) {               /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=0,DMX32=0 */
  ICSSC &= (unsigned char)~0xE0;       /* Initialization of the ICS status and control */
  while((ICSSC & 0xC0) != 0x00) {      /* Wait until the FLL switches to Low range DCO mode */
  }
  /* INTC_WCR: ENB=0,MASK=0 */
  INTC_WCR = 0x00;                                      
}

/*
** ===================================================================
**     Method      :  MCU_init (component MCF51QE128_80)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/
void MCU_init(void)
{
  /* SCGC1: TPM3=1,TPM2=1,TPM1=1,ADC=1,IIC2=1,IIC1=1,SCI2=1,SCI1=1 */
  SCGC1 = 0xFF;                                      
  /* SCGC2: FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,SPI2=1,SPI1=1 */
  SCGC2 = 0xFF;                                      
  /* Common initialization of the CPU registers */
  /* PTASE: PTASE7=0,PTASE6=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  PTASE &= (unsigned char)~0xDF;                     
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  PTBSE = 0x00;                                      
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  PTCSE = 0x00;                                      
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  PTDSE = 0x00;                                      
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  PTESE = 0x00;                                      
  /* PTFSE: PTFSE7=0,PTFSE6=0,PTFSE5=0,PTFSE4=0,PTFSE3=0,PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  PTFSE = 0x00;                                      
  /* PTGSE: PTGSE7=0,PTGSE6=0,PTGSE5=0,PTGSE4=0,PTGSE3=0,PTGSE2=0,PTGSE1=0,PTGSE0=0 */
  PTGSE = 0x00;                                      
  /* PTHSE: PTHSE7=0,PTHSE6=0,PTHSE5=0,PTHSE4=0,PTHSE3=0,PTHSE2=0,PTHSE1=0,PTHSE0=0 */
  PTHSE = 0x00;                                      
  /* PTJSE: PTJSE7=0,PTJSE6=0,PTJSE5=0,PTJSE4=0,PTJSE3=0,PTJSE2=0,PTJSE1=0,PTJSE0=0 */
  PTJSE = 0x00;                                      
  /* PTADS: PTADS7=0,PTADS6=0,PTADS5=0,PTADS4=0,PTADS3=0,PTADS2=0,PTADS1=0,PTADS0=0 */
  PTADS = 0x00;                                      
  /* PTBDS: PTBDS7=0,PTBDS6=0,PTBDS5=0,PTBDS4=0,PTBDS3=0,PTBDS2=0,PTBDS1=0,PTBDS0=0 */
  PTBDS = 0x00;                                      
  /* PTCDS: PTCDS7=0,PTCDS6=0,PTCDS5=0,PTCDS4=0,PTCDS3=0,PTCDS2=0,PTCDS1=0,PTCDS0=0 */
  PTCDS = 0x00;                                      
  /* PTDDS: PTDDS7=0,PTDDS6=0,PTDDS5=0,PTDDS4=0,PTDDS3=0,PTDDS2=0,PTDDS1=0,PTDDS0=0 */
  PTDDS = 0x00;                                      
  /* PTEDS: PTEDS7=0,PTEDS6=0,PTEDS5=0,PTEDS4=0,PTEDS3=0,PTEDS2=0,PTEDS1=0,PTEDS0=0 */
  PTEDS = 0x00;                                      
  /* PTFDS: PTFDS7=0,PTFDS6=0,PTFDS5=0,PTFDS4=0,PTFDS3=0,PTFDS2=0,PTFDS1=0,PTFDS0=0 */
  PTFDS = 0x00;                                      
  /* PTGDS: PTGDS7=0,PTGDS6=0,PTGDS5=0,PTGDS4=0,PTGDS3=0,PTGDS2=0,PTGDS1=0,PTGDS0=0 */
  PTGDS = 0x00;                                      
  /* PTHDS: PTHDS7=0,PTHDS6=0,PTHDS5=0,PTHDS4=0,PTHDS3=0,PTHDS2=0,PTHDS1=0,PTHDS0=0 */
  PTHDS = 0x00;                                      
  /* PTJDS: PTJDS7=0,PTJDS6=0,PTJDS5=0,PTJDS4=0,PTJDS3=0,PTJDS2=0,PTJDS1=0,PTJDS0=0 */
  PTJDS = 0x00;                                      
  /* ### */
  asm {                                /* Set Interrupt level 0 */
    move.w SR,D0;
    andi.l #0xF8FF,D0;
    move.w D0,SR;
  }
} /*MCU_init*/


/*
** ===================================================================
**     Interrupt handler : isr_default
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isr_default(void)
{
  /* Write your interrupt code here ... */

}
/* end of isr_default */


/*
** ===================================================================
**     Interrupt handler : isrVlvd
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isrVlvd(void)
{
  /* Write your interrupt code here ... */

}
/* end of isrVlvd */



/* Initialization of the CPU registers in FLASH */

/* NVPROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
unsigned char NVPROT_INIT @0x0000040D = 0xFF;

/* NVOPT: KEYEN1=0,KEYEN0=1,SEC1=1,SEC0=1 */
unsigned char NVOPT_INIT @0x0000040F = 0x7F;




#ifdef __cplusplus
extern "C" {
#endif
extern void _startup(void);
extern unsigned long far _SP_INIT[];

#ifdef __cplusplus
}
#endif

void SwitchContext(void);
void TickTimer(void);

/* Interrupt vector table */
#ifndef UNASSIGNED_ISR
  #define UNASSIGNED_ISR isr_default   /* unassigned interrupt service routine */
#endif

                                                                /*Address    Lvl Pri */
void (*const vector_0)(void)   @INITSP      = (void(*const )(void))_SP_INIT; /*0x00000000 -   - */
void (*const vector_1)(void)   @INITPC      = _startup;         /*0x00000004 -   - */
void (*const vector_2)(void)   @Vaccerr     = UNASSIGNED_ISR;   /*0x00000008 -   - */
void (*const vector_3)(void)   @Vadderr     = UNASSIGNED_ISR;   /*0x0000000C -   - */
void (*const vector_4)(void)   @Viinstr     = UNASSIGNED_ISR;   /*0x00000010 -   - */
void (*const vector_5)(void)   @VReserved5  = UNASSIGNED_ISR;   /*0x00000014 -   - */
void (*const vector_6)(void)   @VReserved6  = UNASSIGNED_ISR;   /*0x00000018 -   - */
void (*const vector_7)(void)   @VReserved7  = UNASSIGNED_ISR;   /*0x0000001C -   - */
void (*const vector_8)(void)   @Vprviol     = UNASSIGNED_ISR;   /*0x00000020 -   - */
void (*const vector_9)(void)   @Vtrace      = UNASSIGNED_ISR;   /*0x00000024 -   - */
void (*const vector_10)(void)  @Vunilaop    = UNASSIGNED_ISR;   /*0x00000028 -   - */
void (*const vector_11)(void)  @Vunilfop    = UNASSIGNED_ISR;   /*0x0000002C -   - */
void (*const vector_12)(void)  @Vdbgi       = UNASSIGNED_ISR;   /*0x00000030 -   - */
void (*const vector_13)(void)  @VReserved13 = UNASSIGNED_ISR;   /*0x00000034 -   - */
void (*const vector_14)(void)  @Vferror     = UNASSIGNED_ISR;   /*0x00000038 -   - */
void (*const vector_15)(void)  @VReserved15 = UNASSIGNED_ISR;   /*0x0000003C -   - */
void (*const vector_16)(void)  @VReserved16 = UNASSIGNED_ISR;   /*0x00000040 -   - */
void (*const vector_17)(void)  @VReserved17 = UNASSIGNED_ISR;   /*0x00000044 -   - */
void (*const vector_18)(void)  @VReserved18 = UNASSIGNED_ISR;   /*0x00000048 -   - */
void (*const vector_19)(void)  @VReserved19 = UNASSIGNED_ISR;   /*0x0000004C -   - */
void (*const vector_20)(void)  @VReserved20 = UNASSIGNED_ISR;   /*0x00000050 -   - */
void (*const vector_21)(void)  @VReserved21 = UNASSIGNED_ISR;   /*0x00000054 -   - */
void (*const vector_22)(void)  @VReserved22 = UNASSIGNED_ISR;   /*0x00000058 -   - */
void (*const vector_23)(void)  @VReserved23 = UNASSIGNED_ISR;   /*0x0000005C -   - */
void (*const vector_24)(void)  @Vspuri      = UNASSIGNED_ISR;   /*0x00000060 -   - */
void (*const vector_25)(void)  @VReserved25 = UNASSIGNED_ISR;   /*0x00000064 -   - */
void (*const vector_26)(void)  @VReserved26 = UNASSIGNED_ISR;   /*0x00000068 -   - */
void (*const vector_27)(void)  @VReserved27 = UNASSIGNED_ISR;   /*0x0000006C -   - */
void (*const vector_28)(void)  @VReserved28 = UNASSIGNED_ISR;   /*0x00000070 -   - */
void (*const vector_29)(void)  @VReserved29 = UNASSIGNED_ISR;   /*0x00000074 -   - */
void (*const vector_30)(void)  @VReserved30 = UNASSIGNED_ISR;   /*0x00000078 -   - */
void (*const vector_31)(void)  @VReserved31 = UNASSIGNED_ISR;   /*0x0000007C -   - */
void (*const vector_32)(void)  @Vtrap0      = SwitchContext;    /*0x00000080 -   - */
void (*const vector_33)(void)  @Vtrap1      = UNASSIGNED_ISR;   /*0x00000084 -   - */
void (*const vector_34)(void)  @Vtrap2      = UNASSIGNED_ISR;   /*0x00000088 -   - */
void (*const vector_35)(void)  @Vtrap3      = UNASSIGNED_ISR;   /*0x0000008C -   - */
void (*const vector_36)(void)  @Vtrap4      = UNASSIGNED_ISR;   /*0x00000090 -   - */
void (*const vector_37)(void)  @Vtrap5      = UNASSIGNED_ISR;   /*0x00000094 -   - */
void (*const vector_38)(void)  @Vtrap6      = UNASSIGNED_ISR;   /*0x00000098 -   - */
void (*const vector_39)(void)  @Vtrap7      = UNASSIGNED_ISR;   /*0x0000009C -   - */
void (*const vector_40)(void)  @Vtrap8      = UNASSIGNED_ISR;   /*0x000000A0 -   - */
void (*const vector_41)(void)  @Vtrap9      = UNASSIGNED_ISR;   /*0x000000A4 -   - */
void (*const vector_42)(void)  @Vtrap10     = UNASSIGNED_ISR;   /*0x000000A8 -   - */
void (*const vector_43)(void)  @Vtrap11     = UNASSIGNED_ISR;   /*0x000000AC -   - */
void (*const vector_44)(void)  @Vtrap12     = UNASSIGNED_ISR;   /*0x000000B0 -   - */
void (*const vector_45)(void)  @Vtrap13     = UNASSIGNED_ISR;   /*0x000000B4 -   - */
void (*const vector_46)(void)  @Vtrap14     = UNASSIGNED_ISR;   /*0x000000B8 -   - */
void (*const vector_47)(void)  @Vtrap15     = UNASSIGNED_ISR;   /*0x000000BC -   - */
void (*const vector_48)(void)  @VReserved48 = UNASSIGNED_ISR;   /*0x000000C0 -   - */
void (*const vector_49)(void)  @VReserved49 = UNASSIGNED_ISR;   /*0x000000C4 -   - */
void (*const vector_50)(void)  @VReserved50 = UNASSIGNED_ISR;   /*0x000000C8 -   - */
void (*const vector_51)(void)  @VReserved51 = UNASSIGNED_ISR;   /*0x000000CC -   - */
void (*const vector_52)(void)  @VReserved52 = UNASSIGNED_ISR;   /*0x000000D0 -   - */
void (*const vector_53)(void)  @VReserved53 = UNASSIGNED_ISR;   /*0x000000D4 -   - */
void (*const vector_54)(void)  @VReserved54 = UNASSIGNED_ISR;   /*0x000000D8 -   - */
void (*const vector_55)(void)  @VReserved55 = UNASSIGNED_ISR;   /*0x000000DC -   - */
void (*const vector_56)(void)  @VReserved56 = UNASSIGNED_ISR;   /*0x000000E0 -   - */
void (*const vector_57)(void)  @VReserved57 = UNASSIGNED_ISR;   /*0x000000E4 -   - */
void (*const vector_58)(void)  @VReserved58 = UNASSIGNED_ISR;   /*0x000000E8 -   - */
void (*const vector_59)(void)  @VReserved59 = UNASSIGNED_ISR;   /*0x000000EC -   - */
void (*const vector_60)(void)  @VReserved60 = UNASSIGNED_ISR;   /*0x000000F0 -   - */
void (*const vector_61)(void)  @Vunsinstr   = UNASSIGNED_ISR;   /*0x000000F4 -   - */
void (*const vector_62)(void)  @VReserved62 = UNASSIGNED_ISR;   /*0x000000F8 -   - */
void (*const vector_63)(void)  @VReserved63 = UNASSIGNED_ISR;   /*0x000000FC -   - */
void (*const vector_64)(void)  @Virq        = UNASSIGNED_ISR;   /*0x00000100 -   - */
void (*const vector_65)(void)  @Vlvd        = isrVlvd;          /*0x00000104 7   3 */
void (*const vector_66)(void)  @Vtpm1ch0    = UNASSIGNED_ISR;   /*0x00000108 -   - */
void (*const vector_67)(void)  @Vtpm1ch1    = UNASSIGNED_ISR;   /*0x0000010C -   - */
void (*const vector_68)(void)  @Vtpm1ch2    = UNASSIGNED_ISR;   /*0x00000110 -   - */
void (*const vector_69)(void)  @Vtpm1ovf    = TickTimer;        /*0x00000114 -   - */
void (*const vector_70)(void)  @Vtpm2ch0    = UNASSIGNED_ISR;   /*0x00000118 -   - */
void (*const vector_71)(void)  @Vtpm2ch1    = UNASSIGNED_ISR;   /*0x0000011C -   - */
void (*const vector_72)(void)  @Vtpm2ch2    = UNASSIGNED_ISR;   /*0x00000120 -   - */
void (*const vector_73)(void)  @Vtpm2ovf    = UNASSIGNED_ISR;   /*0x00000124 -   - */
void (*const vector_74)(void)  @Vspi2       = UNASSIGNED_ISR;   /*0x00000128 -   - */
void (*const vector_75)(void)  @Vspi1       = UNASSIGNED_ISR;   /*0x0000012C -   - */
void (*const vector_76)(void)  @Vsci1err    = UNASSIGNED_ISR;   /*0x00000130 -   - */
void (*const vector_77)(void)  @Vsci1rx     = UNASSIGNED_ISR;   /*0x00000134 -   - */
void (*const vector_78)(void)  @Vsci1tx     = UNASSIGNED_ISR;   /*0x00000138 -   - */
void (*const vector_79)(void)  @Viicx       = UNASSIGNED_ISR;   /*0x0000013C -   - */
void (*const vector_80)(void)  @Vkeyboard   = UNASSIGNED_ISR;   /*0x00000140 -   - */
void (*const vector_81)(void)  @Vadc        = UNASSIGNED_ISR;   /*0x00000144 -   - */
void (*const vector_82)(void)  @Vacmpx      = UNASSIGNED_ISR;   /*0x00000148 -   - */
void (*const vector_83)(void)  @Vsci2err    = UNASSIGNED_ISR;   /*0x0000014C -   - */
void (*const vector_84)(void)  @Vsci2rx     = UNASSIGNED_ISR;   /*0x00000150 -   - */
void (*const vector_85)(void)  @Vsci2tx     = UNASSIGNED_ISR;   /*0x00000154 -   - */
void (*const vector_86)(void)  @Vrtc        = UNASSIGNED_ISR;   /*0x00000158 -   - */
void (*const vector_87)(void)  @Vtpm3ch0    = UNASSIGNED_ISR;   /*0x0000015C -   - */
void (*const vector_88)(void)  @Vtpm3ch1    = UNASSIGNED_ISR;   /*0x00000160 -   - */
void (*const vector_89)(void)  @Vtpm3ch2    = UNASSIGNED_ISR;   /*0x00000164 -   - */
void (*const vector_90)(void)  @Vtpm3ch3    = UNASSIGNED_ISR;   /*0x00000168 -   - */
void (*const vector_91)(void)  @Vtpm3ch4    = UNASSIGNED_ISR;   /*0x0000016C -   - */
void (*const vector_92)(void)  @Vtpm3ch5    = UNASSIGNED_ISR;   /*0x00000170 -   - */
void (*const vector_93)(void)  @Vtpm3ovf    = UNASSIGNED_ISR;   /*0x00000174 -   - */
void (*const vector_94)(void)  @VReserved94 = UNASSIGNED_ISR;   /*0x00000178 -   - */
void (*const vector_95)(void)  @VReserved95 = UNASSIGNED_ISR;   /*0x0000017C -   - */
void (*const vector_96)(void)  @VL7swi      = UNASSIGNED_ISR;   /*0x00000180 -   - */
void (*const vector_97)(void)  @VL6swi      = UNASSIGNED_ISR;   /*0x00000184 -   - */
void (*const vector_98)(void)  @VL5swi      = UNASSIGNED_ISR;   /*0x00000188 -   - */
void (*const vector_99)(void)  @VL4swi      = UNASSIGNED_ISR;   /*0x0000018C -   - */
void (*const vector_100)(void) @VL3swi      = UNASSIGNED_ISR;   /*0x00000190 -   - */
void (*const vector_101)(void) @VL2swi      = UNASSIGNED_ISR;   /*0x00000194 -   - */
void (*const vector_102)(void) @VL1swi      = UNASSIGNED_ISR;   /*0x00000198 -   - */




/* END MCUinit */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.09 [04.41]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
