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
static unsigned int ng0[] = {0U, 0U};
static unsigned int ng1[] = {1U, 0U};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0};
static int ng4[] = {16, 0};
static unsigned int ng5[] = {2U, 0U};
static int ng6[] = {24, 0};



static void Always_29_0(char *t0)
{
    char t14[8];
    char t19[8];
    char t41[8];
    char t42[8];
    char t52[8];
    char t56[8];
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
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t20;
    char *t21;
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
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t53;
    char *t54;
    char *t55;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;

LAB0:    t1 = (t0 + 2848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3168);
    *((int *)t2) = 1;
    t3 = (t0 + 2880);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1368U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng0)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB7:    t7 = (t0 + 1208U);
    t8 = *((char **)t7);
    t7 = (t0 + 1928);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 32);
    goto LAB13;

LAB9:
LAB14:    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB15;

LAB16:
LAB26:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1008U);
    t4 = (t2 + 72U);
    t7 = *((char **)t4);
    t8 = ((char*)((ng2)));
    xsi_vlog_generic_get_index_select_value(t14, 32, t3, t7, 2, t8, 32, 1);
    t15 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t16 = (t14 + 4);
    t17 = (t15 + 4);
    t9 = *((unsigned int *)t14);
    t10 = *((unsigned int *)t15);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t16);
    t13 = *((unsigned int *)t17);
    t22 = (t12 ^ t13);
    t23 = (t11 | t22);
    t24 = *((unsigned int *)t16);
    t25 = *((unsigned int *)t17);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t28 = (t23 & t27);
    if (t28 != 0)
        goto LAB30;

LAB27:    if (t26 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t19) = 1;

LAB30:    t20 = (t19 + 4);
    t29 = *((unsigned int *)t20);
    t30 = (~(t29));
    t31 = *((unsigned int *)t19);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB31;

LAB32:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t19, 0, 8);
    t2 = (t19 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 16);
    *((unsigned int *)t19) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 16);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t13 & 65535U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 65535U);
    t7 = ((char*)((ng0)));
    xsi_vlogtype_concat(t14, 32, 32, 2U, t7, 16, t19, 16);
    t8 = (t0 + 1928);
    xsi_vlogvar_assign_value(t8, t14, 0, 0, 32);

LAB33:
LAB17:    goto LAB13;

LAB11:
LAB34:    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB60:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t13 & 3U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 3U);
    t7 = ((char*)((ng0)));
    memset(t19, 0, 8);
    t8 = (t14 + 4);
    t15 = (t7 + 4);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t7);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t15);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t36 = (t29 & t33);
    if (t36 != 0)
        goto LAB64;

LAB61:    if (t32 != 0)
        goto LAB63;

LAB62:    *((unsigned int *)t19) = 1;

LAB64:    t17 = (t19 + 4);
    t37 = *((unsigned int *)t17);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (t39 & t38);
    t46 = (t40 != 0);
    if (t46 > 0)
        goto LAB65;

LAB66:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t13 & 3U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 3U);
    t7 = ((char*)((ng1)));
    memset(t19, 0, 8);
    t8 = (t14 + 4);
    t15 = (t7 + 4);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t7);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t15);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t36 = (t29 & t33);
    if (t36 != 0)
        goto LAB71;

LAB68:    if (t32 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t19) = 1;

LAB71:    t17 = (t19 + 4);
    t37 = *((unsigned int *)t17);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (t39 & t38);
    t46 = (t40 != 0);
    if (t46 > 0)
        goto LAB72;

LAB73:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t13 & 3U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 3U);
    t7 = ((char*)((ng5)));
    memset(t19, 0, 8);
    t8 = (t14 + 4);
    t15 = (t7 + 4);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t7);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t15);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t36 = (t29 & t33);
    if (t36 != 0)
        goto LAB78;

LAB75:    if (t32 != 0)
        goto LAB77;

LAB76:    *((unsigned int *)t19) = 1;

LAB78:    t17 = (t19 + 4);
    t37 = *((unsigned int *)t17);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (t39 & t38);
    t46 = (t40 != 0);
    if (t46 > 0)
        goto LAB79;

LAB80:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t19, 0, 8);
    t2 = (t19 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 24);
    *((unsigned int *)t19) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 24);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t13 & 255U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 255U);
    t7 = ((char*)((ng0)));
    xsi_vlogtype_concat(t14, 32, 32, 2U, t7, 24, t19, 8);
    t8 = (t0 + 1928);
    xsi_vlogvar_assign_value(t8, t14, 0, 0, 32);

LAB81:
LAB74:
LAB67:
LAB37:    goto LAB13;

LAB15:
LAB18:    t7 = (t0 + 1048U);
    t8 = *((char **)t7);
    t7 = (t0 + 1008U);
    t15 = (t7 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng2)));
    xsi_vlog_generic_get_index_select_value(t14, 32, t8, t16, 2, t17, 32, 1);
    t18 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t20 = (t14 + 4);
    t21 = (t18 + 4);
    t22 = *((unsigned int *)t14);
    t23 = *((unsigned int *)t18);
    t24 = (t22 ^ t23);
    t25 = *((unsigned int *)t20);
    t26 = *((unsigned int *)t21);
    t27 = (t25 ^ t26);
    t28 = (t24 | t27);
    t29 = *((unsigned int *)t20);
    t30 = *((unsigned int *)t21);
    t31 = (t29 | t30);
    t32 = (~(t31));
    t33 = (t28 & t32);
    if (t33 != 0)
        goto LAB22;

LAB19:    if (t31 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t19) = 1;

LAB22:    t35 = (t19 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t19);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB23;

LAB24:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t19, 0, 8);
    t2 = (t19 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 16);
    *((unsigned int *)t19) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 16);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t13 & 65535U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 65535U);
    t7 = ((char*)((ng4)));
    t8 = (t0 + 1208U);
    t15 = *((char **)t8);
    memset(t42, 0, 8);
    t8 = (t42 + 4);
    t16 = (t15 + 4);
    t23 = *((unsigned int *)t15);
    t24 = (t23 >> 31);
    t25 = (t24 & 1);
    *((unsigned int *)t42) = t25;
    t26 = *((unsigned int *)t16);
    t27 = (t26 >> 31);
    t28 = (t27 & 1);
    *((unsigned int *)t8) = t28;
    xsi_vlog_mul_concat(t41, 16, 1, t7, 1U, t42, 1);
    xsi_vlogtype_concat(t14, 32, 32, 2U, t41, 16, t19, 16);
    t17 = (t0 + 1928);
    xsi_vlogvar_assign_value(t17, t14, 0, 0, 32);

LAB25:    goto LAB17;

LAB21:    t34 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB22;

LAB23:    t43 = (t0 + 1208U);
    t44 = *((char **)t43);
    memset(t42, 0, 8);
    t43 = (t42 + 4);
    t45 = (t44 + 4);
    t46 = *((unsigned int *)t44);
    t47 = (t46 >> 0);
    *((unsigned int *)t42) = t47;
    t48 = *((unsigned int *)t45);
    t49 = (t48 >> 0);
    *((unsigned int *)t43) = t49;
    t50 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t50 & 65535U);
    t51 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t51 & 65535U);
    t53 = ((char*)((ng4)));
    t54 = (t0 + 1208U);
    t55 = *((char **)t54);
    memset(t56, 0, 8);
    t54 = (t56 + 4);
    t57 = (t55 + 4);
    t58 = *((unsigned int *)t55);
    t59 = (t58 >> 15);
    t60 = (t59 & 1);
    *((unsigned int *)t56) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 >> 15);
    t63 = (t62 & 1);
    *((unsigned int *)t54) = t63;
    xsi_vlog_mul_concat(t52, 16, 1, t53, 1U, t56, 1);
    xsi_vlogtype_concat(t41, 32, 32, 2U, t52, 16, t42, 16);
    t64 = (t0 + 1928);
    xsi_vlogvar_assign_value(t64, t41, 0, 0, 32);
    goto LAB25;

LAB29:    t18 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB30;

LAB31:    t21 = (t0 + 1208U);
    t34 = *((char **)t21);
    memset(t42, 0, 8);
    t21 = (t42 + 4);
    t35 = (t34 + 4);
    t36 = *((unsigned int *)t34);
    t37 = (t36 >> 0);
    *((unsigned int *)t42) = t37;
    t38 = *((unsigned int *)t35);
    t39 = (t38 >> 0);
    *((unsigned int *)t21) = t39;
    t40 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t40 & 65535U);
    t46 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t46 & 65535U);
    t43 = ((char*)((ng0)));
    xsi_vlogtype_concat(t41, 32, 32, 2U, t43, 16, t42, 16);
    t44 = (t0 + 1928);
    xsi_vlogvar_assign_value(t44, t41, 0, 0, 32);
    goto LAB33;

LAB35:
LAB38:    t7 = (t0 + 1048U);
    t8 = *((char **)t7);
    memset(t14, 0, 8);
    t7 = (t14 + 4);
    t15 = (t8 + 4);
    t22 = *((unsigned int *)t8);
    t23 = (t22 >> 0);
    *((unsigned int *)t14) = t23;
    t24 = *((unsigned int *)t15);
    t25 = (t24 >> 0);
    *((unsigned int *)t7) = t25;
    t26 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t26 & 3U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 3U);
    t16 = ((char*)((ng0)));
    memset(t19, 0, 8);
    t17 = (t14 + 4);
    t18 = (t16 + 4);
    t28 = *((unsigned int *)t14);
    t29 = *((unsigned int *)t16);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t17);
    t32 = *((unsigned int *)t18);
    t33 = (t31 ^ t32);
    t36 = (t30 | t33);
    t37 = *((unsigned int *)t17);
    t38 = *((unsigned int *)t18);
    t39 = (t37 | t38);
    t40 = (~(t39));
    t46 = (t36 & t40);
    if (t46 != 0)
        goto LAB42;

LAB39:    if (t39 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t19) = 1;

LAB42:    t21 = (t19 + 4);
    t47 = *((unsigned int *)t21);
    t48 = (~(t47));
    t49 = *((unsigned int *)t19);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB43;

LAB44:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t13 & 3U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 3U);
    t7 = ((char*)((ng1)));
    memset(t19, 0, 8);
    t8 = (t14 + 4);
    t15 = (t7 + 4);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t7);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t15);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t36 = (t29 & t33);
    if (t36 != 0)
        goto LAB49;

LAB46:    if (t32 != 0)
        goto LAB48;

LAB47:    *((unsigned int *)t19) = 1;

LAB49:    t17 = (t19 + 4);
    t37 = *((unsigned int *)t17);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (t39 & t38);
    t46 = (t40 != 0);
    if (t46 > 0)
        goto LAB50;

LAB51:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t13 & 3U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 3U);
    t7 = ((char*)((ng5)));
    memset(t19, 0, 8);
    t8 = (t14 + 4);
    t15 = (t7 + 4);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t7);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t15);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t36 = (t29 & t33);
    if (t36 != 0)
        goto LAB56;

LAB53:    if (t32 != 0)
        goto LAB55;

LAB54:    *((unsigned int *)t19) = 1;

LAB56:    t17 = (t19 + 4);
    t37 = *((unsigned int *)t17);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (t39 & t38);
    t46 = (t40 != 0);
    if (t46 > 0)
        goto LAB57;

LAB58:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t19, 0, 8);
    t2 = (t19 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 24);
    *((unsigned int *)t19) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 24);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t13 & 255U);
    t22 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t22 & 255U);
    t7 = ((char*)((ng6)));
    t8 = (t0 + 1208U);
    t15 = *((char **)t8);
    memset(t42, 0, 8);
    t8 = (t42 + 4);
    t16 = (t15 + 4);
    t23 = *((unsigned int *)t15);
    t24 = (t23 >> 31);
    t25 = (t24 & 1);
    *((unsigned int *)t42) = t25;
    t26 = *((unsigned int *)t16);
    t27 = (t26 >> 31);
    t28 = (t27 & 1);
    *((unsigned int *)t8) = t28;
    xsi_vlog_mul_concat(t41, 24, 1, t7, 1U, t42, 1);
    xsi_vlogtype_concat(t14, 32, 32, 2U, t41, 24, t19, 8);
    t17 = (t0 + 1928);
    xsi_vlogvar_assign_value(t17, t14, 0, 0, 32);

LAB59:
LAB52:
LAB45:    goto LAB37;

LAB41:    t20 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB42;

LAB43:    t34 = (t0 + 1208U);
    t35 = *((char **)t34);
    memset(t42, 0, 8);
    t34 = (t42 + 4);
    t43 = (t35 + 4);
    t58 = *((unsigned int *)t35);
    t59 = (t58 >> 0);
    *((unsigned int *)t42) = t59;
    t60 = *((unsigned int *)t43);
    t61 = (t60 >> 0);
    *((unsigned int *)t34) = t61;
    t62 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t62 & 255U);
    t63 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t63 & 255U);
    t44 = ((char*)((ng6)));
    t45 = (t0 + 1208U);
    t53 = *((char **)t45);
    memset(t56, 0, 8);
    t45 = (t56 + 4);
    t54 = (t53 + 4);
    t65 = *((unsigned int *)t53);
    t66 = (t65 >> 7);
    t67 = (t66 & 1);
    *((unsigned int *)t56) = t67;
    t68 = *((unsigned int *)t54);
    t69 = (t68 >> 7);
    t70 = (t69 & 1);
    *((unsigned int *)t45) = t70;
    xsi_vlog_mul_concat(t52, 24, 1, t44, 1U, t56, 1);
    xsi_vlogtype_concat(t41, 32, 32, 2U, t52, 24, t42, 8);
    t55 = (t0 + 1928);
    xsi_vlogvar_assign_value(t55, t41, 0, 0, 32);
    goto LAB45;

LAB48:    t16 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB49;

LAB50:    t18 = (t0 + 1208U);
    t20 = *((char **)t18);
    memset(t42, 0, 8);
    t18 = (t42 + 4);
    t21 = (t20 + 4);
    t47 = *((unsigned int *)t20);
    t48 = (t47 >> 8);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t21);
    t50 = (t49 >> 8);
    *((unsigned int *)t18) = t50;
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 255U);
    t58 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t58 & 255U);
    t34 = ((char*)((ng6)));
    t35 = (t0 + 1208U);
    t43 = *((char **)t35);
    memset(t56, 0, 8);
    t35 = (t56 + 4);
    t44 = (t43 + 4);
    t59 = *((unsigned int *)t43);
    t60 = (t59 >> 15);
    t61 = (t60 & 1);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t44);
    t63 = (t62 >> 15);
    t65 = (t63 & 1);
    *((unsigned int *)t35) = t65;
    xsi_vlog_mul_concat(t52, 24, 1, t34, 1U, t56, 1);
    xsi_vlogtype_concat(t41, 32, 32, 2U, t52, 24, t42, 8);
    t45 = (t0 + 1928);
    xsi_vlogvar_assign_value(t45, t41, 0, 0, 32);
    goto LAB52;

LAB55:    t16 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB56;

LAB57:    t18 = (t0 + 1208U);
    t20 = *((char **)t18);
    memset(t42, 0, 8);
    t18 = (t42 + 4);
    t21 = (t20 + 4);
    t47 = *((unsigned int *)t20);
    t48 = (t47 >> 16);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t21);
    t50 = (t49 >> 16);
    *((unsigned int *)t18) = t50;
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 255U);
    t58 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t58 & 255U);
    t34 = ((char*)((ng6)));
    t35 = (t0 + 1208U);
    t43 = *((char **)t35);
    memset(t56, 0, 8);
    t35 = (t56 + 4);
    t44 = (t43 + 4);
    t59 = *((unsigned int *)t43);
    t60 = (t59 >> 23);
    t61 = (t60 & 1);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t44);
    t63 = (t62 >> 23);
    t65 = (t63 & 1);
    *((unsigned int *)t35) = t65;
    xsi_vlog_mul_concat(t52, 24, 1, t34, 1U, t56, 1);
    xsi_vlogtype_concat(t41, 32, 32, 2U, t52, 24, t42, 8);
    t45 = (t0 + 1928);
    xsi_vlogvar_assign_value(t45, t41, 0, 0, 32);
    goto LAB59;

LAB63:    t16 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB64;

LAB65:    t18 = (t0 + 1208U);
    t20 = *((char **)t18);
    memset(t42, 0, 8);
    t18 = (t42 + 4);
    t21 = (t20 + 4);
    t47 = *((unsigned int *)t20);
    t48 = (t47 >> 0);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t21);
    t50 = (t49 >> 0);
    *((unsigned int *)t18) = t50;
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 255U);
    t58 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t58 & 255U);
    t34 = ((char*)((ng0)));
    xsi_vlogtype_concat(t41, 32, 32, 2U, t34, 24, t42, 8);
    t35 = (t0 + 1928);
    xsi_vlogvar_assign_value(t35, t41, 0, 0, 32);
    goto LAB67;

LAB70:    t16 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB71;

LAB72:    t18 = (t0 + 1208U);
    t20 = *((char **)t18);
    memset(t42, 0, 8);
    t18 = (t42 + 4);
    t21 = (t20 + 4);
    t47 = *((unsigned int *)t20);
    t48 = (t47 >> 8);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t21);
    t50 = (t49 >> 8);
    *((unsigned int *)t18) = t50;
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 255U);
    t58 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t58 & 255U);
    t34 = ((char*)((ng0)));
    xsi_vlogtype_concat(t41, 32, 32, 2U, t34, 24, t42, 8);
    t35 = (t0 + 1928);
    xsi_vlogvar_assign_value(t35, t41, 0, 0, 32);
    goto LAB74;

LAB77:    t16 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB78;

LAB79:    t18 = (t0 + 1208U);
    t20 = *((char **)t18);
    memset(t42, 0, 8);
    t18 = (t42 + 4);
    t21 = (t20 + 4);
    t47 = *((unsigned int *)t20);
    t48 = (t47 >> 16);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t21);
    t50 = (t49 >> 16);
    *((unsigned int *)t18) = t50;
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 255U);
    t58 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t58 & 255U);
    t34 = ((char*)((ng0)));
    xsi_vlogtype_concat(t41, 32, 32, 2U, t34, 24, t42, 8);
    t35 = (t0 + 1928);
    xsi_vlogvar_assign_value(t35, t41, 0, 0, 32);
    goto LAB81;

}


extern void work_m_00000000003098688854_2509864985_init()
{
	static char *pe[] = {(void *)Always_29_0};
	xsi_register_didat("work_m_00000000003098688854_2509864985", "isim/mips.exe.sim/work/m_00000000003098688854_2509864985.didat");
	xsi_register_executes(pe);
}
