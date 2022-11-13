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
static int ng0[] = {2, 0};
static unsigned int ng1[] = {12288U, 0U};
static const char *ng2 = "code.txt";
static int ng3[] = {0, 0};
static int ng4[] = {4096, 0};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {4294967292U, 0U};
static int ng7[] = {31, 0};
static int ng8[] = {24, 0};
static int ng9[] = {23, 0};
static int ng10[] = {16, 0};
static int ng11[] = {15, 0};
static int ng12[] = {8, 0};
static int ng13[] = {7, 0};
static const char *ng14 = "%d@%h: $%d <= %h";
static const char *ng15 = "%d@%h: *%h <= %h";



static void Cont_53_0(char *t0)
{
    char t5[8];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 4928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 3848);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3848);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 1688U);
    t13 = *((char **)t12);
    t12 = ((char*)((ng0)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_rshift(t14, 32, t13, 32, t12, 32);
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t14, 32, 2);
    t15 = (t0 + 6632);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t5, 8);
    xsi_driver_vfirst_trans(t15, 0, 31);
    t20 = (t0 + 6488);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_54_1(char *t0)
{
    char t5[8];
    char t14[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    t1 = (t0 + 5176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 4008);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4008);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 1368U);
    t13 = *((char **)t12);
    t12 = ((char*)((ng1)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 32, t13, 32, t12, 32);
    t15 = ((char*)((ng0)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_rshift(t16, 32, t14, 32, t15, 32);
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t16, 32, 2);
    t17 = (t0 + 6696);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t5, 8);
    xsi_driver_vfirst_trans(t17, 0, 31);
    t22 = (t0 + 6504);
    *((int *)t22) = 1;

LAB1:    return;
}

static void Initial_56_2(char *t0)
{
    char t5[8];
    char t14[8];
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    int t27;
    char *t28;
    unsigned int t29;
    int t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    int t34;
    int t35;

LAB0:
LAB2:    t1 = (t0 + 4008);
    xsi_vlogfile_readmemh(ng2, 0, t1, 0, 0, 0, 0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 3368);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB3:    t1 = (t0 + 3368);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng4)));
    memset(t5, 0, 8);
    xsi_vlog_signed_less(t5, 32, t3, 32, t4, 32);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t12 = ((char*)((ng3)));
    t13 = (t0 + 3848);
    t16 = (t0 + 3848);
    t17 = (t16 + 72U);
    t18 = *((char **)t17);
    t19 = (t0 + 3848);
    t20 = (t19 + 64U);
    t21 = *((char **)t20);
    t22 = (t0 + 3368);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_array_indices(t14, t15, t18, t21, 2, 1, t24, 32, 1);
    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (!(t26));
    t28 = (t15 + 4);
    t29 = *((unsigned int *)t28);
    t30 = (!(t29));
    t31 = (t27 && t30);
    if (t31 == 1)
        goto LAB6;

LAB7:    t1 = (t0 + 3368);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng5)));
    memset(t5, 0, 8);
    xsi_vlog_signed_add(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 3368);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    goto LAB3;

LAB6:    t32 = *((unsigned int *)t14);
    t33 = *((unsigned int *)t15);
    t34 = (t32 - t33);
    t35 = (t34 + 1);
    xsi_vlogvar_wait_assign_value(t13, t12, 0, *((unsigned int *)t15), t35, 0LL);
    goto LAB7;

}

static void Always_62_3(char *t0)
{
    char t7[8];
    char t16[8];
    char t44[8];
    char t45[8];
    char t46[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t47;
    int t48;
    char *t49;
    int t50;
    int t51;
    int t52;
    int t53;
    int t54;

LAB0:    t1 = (t0 + 5672U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6520);
    *((int *)t2) = 1;
    t3 = (t0 + 5704);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 3848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 3848);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3848);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t14 = (t0 + 1688U);
    t15 = *((char **)t14);
    t14 = ((char*)((ng0)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_rshift(t16, 32, t15, 32, t14, 32);
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t10, t13, 2, 1, t16, 32, 2);
    t17 = (t0 + 3688);
    xsi_vlogvar_assign_value(t17, t7, 0, 0, 32);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t2);
    t20 = (t18 & t19);
    *((unsigned int *)t7) = t20;
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = (t7 + 4);
    t21 = *((unsigned int *)t4);
    t22 = *((unsigned int *)t5);
    t23 = (t21 | t22);
    *((unsigned int *)t6) = t23;
    t24 = *((unsigned int *)t6);
    t25 = (t24 != 0);
    if (t25 == 1)
        goto LAB6;

LAB7:
LAB8:    t10 = (t0 + 3528);
    xsi_vlogvar_assign_value(t10, t7, 0, 0, 32);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (t18 >> 3);
    t20 = (t19 & 1);
    *((unsigned int *)t7) = t20;
    t21 = *((unsigned int *)t4);
    t22 = (t21 >> 3);
    t23 = (t22 & 1);
    *((unsigned int *)t2) = t23;
    t5 = (t7 + 4);
    t24 = *((unsigned int *)t5);
    t25 = (~(t24));
    t26 = *((unsigned int *)t7);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB9;

LAB10:
LAB11:    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (t18 >> 2);
    t20 = (t19 & 1);
    *((unsigned int *)t7) = t20;
    t21 = *((unsigned int *)t4);
    t22 = (t21 >> 2);
    t23 = (t22 & 1);
    *((unsigned int *)t2) = t23;
    t5 = (t7 + 4);
    t24 = *((unsigned int *)t5);
    t25 = (~(t24));
    t26 = *((unsigned int *)t7);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB14;

LAB15:
LAB16:    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (t18 >> 1);
    t20 = (t19 & 1);
    *((unsigned int *)t7) = t20;
    t21 = *((unsigned int *)t4);
    t22 = (t21 >> 1);
    t23 = (t22 & 1);
    *((unsigned int *)t2) = t23;
    t5 = (t7 + 4);
    t24 = *((unsigned int *)t5);
    t25 = (~(t24));
    t26 = *((unsigned int *)t7);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB19;

LAB20:
LAB21:    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t7) = t20;
    t21 = *((unsigned int *)t4);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t2) = t23;
    t5 = (t7 + 4);
    t24 = *((unsigned int *)t5);
    t25 = (~(t24));
    t26 = *((unsigned int *)t7);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    t26 = *((unsigned int *)t7);
    t27 = *((unsigned int *)t6);
    *((unsigned int *)t7) = (t26 | t27);
    t8 = (t3 + 4);
    t9 = (t2 + 4);
    t28 = *((unsigned int *)t3);
    t29 = (~(t28));
    t30 = *((unsigned int *)t8);
    t31 = (~(t30));
    t32 = *((unsigned int *)t2);
    t33 = (~(t32));
    t34 = *((unsigned int *)t9);
    t35 = (~(t34));
    t36 = (t29 & t31);
    t37 = (t33 & t35);
    t38 = (~(t36));
    t39 = (~(t37));
    t40 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t40 & t38);
    t41 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t41 & t39);
    t42 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t42 & t38);
    t43 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t43 & t39);
    goto LAB8;

LAB9:    t6 = (t0 + 2008U);
    t8 = *((char **)t6);
    memset(t16, 0, 8);
    t6 = (t16 + 4);
    t9 = (t8 + 4);
    t29 = *((unsigned int *)t8);
    t30 = (t29 >> 24);
    *((unsigned int *)t16) = t30;
    t31 = *((unsigned int *)t9);
    t32 = (t31 >> 24);
    *((unsigned int *)t6) = t32;
    t33 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t33 & 255U);
    t34 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t34 & 255U);
    t10 = (t0 + 3688);
    t11 = (t0 + 3688);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng7)));
    t15 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t13)), 2, t14, 32, 1, t15, 32, 1);
    t17 = (t44 + 4);
    t35 = *((unsigned int *)t17);
    t36 = (!(t35));
    t47 = (t45 + 4);
    t38 = *((unsigned int *)t47);
    t37 = (!(t38));
    t48 = (t36 && t37);
    t49 = (t46 + 4);
    t39 = *((unsigned int *)t49);
    t50 = (!(t39));
    t51 = (t48 && t50);
    if (t51 == 1)
        goto LAB12;

LAB13:    goto LAB11;

LAB12:    t40 = *((unsigned int *)t46);
    t52 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t53 = (t41 - t42);
    t54 = (t53 + 1);
    xsi_vlogvar_assign_value(t10, t16, t52, *((unsigned int *)t45), t54);
    goto LAB13;

LAB14:    t6 = (t0 + 2008U);
    t8 = *((char **)t6);
    memset(t16, 0, 8);
    t6 = (t16 + 4);
    t9 = (t8 + 4);
    t29 = *((unsigned int *)t8);
    t30 = (t29 >> 16);
    *((unsigned int *)t16) = t30;
    t31 = *((unsigned int *)t9);
    t32 = (t31 >> 16);
    *((unsigned int *)t6) = t32;
    t33 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t33 & 255U);
    t34 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t34 & 255U);
    t10 = (t0 + 3688);
    t11 = (t0 + 3688);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng9)));
    t15 = ((char*)((ng10)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t13)), 2, t14, 32, 1, t15, 32, 1);
    t17 = (t44 + 4);
    t35 = *((unsigned int *)t17);
    t36 = (!(t35));
    t47 = (t45 + 4);
    t38 = *((unsigned int *)t47);
    t37 = (!(t38));
    t48 = (t36 && t37);
    t49 = (t46 + 4);
    t39 = *((unsigned int *)t49);
    t50 = (!(t39));
    t51 = (t48 && t50);
    if (t51 == 1)
        goto LAB17;

LAB18:    goto LAB16;

LAB17:    t40 = *((unsigned int *)t46);
    t52 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t53 = (t41 - t42);
    t54 = (t53 + 1);
    xsi_vlogvar_assign_value(t10, t16, t52, *((unsigned int *)t45), t54);
    goto LAB18;

LAB19:    t6 = (t0 + 2008U);
    t8 = *((char **)t6);
    memset(t16, 0, 8);
    t6 = (t16 + 4);
    t9 = (t8 + 4);
    t29 = *((unsigned int *)t8);
    t30 = (t29 >> 8);
    *((unsigned int *)t16) = t30;
    t31 = *((unsigned int *)t9);
    t32 = (t31 >> 8);
    *((unsigned int *)t6) = t32;
    t33 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t33 & 255U);
    t34 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t34 & 255U);
    t10 = (t0 + 3688);
    t11 = (t0 + 3688);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng11)));
    t15 = ((char*)((ng12)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t13)), 2, t14, 32, 1, t15, 32, 1);
    t17 = (t44 + 4);
    t35 = *((unsigned int *)t17);
    t36 = (!(t35));
    t47 = (t45 + 4);
    t38 = *((unsigned int *)t47);
    t37 = (!(t38));
    t48 = (t36 && t37);
    t49 = (t46 + 4);
    t39 = *((unsigned int *)t49);
    t50 = (!(t39));
    t51 = (t48 && t50);
    if (t51 == 1)
        goto LAB22;

LAB23:    goto LAB21;

LAB22:    t40 = *((unsigned int *)t46);
    t52 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t53 = (t41 - t42);
    t54 = (t53 + 1);
    xsi_vlogvar_assign_value(t10, t16, t52, *((unsigned int *)t45), t54);
    goto LAB23;

LAB24:    t6 = (t0 + 2008U);
    t8 = *((char **)t6);
    memset(t16, 0, 8);
    t6 = (t16 + 4);
    t9 = (t8 + 4);
    t29 = *((unsigned int *)t8);
    t30 = (t29 >> 0);
    *((unsigned int *)t16) = t30;
    t31 = *((unsigned int *)t9);
    t32 = (t31 >> 0);
    *((unsigned int *)t6) = t32;
    t33 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t33 & 255U);
    t34 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t34 & 255U);
    t10 = (t0 + 3688);
    t11 = (t0 + 3688);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng13)));
    t15 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t44, t45, t46, ((int*)(t13)), 2, t14, 32, 1, t15, 32, 1);
    t17 = (t44 + 4);
    t35 = *((unsigned int *)t17);
    t36 = (!(t35));
    t47 = (t45 + 4);
    t38 = *((unsigned int *)t47);
    t37 = (!(t38));
    t48 = (t36 && t37);
    t49 = (t46 + 4);
    t39 = *((unsigned int *)t49);
    t50 = (!(t39));
    t51 = (t48 && t50);
    if (t51 == 1)
        goto LAB27;

LAB28:    goto LAB26;

LAB27:    t40 = *((unsigned int *)t46);
    t52 = (t40 + 0);
    t41 = *((unsigned int *)t44);
    t42 = *((unsigned int *)t45);
    t53 = (t41 - t42);
    t54 = (t53 + 1);
    xsi_vlogvar_assign_value(t10, t16, t52, *((unsigned int *)t45), t54);
    goto LAB28;

}

static void Always_73_4(char *t0)
{
    char t4[8];
    char t31[8];
    char t44[8];
    char t60[8];
    char t68[8];
    char t106[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    int t92;
    int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;

LAB0:    t1 = (t0 + 5920U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6536);
    *((int *)t2) = 1;
    t3 = (t0 + 5952);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t5 = (t0 + 1208U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    *((unsigned int *)t4) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB11;

LAB10:    t21 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t4 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB12;

LAB13:
LAB14:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB11:    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t4) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB10;

LAB12:
LAB15:    t29 = (t0 + 2488U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    t29 = (t30 + 4);
    t32 = *((unsigned int *)t29);
    t33 = (~(t32));
    t34 = *((unsigned int *)t30);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t29) != 0)
        goto LAB18;

LAB19:    t38 = (t31 + 4);
    t39 = *((unsigned int *)t31);
    t40 = *((unsigned int *)t38);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB20;

LAB21:    memcpy(t68, t31, 8);

LAB22:    t100 = (t68 + 4);
    t101 = *((unsigned int *)t100);
    t102 = (~(t101));
    t103 = *((unsigned int *)t68);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB34;

LAB35:
LAB36:    goto LAB14;

LAB16:    *((unsigned int *)t31) = 1;
    goto LAB19;

LAB18:    t37 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB19;

LAB20:    t42 = (t0 + 2648U);
    t43 = *((char **)t42);
    t42 = ((char*)((ng3)));
    memset(t44, 0, 8);
    t45 = (t43 + 4);
    t46 = (t42 + 4);
    t47 = *((unsigned int *)t43);
    t48 = *((unsigned int *)t42);
    t49 = (t47 ^ t48);
    t50 = *((unsigned int *)t45);
    t51 = *((unsigned int *)t46);
    t52 = (t50 ^ t51);
    t53 = (t49 | t52);
    t54 = *((unsigned int *)t45);
    t55 = *((unsigned int *)t46);
    t56 = (t54 | t55);
    t57 = (~(t56));
    t58 = (t53 & t57);
    if (t58 != 0)
        goto LAB24;

LAB23:    if (t56 != 0)
        goto LAB25;

LAB26:    memset(t60, 0, 8);
    t61 = (t44 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t44);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t61) != 0)
        goto LAB29;

LAB30:    t69 = *((unsigned int *)t31);
    t70 = *((unsigned int *)t60);
    t71 = (t69 & t70);
    *((unsigned int *)t68) = t71;
    t72 = (t31 + 4);
    t73 = (t60 + 4);
    t74 = (t68 + 4);
    t75 = *((unsigned int *)t72);
    t76 = *((unsigned int *)t73);
    t77 = (t75 | t76);
    *((unsigned int *)t74) = t77;
    t78 = *((unsigned int *)t74);
    t79 = (t78 != 0);
    if (t79 == 1)
        goto LAB31;

LAB32:
LAB33:    goto LAB22;

LAB24:    *((unsigned int *)t44) = 1;
    goto LAB26;

LAB25:    t59 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB26;

LAB27:    *((unsigned int *)t60) = 1;
    goto LAB30;

LAB29:    t67 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t67) = 1;
    goto LAB30;

LAB31:    t80 = *((unsigned int *)t68);
    t81 = *((unsigned int *)t74);
    *((unsigned int *)t68) = (t80 | t81);
    t82 = (t31 + 4);
    t83 = (t60 + 4);
    t84 = *((unsigned int *)t31);
    t85 = (~(t84));
    t86 = *((unsigned int *)t82);
    t87 = (~(t86));
    t88 = *((unsigned int *)t60);
    t89 = (~(t88));
    t90 = *((unsigned int *)t83);
    t91 = (~(t90));
    t92 = (t85 & t87);
    t93 = (t89 & t91);
    t94 = (~(t92));
    t95 = (~(t93));
    t96 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t96 & t94);
    t97 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t97 & t95);
    t98 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t98 & t94);
    t99 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t99 & t95);
    goto LAB33;

LAB34:
LAB37:    t107 = xsi_vlog_time(t106, 1000.0000000000000, 1000.0000000000000);
    t108 = (t0 + 2968U);
    t109 = *((char **)t108);
    t108 = (t0 + 2648U);
    t110 = *((char **)t108);
    t108 = (t0 + 2808U);
    t111 = *((char **)t108);
    xsi_vlogfile_write(1, 0, 0, ng14, 5, t0, (char)118, t106, 64, (char)118, t109, 32, (char)118, t110, 5, (char)118, t111, 32);
    goto LAB36;

}

static void Always_80_5(char *t0)
{
    char t13[8];
    char t15[8];
    char t16[8];
    char t38[8];
    char t45[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    char *t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;

LAB0:    t1 = (t0 + 6168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6552);
    *((int *)t2) = 1;
    t3 = (t0 + 6200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 15U);
    if (t10 != 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t2) != 0)
        goto LAB16;

LAB17:    t5 = (t13 + 4);
    t27 = *((unsigned int *)t5);
    t30 = (~(t27));
    t33 = *((unsigned int *)t13);
    t34 = (t33 & t30);
    t37 = (t34 != 0);
    if (t37 > 0)
        goto LAB18;

LAB19:
LAB20:
LAB8:    goto LAB2;

LAB6:    t11 = ((char*)((ng3)));
    t12 = (t0 + 3368);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);

LAB9:    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_signed_less(t13, 32, t4, 32, t5, 32);
    t11 = (t13 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:    goto LAB8;

LAB10:    t12 = ((char*)((ng3)));
    t14 = (t0 + 3848);
    t17 = (t0 + 3848);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t20 = (t0 + 3848);
    t21 = (t20 + 64U);
    t22 = *((char **)t21);
    t23 = (t0 + 3368);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    xsi_vlog_generic_convert_array_indices(t15, t16, t19, t22, 2, 1, t25, 32, 1);
    t26 = (t15 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t16 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB12;

LAB13:    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t13, 0, 8);
    xsi_vlog_signed_add(t13, 32, t4, 32, t5, 32);
    t11 = (t0 + 3368);
    xsi_vlogvar_assign_value(t11, t13, 0, 0, 32);
    goto LAB9;

LAB12:    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t16);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_wait_assign_value(t14, t12, 0, *((unsigned int *)t16), t36, 0LL);
    goto LAB13;

LAB14:    *((unsigned int *)t13) = 1;
    goto LAB17;

LAB16:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB17;

LAB18:
LAB21:    t11 = (t0 + 3688);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t17 = (t0 + 3848);
    t18 = (t0 + 3848);
    t19 = (t18 + 72U);
    t20 = *((char **)t19);
    t21 = (t0 + 3848);
    t22 = (t21 + 64U);
    t23 = *((char **)t22);
    t24 = (t0 + 3528);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t29 = ((char*)((ng0)));
    memset(t38, 0, 8);
    xsi_vlog_unsigned_rshift(t38, 32, t26, 32, t29, 32);
    xsi_vlog_generic_convert_array_indices(t15, t16, t20, t23, 2, 1, t38, 32, 2);
    t39 = (t15 + 4);
    t40 = *((unsigned int *)t39);
    t28 = (!(t40));
    t41 = (t16 + 4);
    t42 = *((unsigned int *)t41);
    t31 = (!(t42));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB22;

LAB23:    t2 = xsi_vlog_time(t45, 1000.0000000000000, 1000.0000000000000);
    t3 = (t0 + 2328U);
    t4 = *((char **)t3);
    t3 = (t0 + 3528);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 3688);
    t14 = (t12 + 56U);
    t17 = *((char **)t14);
    xsi_vlogfile_write(1, 0, 0, ng15, 5, t0, (char)118, t45, 64, (char)118, t4, 32, (char)118, t11, 32, (char)118, t17, 32);
    goto LAB20;

LAB22:    t43 = *((unsigned int *)t15);
    t44 = *((unsigned int *)t16);
    t35 = (t43 - t44);
    t36 = (t35 + 1);
    xsi_vlogvar_wait_assign_value(t17, t14, 0, *((unsigned int *)t16), t36, 0LL);
    goto LAB23;

}


extern void work_m_00000000002440506025_3877310806_init()
{
	static char *pe[] = {(void *)Cont_53_0,(void *)Cont_54_1,(void *)Initial_56_2,(void *)Always_62_3,(void *)Always_73_4,(void *)Always_80_5};
	xsi_register_didat("work_m_00000000002440506025_3877310806", "isim/mips.exe.sim/work/m_00000000002440506025_3877310806.didat");
	xsi_register_executes(pe);
}
