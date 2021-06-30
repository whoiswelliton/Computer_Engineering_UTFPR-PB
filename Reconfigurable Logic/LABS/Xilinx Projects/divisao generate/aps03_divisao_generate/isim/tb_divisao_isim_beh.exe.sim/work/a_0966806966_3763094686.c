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
static const char *ng0 = "C:/Users/Ricardo/Xilinx/aps03_divisao_generate/divisao.vhd";
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );


static void work_a_0966806966_3763094686_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 4840U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12344);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 0U, 1, 0LL);

LAB2:    t16 = (t0 + 11944);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_1(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 4840U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 12408);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 0U, 1, 0LL);

LAB2:    t36 = (t0 + 11960);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 12408);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 0U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 4840U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_2(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 4960U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12472);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 1U, 1, 0LL);

LAB2:    t16 = (t0 + 11976);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_3(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 4960U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 12536);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 1U, 1, 0LL);

LAB2:    t36 = (t0 + 11992);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 12536);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 1U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 4960U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_4(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5080U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12600);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 2U, 1, 0LL);

LAB2:    t16 = (t0 + 12008);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_5(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5080U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 12664);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 2U, 1, 0LL);

LAB2:    t36 = (t0 + 12024);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 12664);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 2U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5080U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_6(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5200U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12728);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 3U, 1, 0LL);

LAB2:    t16 = (t0 + 12040);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_7(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5200U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 12792);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 3U, 1, 0LL);

LAB2:    t36 = (t0 + 12056);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 12792);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 3U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5200U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_8(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5320U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12856);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 4U, 1, 0LL);

LAB2:    t16 = (t0 + 12072);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_9(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5320U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 12920);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 4U, 1, 0LL);

LAB2:    t36 = (t0 + 12088);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 12920);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 4U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5320U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_10(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5440U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 12984);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 5U, 1, 0LL);

LAB2:    t16 = (t0 + 12104);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_11(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5440U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 13048);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 5U, 1, 0LL);

LAB2:    t36 = (t0 + 12120);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 13048);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 5U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5440U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_12(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5560U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 13112);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 6U, 1, 0LL);

LAB2:    t16 = (t0 + 12136);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_13(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5560U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 13176);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 6U, 1, 0LL);

LAB2:    t36 = (t0 + 12152);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 13176);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 6U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5560U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_14(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(22, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 5680U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3304U);
    t7 = *((char **)t4);
    t4 = (t0 + 18548U);
    t8 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t7, t4);
    t9 = (t6 * t8);
    t10 = (t3 - t9);
    t11 = (t0 + 13240);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t10;
    xsi_driver_first_trans_delta(t11, 7U, 1, 0LL);

LAB2:    t16 = (t0 + 12168);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_15(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 4424U);
    t3 = *((char **)t2);
    t2 = (t0 + 5680U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 7);
    t7 = (t6 * -1);
    t8 = (4U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((int *)t2);
    t11 = (t10 >= 0);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t31 = (t0 + 13304);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    *((unsigned char *)t35) = (unsigned char)2;
    xsi_driver_first_trans_delta(t31, 7U, 1, 0LL);

LAB2:    t36 = (t0 + 12184);
    *((int *)t36) = 1;

LAB1:    return;
LAB3:    t26 = (t0 + 13304);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_delta(t26, 7U, 1, 0LL);
    goto LAB2;

LAB5:    t12 = (t0 + 4424U);
    t13 = *((char **)t12);
    t12 = (t0 + 5680U);
    t14 = *((char **)t12);
    t15 = *((int *)t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (4U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((int *)t12);
    t21 = (t0 + 3304U);
    t22 = *((char **)t21);
    t21 = (t0 + 18548U);
    t23 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t22, t21);
    t24 = (t20 - t23);
    t25 = (t24 < 0);
    t1 = t25;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_16(char *t0)
{
    char *t1;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    unsigned char t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    unsigned char t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    unsigned char t41;
    unsigned int t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t51;
    char *t52;
    unsigned char t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t63;
    char *t64;
    unsigned char t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t75;
    char *t76;
    unsigned char t77;
    unsigned int t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t87;
    char *t88;
    unsigned char t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;

LAB0:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 18756);
    t3 = (t0 + 3784U);
    t4 = *((char **)t3);
    t5 = 1;
    if (8U == 8U)
        goto LAB5;

LAB6:    t5 = 0;

LAB7:    if (t5 != 0)
        goto LAB3;

LAB4:    t13 = (t0 + 18764);
    t15 = (t0 + 3784U);
    t16 = *((char **)t15);
    t17 = 1;
    if (8U == 8U)
        goto LAB13;

LAB14:    t17 = 0;

LAB15:    if (t17 != 0)
        goto LAB11;

LAB12:    t25 = (t0 + 18772);
    t27 = (t0 + 3784U);
    t28 = *((char **)t27);
    t29 = 1;
    if (8U == 8U)
        goto LAB21;

LAB22:    t29 = 0;

LAB23:    if (t29 != 0)
        goto LAB19;

LAB20:    t37 = (t0 + 18780);
    t39 = (t0 + 3784U);
    t40 = *((char **)t39);
    t41 = 1;
    if (8U == 8U)
        goto LAB29;

LAB30:    t41 = 0;

LAB31:    if (t41 != 0)
        goto LAB27;

LAB28:    t49 = (t0 + 18788);
    t51 = (t0 + 3784U);
    t52 = *((char **)t51);
    t53 = 1;
    if (8U == 8U)
        goto LAB37;

LAB38:    t53 = 0;

LAB39:    if (t53 != 0)
        goto LAB35;

LAB36:    t61 = (t0 + 18796);
    t63 = (t0 + 3784U);
    t64 = *((char **)t63);
    t65 = 1;
    if (8U == 8U)
        goto LAB45;

LAB46:    t65 = 0;

LAB47:    if (t65 != 0)
        goto LAB43;

LAB44:    t73 = (t0 + 18804);
    t75 = (t0 + 3784U);
    t76 = *((char **)t75);
    t77 = 1;
    if (8U == 8U)
        goto LAB53;

LAB54:    t77 = 0;

LAB55:    if (t77 != 0)
        goto LAB51;

LAB52:    t85 = (t0 + 18812);
    t87 = (t0 + 3784U);
    t88 = *((char **)t87);
    t89 = 1;
    if (8U == 8U)
        goto LAB61;

LAB62:    t89 = 0;

LAB63:    if (t89 != 0)
        goto LAB59;

LAB60:
LAB67:    t97 = (t0 + 13368);
    t98 = (t97 + 56U);
    t99 = *((char **)t98);
    t100 = (t99 + 56U);
    t101 = *((char **)t100);
    *((int *)t101) = 0;
    xsi_driver_first_trans_fast(t97);

LAB2:    t102 = (t0 + 12200);
    *((int *)t102) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 13368);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = 0;
    xsi_driver_first_trans_fast(t8);
    goto LAB2;

LAB5:    t6 = 0;

LAB8:    if (t6 < 8U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t3 = (t1 + t6);
    t7 = (t4 + t6);
    if (*((unsigned char *)t3) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t6 = (t6 + 1);
    goto LAB8;

LAB11:    t20 = (t0 + 13368);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    *((int *)t24) = 1;
    xsi_driver_first_trans_fast(t20);
    goto LAB2;

LAB13:    t18 = 0;

LAB16:    if (t18 < 8U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t15 = (t13 + t18);
    t19 = (t16 + t18);
    if (*((unsigned char *)t15) != *((unsigned char *)t19))
        goto LAB14;

LAB18:    t18 = (t18 + 1);
    goto LAB16;

LAB19:    t32 = (t0 + 13368);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    *((int *)t36) = 2;
    xsi_driver_first_trans_fast(t32);
    goto LAB2;

LAB21:    t30 = 0;

LAB24:    if (t30 < 8U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t27 = (t25 + t30);
    t31 = (t28 + t30);
    if (*((unsigned char *)t27) != *((unsigned char *)t31))
        goto LAB22;

LAB26:    t30 = (t30 + 1);
    goto LAB24;

LAB27:    t44 = (t0 + 13368);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    t47 = (t46 + 56U);
    t48 = *((char **)t47);
    *((int *)t48) = 3;
    xsi_driver_first_trans_fast(t44);
    goto LAB2;

LAB29:    t42 = 0;

LAB32:    if (t42 < 8U)
        goto LAB33;
    else
        goto LAB31;

LAB33:    t39 = (t37 + t42);
    t43 = (t40 + t42);
    if (*((unsigned char *)t39) != *((unsigned char *)t43))
        goto LAB30;

LAB34:    t42 = (t42 + 1);
    goto LAB32;

LAB35:    t56 = (t0 + 13368);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    *((int *)t60) = 4;
    xsi_driver_first_trans_fast(t56);
    goto LAB2;

LAB37:    t54 = 0;

LAB40:    if (t54 < 8U)
        goto LAB41;
    else
        goto LAB39;

LAB41:    t51 = (t49 + t54);
    t55 = (t52 + t54);
    if (*((unsigned char *)t51) != *((unsigned char *)t55))
        goto LAB38;

LAB42:    t54 = (t54 + 1);
    goto LAB40;

LAB43:    t68 = (t0 + 13368);
    t69 = (t68 + 56U);
    t70 = *((char **)t69);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    *((int *)t72) = 5;
    xsi_driver_first_trans_fast(t68);
    goto LAB2;

LAB45:    t66 = 0;

LAB48:    if (t66 < 8U)
        goto LAB49;
    else
        goto LAB47;

LAB49:    t63 = (t61 + t66);
    t67 = (t64 + t66);
    if (*((unsigned char *)t63) != *((unsigned char *)t67))
        goto LAB46;

LAB50:    t66 = (t66 + 1);
    goto LAB48;

LAB51:    t80 = (t0 + 13368);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    *((int *)t84) = 6;
    xsi_driver_first_trans_fast(t80);
    goto LAB2;

LAB53:    t78 = 0;

LAB56:    if (t78 < 8U)
        goto LAB57;
    else
        goto LAB55;

LAB57:    t75 = (t73 + t78);
    t79 = (t76 + t78);
    if (*((unsigned char *)t75) != *((unsigned char *)t79))
        goto LAB54;

LAB58:    t78 = (t78 + 1);
    goto LAB56;

LAB59:    t92 = (t0 + 13368);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    t95 = (t94 + 56U);
    t96 = *((char **)t95);
    *((int *)t96) = 7;
    xsi_driver_first_trans_fast(t92);
    goto LAB2;

LAB61:    t90 = 0;

LAB64:    if (t90 < 8U)
        goto LAB65;
    else
        goto LAB63;

LAB65:    t87 = (t85 + t90);
    t91 = (t88 + t90);
    if (*((unsigned char *)t87) != *((unsigned char *)t91))
        goto LAB62;

LAB66:    t90 = (t90 + 1);
    goto LAB64;

LAB68:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_17(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(39, ng0);

LAB3:    t1 = (t0 + 3144U);
    t2 = *((char **)t1);
    t1 = (t0 + 18532U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 13432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t3;
    xsi_driver_first_trans_fast(t4);

LAB2:    t9 = (t0 + 12216);
    *((int *)t9) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_18(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(40, ng0);

LAB3:    t1 = (t0 + 3304U);
    t2 = *((char **)t1);
    t1 = (t0 + 18548U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 13496);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t3;
    xsi_driver_first_trans_fast(t4);

LAB2:    t9 = (t0 + 12232);
    *((int *)t9) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_19(char *t0)
{
    char t9[16];
    unsigned char t1;
    char *t2;
    char *t3;
    int t4;
    unsigned char t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t10;
    int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    unsigned char t20;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;

LAB0:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3944U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t5 = (t4 != 0);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:    t17 = (t0 + 4104U);
    t18 = *((char **)t17);
    t19 = *((int *)t18);
    t20 = (t19 == 0);
    if (t20 != 0)
        goto LAB8;

LAB9:
LAB10:    t27 = (t0 + 18823);
    t29 = (t0 + 13560);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memcpy(t33, t27, 3U);
    xsi_driver_first_trans_fast_port(t29);

LAB2:    t34 = (t0 + 12248);
    *((int *)t34) = 1;

LAB1:    return;
LAB3:    t2 = (t0 + 4264U);
    t10 = *((char **)t2);
    t11 = *((int *)t10);
    t2 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t9, t11, 3);
    t12 = (t0 + 13560);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 3U);
    xsi_driver_first_trans_fast_port(t12);
    goto LAB2;

LAB5:    t2 = (t0 + 4104U);
    t6 = *((char **)t2);
    t7 = *((int *)t6);
    t8 = (t7 != 0);
    t1 = t8;
    goto LAB7;

LAB8:    t17 = (t0 + 18820);
    t22 = (t0 + 13560);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t17, 3U);
    xsi_driver_first_trans_fast_port(t22);
    goto LAB2;

LAB11:    goto LAB2;

}

static void work_a_0966806966_3763094686_p_20(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    int t3;
    unsigned char t4;
    char *t6;
    int t7;
    char *t8;
    int t9;
    char *t10;
    int t11;
    int t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 4104U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t4 = (t3 != 0);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t19 = (t0 + 18826);
    t21 = (t0 + 13624);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t19, 3U);
    xsi_driver_first_trans_fast_port(t21);

LAB2:    t26 = (t0 + 12264);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3944U);
    t6 = *((char **)t1);
    t7 = *((int *)t6);
    t1 = (t0 + 4264U);
    t8 = *((char **)t1);
    t9 = *((int *)t8);
    t1 = (t0 + 4104U);
    t10 = *((char **)t1);
    t11 = *((int *)t10);
    t12 = (t9 * t11);
    t13 = (t7 - t12);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t5, t13, 3);
    t14 = (t0 + 13624);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t1, 3U);
    xsi_driver_first_trans_fast_port(t14);
    goto LAB2;

LAB6:    goto LAB2;

}


extern void work_a_0966806966_3763094686_init()
{
	static char *pe[] = {(void *)work_a_0966806966_3763094686_p_0,(void *)work_a_0966806966_3763094686_p_1,(void *)work_a_0966806966_3763094686_p_2,(void *)work_a_0966806966_3763094686_p_3,(void *)work_a_0966806966_3763094686_p_4,(void *)work_a_0966806966_3763094686_p_5,(void *)work_a_0966806966_3763094686_p_6,(void *)work_a_0966806966_3763094686_p_7,(void *)work_a_0966806966_3763094686_p_8,(void *)work_a_0966806966_3763094686_p_9,(void *)work_a_0966806966_3763094686_p_10,(void *)work_a_0966806966_3763094686_p_11,(void *)work_a_0966806966_3763094686_p_12,(void *)work_a_0966806966_3763094686_p_13,(void *)work_a_0966806966_3763094686_p_14,(void *)work_a_0966806966_3763094686_p_15,(void *)work_a_0966806966_3763094686_p_16,(void *)work_a_0966806966_3763094686_p_17,(void *)work_a_0966806966_3763094686_p_18,(void *)work_a_0966806966_3763094686_p_19,(void *)work_a_0966806966_3763094686_p_20};
	xsi_register_didat("work_a_0966806966_3763094686", "isim/tb_divisao_isim_beh.exe.sim/work/a_0966806966_3763094686.didat");
	xsi_register_executes(pe);
}
