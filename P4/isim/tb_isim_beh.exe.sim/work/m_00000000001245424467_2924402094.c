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
static const char *ng0 = "E:/Desktop/P4/DM.v";
static int ng1[] = {0, 0};
static int ng2[] = {1024, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U};
static unsigned int ng5[] = {1U, 0U};
static int ng6[] = {15, 0};
static int ng7[] = {31, 0};
static int ng8[] = {16, 0};
static int ng9[] = {7, 0};
static int ng10[] = {8, 0};
static unsigned int ng11[] = {2U, 0U};
static int ng12[] = {23, 0};
static int ng13[] = {24, 0};
static const char *ng14 = "@%h: *%h <= %h";



static void Initial_34_0(char *t0)
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

LAB0:    xsi_set_current_line(34, ng0);

LAB2:    xsi_set_current_line(35, ng0);
    xsi_set_current_line(35, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB3:    t1 = (t0 + 2728);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng2)));
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
LAB4:    xsi_set_current_line(35, ng0);

LAB6:    xsi_set_current_line(36, ng0);
    t12 = ((char*)((ng1)));
    t13 = (t0 + 2568);
    t16 = (t0 + 2568);
    t17 = (t16 + 72U);
    t18 = *((char **)t17);
    t19 = (t0 + 2568);
    t20 = (t19 + 64U);
    t21 = *((char **)t20);
    t22 = (t0 + 2728);
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
        goto LAB7;

LAB8:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2728);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng3)));
    memset(t5, 0, 8);
    xsi_vlog_signed_add(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2728);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    goto LAB3;

LAB7:    t32 = *((unsigned int *)t14);
    t33 = *((unsigned int *)t15);
    t34 = (t32 - t33);
    t35 = (t34 + 1);
    xsi_vlogvar_assign_value(t13, t12, 0, *((unsigned int *)t15), t35);
    goto LAB8;

}

static void Always_39_1(char *t0)
{
    char t13[8];
    char t15[8];
    char t16[8];
    char t50[8];
    char t78[8];
    char t79[8];
    char t83[8];
    char t93[8];
    char t94[8];
    char t95[8];
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
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t80;
    char *t81;
    char *t82;
    char *t84;
    char *t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    unsigned int t102;
    char *t103;
    unsigned int t104;
    char *t105;
    unsigned int t106;
    char *t107;
    unsigned int t108;
    int t109;
    int t110;
    char *t111;
    unsigned int t112;
    int t113;
    int t114;
    unsigned int t115;
    int t116;
    unsigned int t117;
    unsigned int t118;
    int t119;
    unsigned int t120;
    unsigned int t121;
    int t122;
    int t123;

LAB0:    t1 = (t0 + 3896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 4464);
    *((int *)t2) = 1;
    t3 = (t0 + 3928);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB16;

LAB17:
LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(40, ng0);

LAB9:    xsi_set_current_line(41, ng0);
    xsi_set_current_line(41, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2728);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);

LAB10:    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    xsi_vlog_signed_less(t13, 32, t4, 32, t5, 32);
    t11 = (t13 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    goto LAB8;

LAB11:    xsi_set_current_line(41, ng0);

LAB13:    xsi_set_current_line(42, ng0);
    t12 = ((char*)((ng1)));
    t14 = (t0 + 2568);
    t17 = (t0 + 2568);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t20 = (t0 + 2568);
    t21 = (t20 + 64U);
    t22 = *((char **)t21);
    t23 = (t0 + 2728);
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
        goto LAB14;

LAB15:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    xsi_vlog_signed_add(t13, 32, t4, 32, t5, 32);
    t11 = (t0 + 2728);
    xsi_vlogvar_assign_value(t11, t13, 0, 0, 32);
    goto LAB10;

LAB14:    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t16);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t14, t12, 0, *((unsigned int *)t16), t36);
    goto LAB15;

LAB16:    xsi_set_current_line(45, ng0);

LAB19:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t13, 0, 8);
    t11 = (t5 + 4);
    t12 = (t4 + 4);
    t27 = *((unsigned int *)t5);
    t30 = *((unsigned int *)t4);
    t33 = (t27 ^ t30);
    t34 = *((unsigned int *)t11);
    t37 = *((unsigned int *)t12);
    t38 = (t34 ^ t37);
    t39 = (t33 | t38);
    t40 = *((unsigned int *)t11);
    t41 = *((unsigned int *)t12);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB23;

LAB20:    if (t42 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t13) = 1;

LAB23:    t17 = (t13 + 4);
    t45 = *((unsigned int *)t17);
    t46 = (~(t45));
    t47 = *((unsigned int *)t13);
    t48 = (t47 & t46);
    t49 = (t48 != 0);
    if (t49 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t13, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t27 = (t9 ^ t10);
    t30 = (t8 | t27);
    t33 = *((unsigned int *)t4);
    t34 = *((unsigned int *)t5);
    t37 = (t33 | t34);
    t38 = (~(t37));
    t39 = (t30 & t38);
    if (t39 != 0)
        goto LAB32;

LAB29:    if (t37 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t13) = 1;

LAB32:    t12 = (t13 + 4);
    t40 = *((unsigned int *)t12);
    t41 = (~(t40));
    t42 = *((unsigned int *)t13);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(51, ng0);

LAB48:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 3U);
    t27 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t27 & 3U);
    t5 = ((char*)((ng4)));
    memset(t15, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t30 = *((unsigned int *)t13);
    t33 = *((unsigned int *)t5);
    t34 = (t30 ^ t33);
    t37 = *((unsigned int *)t11);
    t38 = *((unsigned int *)t12);
    t39 = (t37 ^ t38);
    t40 = (t34 | t39);
    t41 = *((unsigned int *)t11);
    t42 = *((unsigned int *)t12);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB52;

LAB49:    if (t43 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t15) = 1;

LAB52:    t17 = (t15 + 4);
    t46 = *((unsigned int *)t17);
    t47 = (~(t46));
    t48 = *((unsigned int *)t15);
    t49 = (t48 & t47);
    t52 = (t49 != 0);
    if (t52 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 3U);
    t27 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t27 & 3U);
    t5 = ((char*)((ng5)));
    memset(t15, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t30 = *((unsigned int *)t13);
    t33 = *((unsigned int *)t5);
    t34 = (t30 ^ t33);
    t37 = *((unsigned int *)t11);
    t38 = *((unsigned int *)t12);
    t39 = (t37 ^ t38);
    t40 = (t34 | t39);
    t41 = *((unsigned int *)t11);
    t42 = *((unsigned int *)t12);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB61;

LAB58:    if (t43 != 0)
        goto LAB60;

LAB59:    *((unsigned int *)t15) = 1;

LAB61:    t17 = (t15 + 4);
    t46 = *((unsigned int *)t17);
    t47 = (~(t46));
    t48 = *((unsigned int *)t15);
    t49 = (t48 & t47);
    t52 = (t49 != 0);
    if (t52 > 0)
        goto LAB62;

LAB63:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 3U);
    t27 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t27 & 3U);
    t5 = ((char*)((ng11)));
    memset(t15, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t30 = *((unsigned int *)t13);
    t33 = *((unsigned int *)t5);
    t34 = (t30 ^ t33);
    t37 = *((unsigned int *)t11);
    t38 = *((unsigned int *)t12);
    t39 = (t37 ^ t38);
    t40 = (t34 | t39);
    t41 = *((unsigned int *)t11);
    t42 = *((unsigned int *)t12);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB70;

LAB67:    if (t43 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t15) = 1;

LAB70:    t17 = (t15 + 4);
    t46 = *((unsigned int *)t17);
    t47 = (~(t46));
    t48 = *((unsigned int *)t15);
    t49 = (t48 & t47);
    t52 = (t49 != 0);
    if (t52 > 0)
        goto LAB71;

LAB72:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 255U);
    t27 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t27 & 255U);
    t5 = (t0 + 2568);
    t11 = (t0 + 2568);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t17 = (t0 + 2568);
    t18 = (t17 + 64U);
    t19 = *((char **)t18);
    t20 = (t0 + 1688U);
    t21 = *((char **)t20);
    memset(t50, 0, 8);
    t20 = (t50 + 4);
    t22 = (t21 + 4);
    t30 = *((unsigned int *)t21);
    t33 = (t30 >> 2);
    *((unsigned int *)t50) = t33;
    t34 = *((unsigned int *)t22);
    t37 = (t34 >> 2);
    *((unsigned int *)t20) = t37;
    t38 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t38 & 1023U);
    t39 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t39 & 1023U);
    xsi_vlog_generic_convert_array_indices(t15, t16, t14, t19, 2, 1, t50, 10, 2);
    t23 = (t0 + 2568);
    t24 = (t23 + 72U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng7)));
    t29 = ((char*)((ng13)));
    xsi_vlog_convert_partindices(t78, t79, t83, ((int*)(t25)), 2, t26, 32, 1, t29, 32, 1);
    t51 = (t15 + 4);
    t40 = *((unsigned int *)t51);
    t28 = (!(t40));
    t58 = (t16 + 4);
    t41 = *((unsigned int *)t58);
    t31 = (!(t41));
    t32 = (t28 && t31);
    t60 = (t78 + 4);
    t42 = *((unsigned int *)t60);
    t35 = (!(t42));
    t36 = (t32 && t35);
    t80 = (t79 + 4);
    t43 = *((unsigned int *)t80);
    t109 = (!(t43));
    t110 = (t36 && t109);
    t81 = (t83 + 4);
    t44 = *((unsigned int *)t81);
    t113 = (!(t44));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB76;

LAB77:
LAB73:
LAB64:
LAB55:
LAB35:
LAB26:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 1688U);
    t4 = *((char **)t2);
    t2 = (t0 + 1848U);
    t5 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng14, 4, t0, (char)118, t3, 32, (char)118, t4, 32, (char)118, t5, 32);
    goto LAB18;

LAB22:    t14 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB23;

LAB24:    xsi_set_current_line(46, ng0);
    t18 = (t0 + 1848U);
    t19 = *((char **)t18);
    t18 = (t0 + 2568);
    t20 = (t0 + 2568);
    t21 = (t20 + 72U);
    t22 = *((char **)t21);
    t23 = (t0 + 2568);
    t24 = (t23 + 64U);
    t25 = *((char **)t24);
    t26 = (t0 + 1688U);
    t29 = *((char **)t26);
    memset(t50, 0, 8);
    t26 = (t50 + 4);
    t51 = (t29 + 4);
    t52 = *((unsigned int *)t29);
    t53 = (t52 >> 2);
    *((unsigned int *)t50) = t53;
    t54 = *((unsigned int *)t51);
    t55 = (t54 >> 2);
    *((unsigned int *)t26) = t55;
    t56 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t56 & 1023U);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & 1023U);
    xsi_vlog_generic_convert_array_indices(t15, t16, t22, t25, 2, 1, t50, 10, 2);
    t58 = (t15 + 4);
    t59 = *((unsigned int *)t58);
    t28 = (!(t59));
    t60 = (t16 + 4);
    t61 = *((unsigned int *)t60);
    t31 = (!(t61));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB27;

LAB28:    goto LAB26;

LAB27:    t62 = *((unsigned int *)t15);
    t63 = *((unsigned int *)t16);
    t35 = (t62 - t63);
    t36 = (t35 + 1);
    xsi_vlogvar_wait_assign_value(t18, t19, 0, *((unsigned int *)t16), t36, 0LL);
    goto LAB28;

LAB31:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(47, ng0);

LAB36:    xsi_set_current_line(48, ng0);
    t14 = (t0 + 1688U);
    t17 = *((char **)t14);
    memset(t15, 0, 8);
    t14 = (t15 + 4);
    t18 = (t17 + 4);
    t45 = *((unsigned int *)t17);
    t46 = (t45 >> 1);
    t47 = (t46 & 1);
    *((unsigned int *)t15) = t47;
    t48 = *((unsigned int *)t18);
    t49 = (t48 >> 1);
    t52 = (t49 & 1);
    *((unsigned int *)t14) = t52;
    t19 = ((char*)((ng4)));
    memset(t16, 0, 8);
    t20 = (t15 + 4);
    t21 = (t19 + 4);
    t53 = *((unsigned int *)t15);
    t54 = *((unsigned int *)t19);
    t55 = (t53 ^ t54);
    t56 = *((unsigned int *)t20);
    t57 = *((unsigned int *)t21);
    t59 = (t56 ^ t57);
    t61 = (t55 | t59);
    t62 = *((unsigned int *)t20);
    t63 = *((unsigned int *)t21);
    t64 = (t62 | t63);
    t65 = (~(t64));
    t66 = (t61 & t65);
    if (t66 != 0)
        goto LAB40;

LAB37:    if (t64 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t16) = 1;

LAB40:    t23 = (t16 + 4);
    t67 = *((unsigned int *)t23);
    t68 = (~(t67));
    t69 = *((unsigned int *)t16);
    t70 = (t69 & t68);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB41;

LAB42:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 65535U);
    t27 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t27 & 65535U);
    t5 = (t0 + 2568);
    t11 = (t0 + 2568);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t17 = (t0 + 2568);
    t18 = (t17 + 64U);
    t19 = *((char **)t18);
    t20 = (t0 + 1688U);
    t21 = *((char **)t20);
    memset(t50, 0, 8);
    t20 = (t50 + 4);
    t22 = (t21 + 4);
    t30 = *((unsigned int *)t21);
    t33 = (t30 >> 2);
    *((unsigned int *)t50) = t33;
    t34 = *((unsigned int *)t22);
    t37 = (t34 >> 2);
    *((unsigned int *)t20) = t37;
    t38 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t38 & 1023U);
    t39 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t39 & 1023U);
    xsi_vlog_generic_convert_array_indices(t15, t16, t14, t19, 2, 1, t50, 10, 2);
    t23 = (t0 + 2568);
    t24 = (t23 + 72U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng7)));
    t29 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t78, t79, t83, ((int*)(t25)), 2, t26, 32, 1, t29, 32, 1);
    t51 = (t15 + 4);
    t40 = *((unsigned int *)t51);
    t28 = (!(t40));
    t58 = (t16 + 4);
    t41 = *((unsigned int *)t58);
    t31 = (!(t41));
    t32 = (t28 && t31);
    t60 = (t78 + 4);
    t42 = *((unsigned int *)t60);
    t35 = (!(t42));
    t36 = (t32 && t35);
    t80 = (t79 + 4);
    t43 = *((unsigned int *)t80);
    t109 = (!(t43));
    t110 = (t36 && t109);
    t81 = (t83 + 4);
    t44 = *((unsigned int *)t81);
    t113 = (!(t44));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB46;

LAB47:
LAB43:    goto LAB35;

LAB39:    t22 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(48, ng0);
    t24 = (t0 + 1848U);
    t25 = *((char **)t24);
    memset(t50, 0, 8);
    t24 = (t50 + 4);
    t26 = (t25 + 4);
    t72 = *((unsigned int *)t25);
    t73 = (t72 >> 0);
    *((unsigned int *)t50) = t73;
    t74 = *((unsigned int *)t26);
    t75 = (t74 >> 0);
    *((unsigned int *)t24) = t75;
    t76 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t76 & 65535U);
    t77 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t77 & 65535U);
    t29 = (t0 + 2568);
    t51 = (t0 + 2568);
    t58 = (t51 + 72U);
    t60 = *((char **)t58);
    t80 = (t0 + 2568);
    t81 = (t80 + 64U);
    t82 = *((char **)t81);
    t84 = (t0 + 1688U);
    t85 = *((char **)t84);
    memset(t83, 0, 8);
    t84 = (t83 + 4);
    t86 = (t85 + 4);
    t87 = *((unsigned int *)t85);
    t88 = (t87 >> 2);
    *((unsigned int *)t83) = t88;
    t89 = *((unsigned int *)t86);
    t90 = (t89 >> 2);
    *((unsigned int *)t84) = t90;
    t91 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t91 & 1023U);
    t92 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t92 & 1023U);
    xsi_vlog_generic_convert_array_indices(t78, t79, t60, t82, 2, 1, t83, 10, 2);
    t96 = (t0 + 2568);
    t97 = (t96 + 72U);
    t98 = *((char **)t97);
    t99 = ((char*)((ng6)));
    t100 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t93, t94, t95, ((int*)(t98)), 2, t99, 32, 1, t100, 32, 1);
    t101 = (t78 + 4);
    t102 = *((unsigned int *)t101);
    t28 = (!(t102));
    t103 = (t79 + 4);
    t104 = *((unsigned int *)t103);
    t31 = (!(t104));
    t32 = (t28 && t31);
    t105 = (t93 + 4);
    t106 = *((unsigned int *)t105);
    t35 = (!(t106));
    t36 = (t32 && t35);
    t107 = (t94 + 4);
    t108 = *((unsigned int *)t107);
    t109 = (!(t108));
    t110 = (t36 && t109);
    t111 = (t95 + 4);
    t112 = *((unsigned int *)t111);
    t113 = (!(t112));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB44;

LAB45:    goto LAB43;

LAB44:    t115 = *((unsigned int *)t95);
    t116 = (t115 + 0);
    t117 = *((unsigned int *)t79);
    t118 = *((unsigned int *)t94);
    t119 = (t117 + t118);
    t120 = *((unsigned int *)t93);
    t121 = *((unsigned int *)t94);
    t122 = (t120 - t121);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t29, t50, t116, t119, t123, 0LL);
    goto LAB45;

LAB46:    t45 = *((unsigned int *)t83);
    t116 = (t45 + 0);
    t46 = *((unsigned int *)t16);
    t47 = *((unsigned int *)t79);
    t119 = (t46 + t47);
    t48 = *((unsigned int *)t78);
    t49 = *((unsigned int *)t79);
    t122 = (t48 - t49);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t5, t13, t116, t119, t123, 0LL);
    goto LAB47;

LAB51:    t14 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(52, ng0);
    t18 = (t0 + 1848U);
    t19 = *((char **)t18);
    memset(t16, 0, 8);
    t18 = (t16 + 4);
    t20 = (t19 + 4);
    t53 = *((unsigned int *)t19);
    t54 = (t53 >> 0);
    *((unsigned int *)t16) = t54;
    t55 = *((unsigned int *)t20);
    t56 = (t55 >> 0);
    *((unsigned int *)t18) = t56;
    t57 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t57 & 255U);
    t59 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t59 & 255U);
    t21 = (t0 + 2568);
    t22 = (t0 + 2568);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = (t0 + 2568);
    t26 = (t25 + 64U);
    t29 = *((char **)t26);
    t51 = (t0 + 1688U);
    t58 = *((char **)t51);
    memset(t79, 0, 8);
    t51 = (t79 + 4);
    t60 = (t58 + 4);
    t61 = *((unsigned int *)t58);
    t62 = (t61 >> 2);
    *((unsigned int *)t79) = t62;
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 2);
    *((unsigned int *)t51) = t64;
    t65 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t65 & 1023U);
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t78, t24, t29, 2, 1, t79, 10, 2);
    t80 = (t0 + 2568);
    t81 = (t80 + 72U);
    t82 = *((char **)t81);
    t84 = ((char*)((ng9)));
    t85 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t83, t93, t94, ((int*)(t82)), 2, t84, 32, 1, t85, 32, 1);
    t86 = (t50 + 4);
    t67 = *((unsigned int *)t86);
    t28 = (!(t67));
    t96 = (t78 + 4);
    t68 = *((unsigned int *)t96);
    t31 = (!(t68));
    t32 = (t28 && t31);
    t97 = (t83 + 4);
    t69 = *((unsigned int *)t97);
    t35 = (!(t69));
    t36 = (t32 && t35);
    t98 = (t93 + 4);
    t70 = *((unsigned int *)t98);
    t109 = (!(t70));
    t110 = (t36 && t109);
    t99 = (t94 + 4);
    t71 = *((unsigned int *)t99);
    t113 = (!(t71));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB56;

LAB57:    goto LAB55;

LAB56:    t72 = *((unsigned int *)t94);
    t116 = (t72 + 0);
    t73 = *((unsigned int *)t78);
    t74 = *((unsigned int *)t93);
    t119 = (t73 + t74);
    t75 = *((unsigned int *)t83);
    t76 = *((unsigned int *)t93);
    t122 = (t75 - t76);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t21, t16, t116, t119, t123, 0LL);
    goto LAB57;

LAB60:    t14 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB61;

LAB62:    xsi_set_current_line(53, ng0);
    t18 = (t0 + 1848U);
    t19 = *((char **)t18);
    memset(t16, 0, 8);
    t18 = (t16 + 4);
    t20 = (t19 + 4);
    t53 = *((unsigned int *)t19);
    t54 = (t53 >> 0);
    *((unsigned int *)t16) = t54;
    t55 = *((unsigned int *)t20);
    t56 = (t55 >> 0);
    *((unsigned int *)t18) = t56;
    t57 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t57 & 255U);
    t59 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t59 & 255U);
    t21 = (t0 + 2568);
    t22 = (t0 + 2568);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = (t0 + 2568);
    t26 = (t25 + 64U);
    t29 = *((char **)t26);
    t51 = (t0 + 1688U);
    t58 = *((char **)t51);
    memset(t79, 0, 8);
    t51 = (t79 + 4);
    t60 = (t58 + 4);
    t61 = *((unsigned int *)t58);
    t62 = (t61 >> 2);
    *((unsigned int *)t79) = t62;
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 2);
    *((unsigned int *)t51) = t64;
    t65 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t65 & 1023U);
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t78, t24, t29, 2, 1, t79, 10, 2);
    t80 = (t0 + 2568);
    t81 = (t80 + 72U);
    t82 = *((char **)t81);
    t84 = ((char*)((ng6)));
    t85 = ((char*)((ng10)));
    xsi_vlog_convert_partindices(t83, t93, t94, ((int*)(t82)), 2, t84, 32, 1, t85, 32, 1);
    t86 = (t50 + 4);
    t67 = *((unsigned int *)t86);
    t28 = (!(t67));
    t96 = (t78 + 4);
    t68 = *((unsigned int *)t96);
    t31 = (!(t68));
    t32 = (t28 && t31);
    t97 = (t83 + 4);
    t69 = *((unsigned int *)t97);
    t35 = (!(t69));
    t36 = (t32 && t35);
    t98 = (t93 + 4);
    t70 = *((unsigned int *)t98);
    t109 = (!(t70));
    t110 = (t36 && t109);
    t99 = (t94 + 4);
    t71 = *((unsigned int *)t99);
    t113 = (!(t71));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB65;

LAB66:    goto LAB64;

LAB65:    t72 = *((unsigned int *)t94);
    t116 = (t72 + 0);
    t73 = *((unsigned int *)t78);
    t74 = *((unsigned int *)t93);
    t119 = (t73 + t74);
    t75 = *((unsigned int *)t83);
    t76 = *((unsigned int *)t93);
    t122 = (t75 - t76);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t21, t16, t116, t119, t123, 0LL);
    goto LAB66;

LAB69:    t14 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB70;

LAB71:    xsi_set_current_line(54, ng0);
    t18 = (t0 + 1848U);
    t19 = *((char **)t18);
    memset(t16, 0, 8);
    t18 = (t16 + 4);
    t20 = (t19 + 4);
    t53 = *((unsigned int *)t19);
    t54 = (t53 >> 0);
    *((unsigned int *)t16) = t54;
    t55 = *((unsigned int *)t20);
    t56 = (t55 >> 0);
    *((unsigned int *)t18) = t56;
    t57 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t57 & 255U);
    t59 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t59 & 255U);
    t21 = (t0 + 2568);
    t22 = (t0 + 2568);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = (t0 + 2568);
    t26 = (t25 + 64U);
    t29 = *((char **)t26);
    t51 = (t0 + 1688U);
    t58 = *((char **)t51);
    memset(t79, 0, 8);
    t51 = (t79 + 4);
    t60 = (t58 + 4);
    t61 = *((unsigned int *)t58);
    t62 = (t61 >> 2);
    *((unsigned int *)t79) = t62;
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 2);
    *((unsigned int *)t51) = t64;
    t65 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t65 & 1023U);
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t78, t24, t29, 2, 1, t79, 10, 2);
    t80 = (t0 + 2568);
    t81 = (t80 + 72U);
    t82 = *((char **)t81);
    t84 = ((char*)((ng12)));
    t85 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t83, t93, t94, ((int*)(t82)), 2, t84, 32, 1, t85, 32, 1);
    t86 = (t50 + 4);
    t67 = *((unsigned int *)t86);
    t28 = (!(t67));
    t96 = (t78 + 4);
    t68 = *((unsigned int *)t96);
    t31 = (!(t68));
    t32 = (t28 && t31);
    t97 = (t83 + 4);
    t69 = *((unsigned int *)t97);
    t35 = (!(t69));
    t36 = (t32 && t35);
    t98 = (t93 + 4);
    t70 = *((unsigned int *)t98);
    t109 = (!(t70));
    t110 = (t36 && t109);
    t99 = (t94 + 4);
    t71 = *((unsigned int *)t99);
    t113 = (!(t71));
    t114 = (t110 && t113);
    if (t114 == 1)
        goto LAB74;

LAB75:    goto LAB73;

LAB74:    t72 = *((unsigned int *)t94);
    t116 = (t72 + 0);
    t73 = *((unsigned int *)t78);
    t74 = *((unsigned int *)t93);
    t119 = (t73 + t74);
    t75 = *((unsigned int *)t83);
    t76 = *((unsigned int *)t93);
    t122 = (t75 - t76);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t21, t16, t116, t119, t123, 0LL);
    goto LAB75;

LAB76:    t45 = *((unsigned int *)t83);
    t116 = (t45 + 0);
    t46 = *((unsigned int *)t16);
    t47 = *((unsigned int *)t79);
    t119 = (t46 + t47);
    t48 = *((unsigned int *)t78);
    t49 = *((unsigned int *)t79);
    t122 = (t48 - t49);
    t123 = (t122 + 1);
    xsi_vlogvar_wait_assign_value(t5, t13, t116, t119, t123, 0LL);
    goto LAB77;

}

static void Always_61_2(char *t0)
{
    char t6[8];
    char t31[8];
    char t38[8];
    char t66[8];
    char t69[8];
    char t79[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
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
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t67;
    char *t68;
    char *t70;
    char *t71;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;

LAB0:    t1 = (t0 + 4144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 4480);
    *((int *)t2) = 1;
    t3 = (t0 + 4176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);

LAB5:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB16;

LAB13:    if (t18 != 0)
        goto LAB15;

LAB14:    *((unsigned int *)t6) = 1;

LAB16:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(67, ng0);

LAB28:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 3U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 3U);
    t5 = ((char*)((ng4)));
    memset(t31, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t5);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t8);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t42 = (t23 & t27);
    if (t42 != 0)
        goto LAB32;

LAB29:    if (t26 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t31) = 1;

LAB32:    t22 = (t31 + 4);
    t43 = *((unsigned int *)t22);
    t44 = (~(t43));
    t45 = *((unsigned int *)t31);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 3U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 3U);
    t5 = ((char*)((ng5)));
    memset(t31, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t5);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t8);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t42 = (t23 & t27);
    if (t42 != 0)
        goto LAB39;

LAB36:    if (t26 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t31) = 1;

LAB39:    t22 = (t31 + 4);
    t43 = *((unsigned int *)t22);
    t44 = (~(t43));
    t45 = *((unsigned int *)t31);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 3U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 3U);
    t5 = ((char*)((ng11)));
    memset(t31, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t5);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t8);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t42 = (t23 & t27);
    if (t42 != 0)
        goto LAB46;

LAB43:    if (t26 != 0)
        goto LAB45;

LAB44:    *((unsigned int *)t31) = 1;

LAB46:    t22 = (t31 + 4);
    t43 = *((unsigned int *)t22);
    t44 = (~(t43));
    t45 = *((unsigned int *)t31);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2568);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t21 = (t0 + 2568);
    t22 = (t21 + 64U);
    t28 = *((char **)t22);
    t29 = (t0 + 1688U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    t29 = (t31 + 4);
    t32 = (t30 + 4);
    t9 = *((unsigned int *)t30);
    t10 = (t9 >> 2);
    *((unsigned int *)t31) = t10;
    t11 = *((unsigned int *)t32);
    t12 = (t11 >> 2);
    *((unsigned int *)t29) = t12;
    t13 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t13 & 1023U);
    t14 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t14 & 1023U);
    xsi_vlog_generic_get_array_select_value(t6, 32, t4, t8, t28, 2, 1, t31, 10, 2);
    memset(t38, 0, 8);
    t33 = (t38 + 4);
    t34 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 24);
    *((unsigned int *)t38) = t16;
    t17 = *((unsigned int *)t34);
    t18 = (t17 >> 24);
    *((unsigned int *)t33) = t18;
    t19 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t19 & 255U);
    t20 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t20 & 255U);
    t35 = (t0 + 1848U);
    t36 = *((char **)t35);
    memset(t66, 0, 8);
    t35 = (t66 + 4);
    t37 = (t36 + 4);
    t23 = *((unsigned int *)t36);
    t24 = (t23 >> 0);
    *((unsigned int *)t66) = t24;
    t25 = *((unsigned int *)t37);
    t26 = (t25 >> 0);
    *((unsigned int *)t35) = t26;
    t27 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t27 & 255U);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 & 255U);
    memset(t69, 0, 8);
    t39 = (t38 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB51;

LAB50:    t40 = (t66 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB51;

LAB54:    if (*((unsigned int *)t38) > *((unsigned int *)t66))
        goto LAB53;

LAB52:    *((unsigned int *)t69) = 1;

LAB53:    t48 = (t0 + 2408);
    xsi_vlogvar_assign_value(t48, t69, 0, 0, 32);

LAB49:
LAB42:
LAB35:
LAB19:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(62, ng0);
    t28 = (t0 + 2568);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t32 = (t0 + 2568);
    t33 = (t32 + 72U);
    t34 = *((char **)t33);
    t35 = (t0 + 2568);
    t36 = (t35 + 64U);
    t37 = *((char **)t36);
    t39 = (t0 + 1688U);
    t40 = *((char **)t39);
    memset(t38, 0, 8);
    t39 = (t38 + 4);
    t41 = (t40 + 4);
    t42 = *((unsigned int *)t40);
    t43 = (t42 >> 2);
    *((unsigned int *)t38) = t43;
    t44 = *((unsigned int *)t41);
    t45 = (t44 >> 2);
    *((unsigned int *)t39) = t45;
    t46 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t46 & 1023U);
    t47 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t47 & 1023U);
    xsi_vlog_generic_get_array_select_value(t31, 32, t30, t34, t37, 2, 1, t38, 10, 2);
    t48 = (t0 + 2408);
    xsi_vlogvar_assign_value(t48, t31, 0, 0, 32);
    goto LAB12;

LAB15:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB16;

LAB17:    xsi_set_current_line(63, ng0);

LAB20:    xsi_set_current_line(64, ng0);
    t21 = (t0 + 1688U);
    t22 = *((char **)t21);
    memset(t31, 0, 8);
    t21 = (t31 + 4);
    t28 = (t22 + 4);
    t42 = *((unsigned int *)t22);
    t43 = (t42 >> 1);
    t44 = (t43 & 1);
    *((unsigned int *)t31) = t44;
    t45 = *((unsigned int *)t28);
    t46 = (t45 >> 1);
    t47 = (t46 & 1);
    *((unsigned int *)t21) = t47;
    t29 = ((char*)((ng4)));
    memset(t38, 0, 8);
    t30 = (t31 + 4);
    t32 = (t29 + 4);
    t49 = *((unsigned int *)t31);
    t50 = *((unsigned int *)t29);
    t51 = (t49 ^ t50);
    t52 = *((unsigned int *)t30);
    t53 = *((unsigned int *)t32);
    t54 = (t52 ^ t53);
    t55 = (t51 | t54);
    t56 = *((unsigned int *)t30);
    t57 = *((unsigned int *)t32);
    t58 = (t56 | t57);
    t59 = (~(t58));
    t60 = (t55 & t59);
    if (t60 != 0)
        goto LAB24;

LAB21:    if (t58 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t38) = 1;

LAB24:    t34 = (t38 + 4);
    t61 = *((unsigned int *)t34);
    t62 = (~(t61));
    t63 = *((unsigned int *)t38);
    t64 = (t63 & t62);
    t65 = (t64 != 0);
    if (t65 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2568);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t21 = (t0 + 2568);
    t22 = (t21 + 64U);
    t28 = *((char **)t22);
    t29 = (t0 + 1688U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    t29 = (t31 + 4);
    t32 = (t30 + 4);
    t9 = *((unsigned int *)t30);
    t10 = (t9 >> 2);
    *((unsigned int *)t31) = t10;
    t11 = *((unsigned int *)t32);
    t12 = (t11 >> 2);
    *((unsigned int *)t29) = t12;
    t13 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t13 & 1023U);
    t14 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t14 & 1023U);
    xsi_vlog_generic_get_array_select_value(t6, 32, t4, t8, t28, 2, 1, t31, 10, 2);
    memset(t38, 0, 8);
    t33 = (t38 + 4);
    t34 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 16);
    *((unsigned int *)t38) = t16;
    t17 = *((unsigned int *)t34);
    t18 = (t17 >> 16);
    *((unsigned int *)t33) = t18;
    t19 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t19 & 65535U);
    t20 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t20 & 65535U);
    t35 = (t0 + 2408);
    xsi_vlogvar_assign_value(t35, t38, 0, 0, 32);

LAB27:    goto LAB19;

LAB23:    t33 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB24;

LAB25:    xsi_set_current_line(64, ng0);
    t35 = (t0 + 2568);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t39 = (t0 + 2568);
    t40 = (t39 + 72U);
    t41 = *((char **)t40);
    t48 = (t0 + 2568);
    t67 = (t48 + 64U);
    t68 = *((char **)t67);
    t70 = (t0 + 1688U);
    t71 = *((char **)t70);
    memset(t69, 0, 8);
    t70 = (t69 + 4);
    t72 = (t71 + 4);
    t73 = *((unsigned int *)t71);
    t74 = (t73 >> 2);
    *((unsigned int *)t69) = t74;
    t75 = *((unsigned int *)t72);
    t76 = (t75 >> 2);
    *((unsigned int *)t70) = t76;
    t77 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t77 & 1023U);
    t78 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t78 & 1023U);
    xsi_vlog_generic_get_array_select_value(t66, 32, t37, t41, t68, 2, 1, t69, 10, 2);
    memset(t79, 0, 8);
    t80 = (t79 + 4);
    t81 = (t66 + 4);
    t82 = *((unsigned int *)t66);
    t83 = (t82 >> 0);
    *((unsigned int *)t79) = t83;
    t84 = *((unsigned int *)t81);
    t85 = (t84 >> 0);
    *((unsigned int *)t80) = t85;
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t86 & 65535U);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 & 65535U);
    t88 = (t0 + 2408);
    xsi_vlogvar_assign_value(t88, t79, 0, 0, 32);
    goto LAB27;

LAB31:    t21 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(68, ng0);
    t28 = (t0 + 2568);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t32 = (t0 + 2568);
    t33 = (t32 + 72U);
    t34 = *((char **)t33);
    t35 = (t0 + 2568);
    t36 = (t35 + 64U);
    t37 = *((char **)t36);
    t39 = (t0 + 1688U);
    t40 = *((char **)t39);
    memset(t66, 0, 8);
    t39 = (t66 + 4);
    t41 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = (t49 >> 2);
    *((unsigned int *)t66) = t50;
    t51 = *((unsigned int *)t41);
    t52 = (t51 >> 2);
    *((unsigned int *)t39) = t52;
    t53 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t53 & 1023U);
    t54 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t54 & 1023U);
    xsi_vlog_generic_get_array_select_value(t38, 32, t30, t34, t37, 2, 1, t66, 10, 2);
    memset(t69, 0, 8);
    t48 = (t69 + 4);
    t67 = (t38 + 4);
    t55 = *((unsigned int *)t38);
    t56 = (t55 >> 0);
    *((unsigned int *)t69) = t56;
    t57 = *((unsigned int *)t67);
    t58 = (t57 >> 0);
    *((unsigned int *)t48) = t58;
    t59 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t59 & 255U);
    t60 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t60 & 255U);
    t68 = (t0 + 2408);
    xsi_vlogvar_assign_value(t68, t69, 0, 0, 32);
    goto LAB35;

LAB38:    t21 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB39;

LAB40:    xsi_set_current_line(69, ng0);
    t28 = (t0 + 2568);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t32 = (t0 + 2568);
    t33 = (t32 + 72U);
    t34 = *((char **)t33);
    t35 = (t0 + 2568);
    t36 = (t35 + 64U);
    t37 = *((char **)t36);
    t39 = (t0 + 1688U);
    t40 = *((char **)t39);
    memset(t66, 0, 8);
    t39 = (t66 + 4);
    t41 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = (t49 >> 2);
    *((unsigned int *)t66) = t50;
    t51 = *((unsigned int *)t41);
    t52 = (t51 >> 2);
    *((unsigned int *)t39) = t52;
    t53 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t53 & 1023U);
    t54 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t54 & 1023U);
    xsi_vlog_generic_get_array_select_value(t38, 32, t30, t34, t37, 2, 1, t66, 10, 2);
    memset(t69, 0, 8);
    t48 = (t69 + 4);
    t67 = (t38 + 4);
    t55 = *((unsigned int *)t38);
    t56 = (t55 >> 8);
    *((unsigned int *)t69) = t56;
    t57 = *((unsigned int *)t67);
    t58 = (t57 >> 8);
    *((unsigned int *)t48) = t58;
    t59 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t59 & 255U);
    t60 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t60 & 255U);
    t68 = (t0 + 2408);
    xsi_vlogvar_assign_value(t68, t69, 0, 0, 32);
    goto LAB42;

LAB45:    t21 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB46;

LAB47:    xsi_set_current_line(70, ng0);
    t28 = (t0 + 2568);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t32 = (t0 + 2568);
    t33 = (t32 + 72U);
    t34 = *((char **)t33);
    t35 = (t0 + 2568);
    t36 = (t35 + 64U);
    t37 = *((char **)t36);
    t39 = (t0 + 1688U);
    t40 = *((char **)t39);
    memset(t66, 0, 8);
    t39 = (t66 + 4);
    t41 = (t40 + 4);
    t49 = *((unsigned int *)t40);
    t50 = (t49 >> 2);
    *((unsigned int *)t66) = t50;
    t51 = *((unsigned int *)t41);
    t52 = (t51 >> 2);
    *((unsigned int *)t39) = t52;
    t53 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t53 & 1023U);
    t54 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t54 & 1023U);
    xsi_vlog_generic_get_array_select_value(t38, 32, t30, t34, t37, 2, 1, t66, 10, 2);
    memset(t69, 0, 8);
    t48 = (t69 + 4);
    t67 = (t38 + 4);
    t55 = *((unsigned int *)t38);
    t56 = (t55 >> 16);
    *((unsigned int *)t69) = t56;
    t57 = *((unsigned int *)t67);
    t58 = (t57 >> 16);
    *((unsigned int *)t48) = t58;
    t59 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t59 & 255U);
    t60 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t60 & 255U);
    t68 = (t0 + 2408);
    xsi_vlogvar_assign_value(t68, t69, 0, 0, 32);
    goto LAB49;

LAB51:    t41 = (t69 + 4);
    *((unsigned int *)t69) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB53;

}


extern void work_m_00000000001245424467_2924402094_init()
{
	static char *pe[] = {(void *)Initial_34_0,(void *)Always_39_1,(void *)Always_61_2};
	xsi_register_didat("work_m_00000000001245424467_2924402094", "isim/tb_isim_beh.exe.sim/work/m_00000000001245424467_2924402094.didat");
	xsi_register_executes(pe);
}
