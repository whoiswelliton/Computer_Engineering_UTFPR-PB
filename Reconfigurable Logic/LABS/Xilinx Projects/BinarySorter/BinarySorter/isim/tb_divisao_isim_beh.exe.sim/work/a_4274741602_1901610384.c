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
static const char *ng0 = "C:/Xilinx/Projects/BinarySorter/BinarySorter/binarysorter.vhd";



static void work_a_4274741602_1901610384_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(15, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t1 = (t0 + 2824U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 3);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = *((unsigned char *)t1);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB3;

LAB4:    t16 = (t0 + 2088U);
    t17 = *((char **)t16);
    t16 = (t0 + 2824U);
    t18 = *((char **)t16);
    t19 = *((int *)t18);
    t20 = (t19 - 3);
    t21 = (t20 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t16 = (t17 + t23);
    t24 = *((unsigned char *)t16);
    t25 = (t24 != (unsigned char)3);
    if (t25 != 0)
        goto LAB5;

LAB6:
LAB2:    t31 = (t0 + 5232);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 5360);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t11, 12U, 1, 0LL);
    goto LAB2;

LAB5:    t26 = (t0 + 5360);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)2;
    xsi_driver_first_trans_delta(t26, 12U, 1, 0LL);
    goto LAB2;

}

static void work_a_4274741602_1901610384_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(15, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t1 = (t0 + 2944U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 3);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = *((unsigned char *)t1);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB3;

LAB4:    t16 = (t0 + 2088U);
    t17 = *((char **)t16);
    t16 = (t0 + 2944U);
    t18 = *((char **)t16);
    t19 = *((int *)t18);
    t20 = (t19 - 3);
    t21 = (t20 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t16 = (t17 + t23);
    t24 = *((unsigned char *)t16);
    t25 = (t24 != (unsigned char)3);
    if (t25 != 0)
        goto LAB5;

LAB6:
LAB2:    t31 = (t0 + 5248);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 5424);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t11, 13U, 1, 0LL);
    goto LAB2;

LAB5:    t26 = (t0 + 5424);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)2;
    xsi_driver_first_trans_delta(t26, 13U, 1, 0LL);
    goto LAB2;

}

static void work_a_4274741602_1901610384_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(15, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t1 = (t0 + 3064U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 3);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = *((unsigned char *)t1);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB3;

LAB4:    t16 = (t0 + 2088U);
    t17 = *((char **)t16);
    t16 = (t0 + 3064U);
    t18 = *((char **)t16);
    t19 = *((int *)t18);
    t20 = (t19 - 3);
    t21 = (t20 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t16 = (t17 + t23);
    t24 = *((unsigned char *)t16);
    t25 = (t24 != (unsigned char)3);
    if (t25 != 0)
        goto LAB5;

LAB6:
LAB2:    t31 = (t0 + 5264);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 5488);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t11, 14U, 1, 0LL);
    goto LAB2;

LAB5:    t26 = (t0 + 5488);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)2;
    xsi_driver_first_trans_delta(t26, 14U, 1, 0LL);
    goto LAB2;

}

static void work_a_4274741602_1901610384_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(15, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t1 = (t0 + 3184U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 3);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = *((unsigned char *)t1);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB3;

LAB4:    t16 = (t0 + 2088U);
    t17 = *((char **)t16);
    t16 = (t0 + 3184U);
    t18 = *((char **)t16);
    t19 = *((int *)t18);
    t20 = (t19 - 3);
    t21 = (t20 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t16 = (t17 + t23);
    t24 = *((unsigned char *)t16);
    t25 = (t24 != (unsigned char)3);
    if (t25 != 0)
        goto LAB5;

LAB6:
LAB2:    t31 = (t0 + 5280);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 5552);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t11, 15U, 1, 0LL);
    goto LAB2;

LAB5:    t26 = (t0 + 5552);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)2;
    xsi_driver_first_trans_delta(t26, 15U, 1, 0LL);
    goto LAB2;

}


extern void work_a_4274741602_1901610384_init()
{
	static char *pe[] = {(void *)work_a_4274741602_1901610384_p_0,(void *)work_a_4274741602_1901610384_p_1,(void *)work_a_4274741602_1901610384_p_2,(void *)work_a_4274741602_1901610384_p_3};
	xsi_register_didat("work_a_4274741602_1901610384", "isim/tb_divisao_isim_beh.exe.sim/work/a_4274741602_1901610384.didat");
	xsi_register_executes(pe);
}
