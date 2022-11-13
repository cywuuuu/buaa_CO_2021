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
static unsigned int ng0[] = {1U, 0U};
static int ng1[] = {4, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {14, 0};
static unsigned int ng4[] = {4U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {3U, 0U};
static int ng7[] = {8, 0};
static unsigned int ng8[] = {16768U, 0U};



static void Always_25_0(char *t0)
{
    char t16[8];
    char t17[8];
    char t19[8];
    char t29[8];
    char t33[8];
    char t41[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t18;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t42;

LAB0:    t1 = (t0 + 4128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4944);
    *((int *)t2) = 1;
    t3 = (t0 + 4160);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 2008U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng0)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t3, 32, t2, 32);
    t4 = (t0 + 3208);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 32);

LAB19:    goto LAB2;

LAB7:
LAB20:    t7 = (t0 + 2168U);
    t8 = *((char **)t7);
    t7 = (t8 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t8);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB21;

LAB22:    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3208);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 32);

LAB23:    goto LAB19;

LAB9:
LAB24:    t3 = (t0 + 2168U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB25;

LAB26:    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3208);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 32);

LAB27:    goto LAB19;

LAB11:    t3 = ((char*)((ng2)));
    t4 = (t0 + 1848U);
    t7 = *((char **)t4);
    t4 = (t0 + 1208U);
    t8 = *((char **)t4);
    memset(t17, 0, 8);
    t4 = (t17 + 4);
    t14 = (t8 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (t9 >> 28);
    *((unsigned int *)t17) = t10;
    t11 = *((unsigned int *)t14);
    t12 = (t11 >> 28);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t13 & 15U);
    t23 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t23 & 15U);
    xsi_vlogtype_concat(t16, 32, 32, 3U, t17, 4, t7, 26, t3, 2);
    t15 = (t0 + 3208);
    xsi_vlogvar_assign_value(t15, t16, 0, 0, 32);
    goto LAB19;

LAB13:    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 32);
    goto LAB19;

LAB15:    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng1)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t4, 32, t3, 32);
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t16, 0, 0, 32);
    goto LAB19;

LAB21:    t14 = (t0 + 1208U);
    t15 = *((char **)t14);
    t14 = ((char*)((ng1)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t15, 32, t14, 32);
    t18 = ((char*)((ng2)));
    t20 = (t0 + 1848U);
    t21 = *((char **)t20);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t22 = (t21 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (t23 >> 0);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t22);
    t26 = (t25 >> 0);
    *((unsigned int *)t20) = t26;
    t27 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t27 & 65535U);
    t28 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t28 & 65535U);
    t30 = ((char*)((ng3)));
    t31 = (t0 + 1848U);
    t32 = *((char **)t31);
    memset(t33, 0, 8);
    t31 = (t33 + 4);
    t34 = (t32 + 4);
    t35 = *((unsigned int *)t32);
    t36 = (t35 >> 15);
    t37 = (t36 & 1);
    *((unsigned int *)t33) = t37;
    t38 = *((unsigned int *)t34);
    t39 = (t38 >> 15);
    t40 = (t39 & 1);
    *((unsigned int *)t31) = t40;
    xsi_vlog_mul_concat(t29, 14, 1, t30, 1U, t33, 1);
    xsi_vlogtype_concat(t17, 32, 32, 3U, t29, 14, t19, 16, t18, 2);
    memset(t41, 0, 8);
    xsi_vlog_unsigned_add(t41, 32, t16, 32, t17, 32);
    t42 = (t0 + 3208);
    xsi_vlogvar_assign_value(t42, t41, 0, 0, 32);
    goto LAB23;

LAB25:    t7 = (t0 + 1688U);
    t8 = *((char **)t7);
    t7 = (t0 + 3208);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 32);
    goto LAB27;

}

static void Cont_42_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t3, 32, t2, 32);
    t5 = (t0 + 5056);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t4, 8);
    xsi_driver_vfirst_trans(t5, 0, 31);
    t10 = (t0 + 4960);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Cont_43_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char t22[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;

LAB0:    t1 = (t0 + 4624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2328U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t17 = *((unsigned int *)t4);
    t18 = (~(t17));
    t19 = *((unsigned int *)t12);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t21, 8);

LAB16:    t45 = (t0 + 5120);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    memcpy(t49, t3, 8);
    xsi_driver_vfirst_trans(t45, 0, 31);
    t50 = (t0 + 4976);
    *((int *)t50) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = ((char*)((ng8)));
    goto LAB9;

LAB10:    t23 = (t0 + 2488U);
    t24 = *((char **)t23);
    memset(t22, 0, 8);
    t23 = (t24 + 4);
    t25 = *((unsigned int *)t23);
    t26 = (~(t25));
    t27 = *((unsigned int *)t24);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t23) != 0)
        goto LAB19;

LAB20:    t31 = (t22 + 4);
    t32 = *((unsigned int *)t22);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB21;

LAB22:    t38 = *((unsigned int *)t22);
    t39 = (~(t38));
    t40 = *((unsigned int *)t31);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t31) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t22) > 0)
        goto LAB27;

LAB28:    memcpy(t21, t44, 8);

LAB29:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t16, 32, t21, 32);
    goto LAB16;

LAB14:    memcpy(t3, t16, 8);
    goto LAB16;

LAB17:    *((unsigned int *)t22) = 1;
    goto LAB20;

LAB19:    t30 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB21:    t35 = (t0 + 1368U);
    t36 = *((char **)t35);
    t35 = ((char*)((ng1)));
    memset(t37, 0, 8);
    xsi_vlog_unsigned_add(t37, 32, t36, 32, t35, 32);
    goto LAB22;

LAB23:    t42 = (t0 + 3208);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t21, 32, t37, 32, t44, 32);
    goto LAB29;

LAB27:    memcpy(t21, t37, 8);
    goto LAB29;

}


extern void work_m_00000000000926058785_0757879789_init()
{
	static char *pe[] = {(void *)Always_25_0,(void *)Cont_42_1,(void *)Cont_43_2};
	xsi_register_didat("work_m_00000000000926058785_0757879789", "isim/mips.exe.sim/work/m_00000000000926058785_0757879789.didat");
	xsi_register_executes(pe);
}
