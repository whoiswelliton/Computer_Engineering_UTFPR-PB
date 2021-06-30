/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Ricardo/Xilinx/aps02_divisao/tb_divisao.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


static void work_a_2180093639_1901610384_p_0(char *t0)
{
    char t10[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    char *t6;
    char *t7;
    int t8;
    int t9;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    int64 t18;
    int t19;

LAB0:    t1 = (t0 + 2912U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(24, ng0);
    t2 = (t0 + 5308);
    *((int *)t2) = 0;
    t3 = (t0 + 5312);
    *((int *)t3) = 7;
    t4 = 0;
    t5 = 7;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(25, ng0);
    t6 = (t0 + 5316);
    *((int *)t6) = 0;
    t7 = (t0 + 5320);
    *((int *)t7) = 7;
    t8 = 0;
    t9 = 7;

LAB8:    if (t8 <= t9)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5308);
    t4 = *((int *)t2);
    t3 = (t0 + 5312);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB17:    t8 = (t4 + 1);
    t4 = t8;
    t6 = (t0 + 5308);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(26, ng0);
    t11 = (t0 + 5308);
    t12 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t10, *((int *)t11), 3);
    t13 = (t0 + 3296);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t12, 3U);
    xsi_driver_first_trans_fast(t13);
    xsi_set_current_line(27, ng0);
    t2 = (t0 + 5316);
    t3 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t10, *((int *)t2), 3);
    t6 = (t0 + 3360);
    t7 = (t6 + 56U);
    t11 = *((char **)t7);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t3, 3U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(28, ng0);
    t18 = (10 * 1000LL);
    t2 = (t0 + 2720);
    xsi_process_wait(t2, t18);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5316);
    t8 = *((int *)t2);
    t3 = (t0 + 5320);
    t9 = *((int *)t3);
    if (t8 == t9)
        goto LAB11;

LAB16:    t19 = (t8 + 1);
    t8 = t19;
    t6 = (t0 + 5316);
    *((int *)t6) = t8;
    goto LAB8;

LAB12:    goto LAB10;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_2180093639_1901610384_init()
{
	static char *pe[] = {(void *)work_a_2180093639_1901610384_p_0};
	xsi_register_didat("work_a_2180093639_1901610384", "isim/tb_divisao_isim_beh.exe.sim/work/a_2180093639_1901610384.didat");
	xsi_register_executes(pe);
}
