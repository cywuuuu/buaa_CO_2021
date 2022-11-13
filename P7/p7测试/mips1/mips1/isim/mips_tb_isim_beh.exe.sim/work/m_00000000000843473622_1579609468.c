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
static const char *ng0 = "C:/Users/86135/Desktop/test_demo/test_p7/test_cmp1.3/mips1/src/D_CMP.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {5U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {1U, 0U};
static unsigned int ng8[] = {2U, 0U};
static unsigned int ng9[] = {6U, 0U};
static unsigned int ng10[] = {7U, 0U};



static void Always_11_0(char *t0)
{
    char t7[8];
    char t8[8];
    char t12[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t63[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    int t87;
    int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(11, ng0);
    t2 = (t0 + 3008);
    *((int *)t2) = 1;
    t3 = (t0 + 2720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(11, ng0);

LAB5:    xsi_set_current_line(12, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t4, 5);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB21;

LAB22:
LAB24:
LAB23:    xsi_set_current_line(21, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB25:    goto LAB2;

LAB7:    xsi_set_current_line(13, ng0);
    t9 = (t0 + 1048U);
    t10 = *((char **)t9);
    t9 = (t0 + 1208U);
    t11 = *((char **)t9);
    memset(t12, 0, 8);
    t9 = (t10 + 4);
    t13 = (t11 + 4);
    t14 = *((unsigned int *)t10);
    t15 = *((unsigned int *)t11);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t9);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t9);
    t22 = *((unsigned int *)t13);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB29;

LAB26:    if (t23 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t12) = 1;

LAB29:    memset(t8, 0, 8);
    t27 = (t12 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t27) != 0)
        goto LAB32;

LAB33:    t34 = (t8 + 4);
    t35 = *((unsigned int *)t8);
    t36 = *((unsigned int *)t34);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB34;

LAB35:    t39 = *((unsigned int *)t8);
    t40 = (~(t39));
    t41 = *((unsigned int *)t34);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t34) > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t8) > 0)
        goto LAB40;

LAB41:    memcpy(t7, t43, 8);

LAB42:    t44 = (t0 + 1768);
    xsi_vlogvar_assign_value(t44, t7, 0, 0, 1);
    goto LAB25;

LAB9:    xsi_set_current_line(14, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    t3 = (t0 + 1208U);
    t9 = *((char **)t3);
    memset(t12, 0, 8);
    t3 = (t4 + 4);
    t10 = (t9 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t9);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t10);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t3);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB44;

LAB43:    if (t23 != 0)
        goto LAB45;

LAB46:    memset(t8, 0, 8);
    t13 = (t12 + 4);
    t28 = *((unsigned int *)t13);
    t29 = (~(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t13) != 0)
        goto LAB49;

LAB50:    t27 = (t8 + 4);
    t35 = *((unsigned int *)t8);
    t36 = *((unsigned int *)t27);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB51;

LAB52:    t39 = *((unsigned int *)t8);
    t40 = (~(t39));
    t41 = *((unsigned int *)t27);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t27) > 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t8) > 0)
        goto LAB57;

LAB58:    memcpy(t7, t34, 8);

LAB59:    t38 = (t0 + 1768);
    xsi_vlogvar_assign_value(t38, t7, 0, 0, 1);
    goto LAB25;

LAB11:    xsi_set_current_line(15, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t45, 0, 8);
    t3 = (t45 + 4);
    t9 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t45) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t3) = t19;
    memset(t12, 0, 8);
    t10 = (t45 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t45);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB63;

LAB61:    if (*((unsigned int *)t10) == 0)
        goto LAB60;

LAB62:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;

LAB63:    memset(t46, 0, 8);
    t13 = (t12 + 4);
    t25 = *((unsigned int *)t13);
    t28 = (~(t25));
    t29 = *((unsigned int *)t12);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB64;

LAB65:    if (*((unsigned int *)t13) != 0)
        goto LAB66;

LAB67:    t27 = (t46 + 4);
    t32 = *((unsigned int *)t46);
    t35 = *((unsigned int *)t27);
    t36 = (t32 || t35);
    if (t36 > 0)
        goto LAB68;

LAB69:    memcpy(t63, t46, 8);

LAB70:    memset(t8, 0, 8);
    t95 = (t63 + 4);
    t96 = *((unsigned int *)t95);
    t97 = (~(t96));
    t98 = *((unsigned int *)t63);
    t99 = (t98 & t97);
    t100 = (t99 & 1U);
    if (t100 != 0)
        goto LAB82;

LAB83:    if (*((unsigned int *)t95) != 0)
        goto LAB84;

LAB85:    t102 = (t8 + 4);
    t103 = *((unsigned int *)t8);
    t104 = *((unsigned int *)t102);
    t105 = (t103 || t104);
    if (t105 > 0)
        goto LAB86;

LAB87:    t107 = *((unsigned int *)t8);
    t108 = (~(t107));
    t109 = *((unsigned int *)t102);
    t110 = (t108 || t109);
    if (t110 > 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t102) > 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t8) > 0)
        goto LAB92;

LAB93:    memcpy(t7, t111, 8);

LAB94:    t112 = (t0 + 1768);
    xsi_vlogvar_assign_value(t112, t7, 0, 0, 1);
    goto LAB25;

LAB13:    xsi_set_current_line(16, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t45, 0, 8);
    t3 = (t45 + 4);
    t9 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t45) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t3) = t19;
    memset(t12, 0, 8);
    t10 = (t45 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t45);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB98;

LAB96:    if (*((unsigned int *)t10) == 0)
        goto LAB95;

LAB97:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;

LAB98:    memset(t8, 0, 8);
    t13 = (t12 + 4);
    t25 = *((unsigned int *)t13);
    t28 = (~(t25));
    t29 = *((unsigned int *)t12);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t13) != 0)
        goto LAB101;

LAB102:    t27 = (t8 + 4);
    t32 = *((unsigned int *)t8);
    t35 = *((unsigned int *)t27);
    t36 = (t32 || t35);
    if (t36 > 0)
        goto LAB103;

LAB104:    t37 = *((unsigned int *)t8);
    t39 = (~(t37));
    t40 = *((unsigned int *)t27);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB105;

LAB106:    if (*((unsigned int *)t27) > 0)
        goto LAB107;

LAB108:    if (*((unsigned int *)t8) > 0)
        goto LAB109;

LAB110:    memcpy(t7, t34, 8);

LAB111:    t38 = (t0 + 1768);
    xsi_vlogvar_assign_value(t38, t7, 0, 0, 1);
    goto LAB25;

LAB15:    xsi_set_current_line(17, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t12, 0, 8);
    t3 = (t12 + 4);
    t9 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t12) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t3) = t19;
    memset(t45, 0, 8);
    t10 = (t12 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB112;

LAB113:    if (*((unsigned int *)t10) != 0)
        goto LAB114;

LAB115:    t13 = (t45 + 4);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t13);
    t29 = (t25 || t28);
    if (t29 > 0)
        goto LAB116;

LAB117:    memcpy(t55, t45, 8);

LAB118:    memset(t8, 0, 8);
    t77 = (t55 + 4);
    t90 = *((unsigned int *)t77);
    t91 = (~(t90));
    t92 = *((unsigned int *)t55);
    t93 = (t92 & t91);
    t94 = (t93 & 1U);
    if (t94 != 0)
        goto LAB130;

LAB131:    if (*((unsigned int *)t77) != 0)
        goto LAB132;

LAB133:    t95 = (t8 + 4);
    t96 = *((unsigned int *)t8);
    t97 = *((unsigned int *)t95);
    t98 = (t96 || t97);
    if (t98 > 0)
        goto LAB134;

LAB135:    t99 = *((unsigned int *)t8);
    t100 = (~(t99));
    t103 = *((unsigned int *)t95);
    t104 = (t100 || t103);
    if (t104 > 0)
        goto LAB136;

LAB137:    if (*((unsigned int *)t95) > 0)
        goto LAB138;

LAB139:    if (*((unsigned int *)t8) > 0)
        goto LAB140;

LAB141:    memcpy(t7, t102, 8);

LAB142:    t106 = (t0 + 1768);
    xsi_vlogvar_assign_value(t106, t7, 0, 0, 1);
    goto LAB25;

LAB17:    xsi_set_current_line(18, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t12, 0, 8);
    t3 = (t12 + 4);
    t9 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t12) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t3) = t19;
    memset(t45, 0, 8);
    t10 = (t12 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB143;

LAB144:    if (*((unsigned int *)t10) != 0)
        goto LAB145;

LAB146:    t13 = (t45 + 4);
    t25 = *((unsigned int *)t45);
    t28 = (!(t25));
    t29 = *((unsigned int *)t13);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB147;

LAB148:    memcpy(t55, t45, 8);

LAB149:    memset(t8, 0, 8);
    t77 = (t55 + 4);
    t85 = *((unsigned int *)t77);
    t86 = (~(t85));
    t89 = *((unsigned int *)t55);
    t90 = (t89 & t86);
    t91 = (t90 & 1U);
    if (t91 != 0)
        goto LAB161;

LAB162:    if (*((unsigned int *)t77) != 0)
        goto LAB163;

LAB164:    t95 = (t8 + 4);
    t92 = *((unsigned int *)t8);
    t93 = *((unsigned int *)t95);
    t94 = (t92 || t93);
    if (t94 > 0)
        goto LAB165;

LAB166:    t96 = *((unsigned int *)t8);
    t97 = (~(t96));
    t98 = *((unsigned int *)t95);
    t99 = (t97 || t98);
    if (t99 > 0)
        goto LAB167;

LAB168:    if (*((unsigned int *)t95) > 0)
        goto LAB169;

LAB170:    if (*((unsigned int *)t8) > 0)
        goto LAB171;

LAB172:    memcpy(t7, t102, 8);

LAB173:    t106 = (t0 + 1768);
    xsi_vlogvar_assign_value(t106, t7, 0, 0, 1);
    goto LAB25;

LAB19:    xsi_set_current_line(19, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t12, 0, 8);
    t9 = (t4 + 4);
    t10 = (t3 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t3);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t9);
    t18 = *((unsigned int *)t10);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t9);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB177;

LAB174:    if (t23 != 0)
        goto LAB176;

LAB175:    *((unsigned int *)t12) = 1;

LAB177:    memset(t8, 0, 8);
    t13 = (t12 + 4);
    t28 = *((unsigned int *)t13);
    t29 = (~(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB178;

LAB179:    if (*((unsigned int *)t13) != 0)
        goto LAB180;

LAB181:    t27 = (t8 + 4);
    t35 = *((unsigned int *)t8);
    t36 = *((unsigned int *)t27);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB182;

LAB183:    t39 = *((unsigned int *)t8);
    t40 = (~(t39));
    t41 = *((unsigned int *)t27);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB184;

LAB185:    if (*((unsigned int *)t27) > 0)
        goto LAB186;

LAB187:    if (*((unsigned int *)t8) > 0)
        goto LAB188;

LAB189:    memcpy(t7, t34, 8);

LAB190:    t38 = (t0 + 1768);
    xsi_vlogvar_assign_value(t38, t7, 0, 0, 1);
    goto LAB25;

LAB21:    xsi_set_current_line(20, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t12, 0, 8);
    t9 = (t4 + 4);
    t10 = (t3 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t3);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t9);
    t18 = *((unsigned int *)t10);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t9);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB192;

LAB191:    if (t23 != 0)
        goto LAB193;

LAB194:    memset(t8, 0, 8);
    t13 = (t12 + 4);
    t28 = *((unsigned int *)t13);
    t29 = (~(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB195;

LAB196:    if (*((unsigned int *)t13) != 0)
        goto LAB197;

LAB198:    t27 = (t8 + 4);
    t35 = *((unsigned int *)t8);
    t36 = *((unsigned int *)t27);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB199;

LAB200:    t39 = *((unsigned int *)t8);
    t40 = (~(t39));
    t41 = *((unsigned int *)t27);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB201;

LAB202:    if (*((unsigned int *)t27) > 0)
        goto LAB203;

LAB204:    if (*((unsigned int *)t8) > 0)
        goto LAB205;

LAB206:    memcpy(t7, t34, 8);

LAB207:    t38 = (t0 + 1768);
    xsi_vlogvar_assign_value(t38, t7, 0, 0, 1);
    goto LAB25;

LAB28:    t26 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB29;

LAB30:    *((unsigned int *)t8) = 1;
    goto LAB33;

LAB32:    t33 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB33;

LAB34:    t38 = ((char*)((ng2)));
    goto LAB35;

LAB36:    t43 = ((char*)((ng3)));
    goto LAB37;

LAB38:    xsi_vlog_unsigned_bit_combine(t7, 32, t38, 32, t43, 32);
    goto LAB42;

LAB40:    memcpy(t7, t38, 8);
    goto LAB42;

LAB44:    *((unsigned int *)t12) = 1;
    goto LAB46;

LAB45:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB46;

LAB47:    *((unsigned int *)t8) = 1;
    goto LAB50;

LAB49:    t26 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB50;

LAB51:    t33 = ((char*)((ng2)));
    goto LAB52;

LAB53:    t34 = ((char*)((ng3)));
    goto LAB54;

LAB55:    xsi_vlog_unsigned_bit_combine(t7, 32, t33, 32, t34, 32);
    goto LAB59;

LAB57:    memcpy(t7, t33, 8);
    goto LAB59;

LAB60:    *((unsigned int *)t12) = 1;
    goto LAB63;

LAB64:    *((unsigned int *)t46) = 1;
    goto LAB67;

LAB66:    t26 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB67;

LAB68:    t33 = (t0 + 1048U);
    t34 = *((char **)t33);
    t33 = ((char*)((ng3)));
    memset(t47, 0, 8);
    t38 = (t34 + 4);
    t43 = (t33 + 4);
    t37 = *((unsigned int *)t34);
    t39 = *((unsigned int *)t33);
    t40 = (t37 ^ t39);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t43);
    t48 = (t41 ^ t42);
    t49 = (t40 | t48);
    t50 = *((unsigned int *)t38);
    t51 = *((unsigned int *)t43);
    t52 = (t50 | t51);
    t53 = (~(t52));
    t54 = (t49 & t53);
    if (t54 != 0)
        goto LAB72;

LAB71:    if (t52 != 0)
        goto LAB73;

LAB74:    memset(t55, 0, 8);
    t56 = (t47 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t47);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB75;

LAB76:    if (*((unsigned int *)t56) != 0)
        goto LAB77;

LAB78:    t64 = *((unsigned int *)t46);
    t65 = *((unsigned int *)t55);
    t66 = (t64 & t65);
    *((unsigned int *)t63) = t66;
    t67 = (t46 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t67);
    t71 = *((unsigned int *)t68);
    t72 = (t70 | t71);
    *((unsigned int *)t69) = t72;
    t73 = *((unsigned int *)t69);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB79;

LAB80:
LAB81:    goto LAB70;

LAB72:    *((unsigned int *)t47) = 1;
    goto LAB74;

LAB73:    t44 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB74;

LAB75:    *((unsigned int *)t55) = 1;
    goto LAB78;

LAB77:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB78;

LAB79:    t75 = *((unsigned int *)t63);
    t76 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t75 | t76);
    t77 = (t46 + 4);
    t78 = (t55 + 4);
    t79 = *((unsigned int *)t46);
    t80 = (~(t79));
    t81 = *((unsigned int *)t77);
    t82 = (~(t81));
    t83 = *((unsigned int *)t55);
    t84 = (~(t83));
    t85 = *((unsigned int *)t78);
    t86 = (~(t85));
    t87 = (t80 & t82);
    t88 = (t84 & t86);
    t89 = (~(t87));
    t90 = (~(t88));
    t91 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t91 & t89);
    t92 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t92 & t90);
    t93 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t93 & t89);
    t94 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t94 & t90);
    goto LAB81;

LAB82:    *((unsigned int *)t8) = 1;
    goto LAB85;

LAB84:    t101 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t101) = 1;
    goto LAB85;

LAB86:    t106 = ((char*)((ng2)));
    goto LAB87;

LAB88:    t111 = ((char*)((ng3)));
    goto LAB89;

LAB90:    xsi_vlog_unsigned_bit_combine(t7, 32, t106, 32, t111, 32);
    goto LAB94;

LAB92:    memcpy(t7, t106, 8);
    goto LAB94;

LAB95:    *((unsigned int *)t12) = 1;
    goto LAB98;

LAB99:    *((unsigned int *)t8) = 1;
    goto LAB102;

LAB101:    t26 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB102;

LAB103:    t33 = ((char*)((ng2)));
    goto LAB104;

LAB105:    t34 = ((char*)((ng3)));
    goto LAB106;

LAB107:    xsi_vlog_unsigned_bit_combine(t7, 32, t33, 32, t34, 32);
    goto LAB111;

LAB109:    memcpy(t7, t33, 8);
    goto LAB111;

LAB112:    *((unsigned int *)t45) = 1;
    goto LAB115;

LAB114:    t11 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB115;

LAB116:    t26 = (t0 + 1048U);
    t27 = *((char **)t26);
    t26 = ((char*)((ng3)));
    memset(t46, 0, 8);
    t33 = (t27 + 4);
    t34 = (t26 + 4);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t35 = *((unsigned int *)t33);
    t36 = *((unsigned int *)t34);
    t37 = (t35 ^ t36);
    t39 = (t32 | t37);
    t40 = *((unsigned int *)t33);
    t41 = *((unsigned int *)t34);
    t42 = (t40 | t41);
    t48 = (~(t42));
    t49 = (t39 & t48);
    if (t49 != 0)
        goto LAB120;

LAB119:    if (t42 != 0)
        goto LAB121;

LAB122:    memset(t47, 0, 8);
    t43 = (t46 + 4);
    t50 = *((unsigned int *)t43);
    t51 = (~(t50));
    t52 = *((unsigned int *)t46);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB123;

LAB124:    if (*((unsigned int *)t43) != 0)
        goto LAB125;

LAB126:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t47);
    t59 = (t57 & t58);
    *((unsigned int *)t55) = t59;
    t56 = (t45 + 4);
    t62 = (t47 + 4);
    t67 = (t55 + 4);
    t60 = *((unsigned int *)t56);
    t61 = *((unsigned int *)t62);
    t64 = (t60 | t61);
    *((unsigned int *)t67) = t64;
    t65 = *((unsigned int *)t67);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB127;

LAB128:
LAB129:    goto LAB118;

LAB120:    *((unsigned int *)t46) = 1;
    goto LAB122;

LAB121:    t38 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB122;

LAB123:    *((unsigned int *)t47) = 1;
    goto LAB126;

LAB125:    t44 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB126;

LAB127:    t70 = *((unsigned int *)t55);
    t71 = *((unsigned int *)t67);
    *((unsigned int *)t55) = (t70 | t71);
    t68 = (t45 + 4);
    t69 = (t47 + 4);
    t72 = *((unsigned int *)t45);
    t73 = (~(t72));
    t74 = *((unsigned int *)t68);
    t75 = (~(t74));
    t76 = *((unsigned int *)t47);
    t79 = (~(t76));
    t80 = *((unsigned int *)t69);
    t81 = (~(t80));
    t87 = (t73 & t75);
    t88 = (t79 & t81);
    t82 = (~(t87));
    t83 = (~(t88));
    t84 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t84 & t82);
    t85 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t85 & t83);
    t86 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t86 & t82);
    t89 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t89 & t83);
    goto LAB129;

LAB130:    *((unsigned int *)t8) = 1;
    goto LAB133;

LAB132:    t78 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB133;

LAB134:    t101 = ((char*)((ng2)));
    goto LAB135;

LAB136:    t102 = ((char*)((ng3)));
    goto LAB137;

LAB138:    xsi_vlog_unsigned_bit_combine(t7, 32, t101, 32, t102, 32);
    goto LAB142;

LAB140:    memcpy(t7, t101, 8);
    goto LAB142;

LAB143:    *((unsigned int *)t45) = 1;
    goto LAB146;

LAB145:    t11 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB146;

LAB147:    t26 = (t0 + 1048U);
    t27 = *((char **)t26);
    t26 = ((char*)((ng3)));
    memset(t46, 0, 8);
    t33 = (t27 + 4);
    t34 = (t26 + 4);
    t31 = *((unsigned int *)t27);
    t32 = *((unsigned int *)t26);
    t35 = (t31 ^ t32);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t39 = (t36 ^ t37);
    t40 = (t35 | t39);
    t41 = *((unsigned int *)t33);
    t42 = *((unsigned int *)t34);
    t48 = (t41 | t42);
    t49 = (~(t48));
    t50 = (t40 & t49);
    if (t50 != 0)
        goto LAB153;

LAB150:    if (t48 != 0)
        goto LAB152;

LAB151:    *((unsigned int *)t46) = 1;

LAB153:    memset(t47, 0, 8);
    t43 = (t46 + 4);
    t51 = *((unsigned int *)t43);
    t52 = (~(t51));
    t53 = *((unsigned int *)t46);
    t54 = (t53 & t52);
    t57 = (t54 & 1U);
    if (t57 != 0)
        goto LAB154;

LAB155:    if (*((unsigned int *)t43) != 0)
        goto LAB156;

LAB157:    t58 = *((unsigned int *)t45);
    t59 = *((unsigned int *)t47);
    t60 = (t58 | t59);
    *((unsigned int *)t55) = t60;
    t56 = (t45 + 4);
    t62 = (t47 + 4);
    t67 = (t55 + 4);
    t61 = *((unsigned int *)t56);
    t64 = *((unsigned int *)t62);
    t65 = (t61 | t64);
    *((unsigned int *)t67) = t65;
    t66 = *((unsigned int *)t67);
    t70 = (t66 != 0);
    if (t70 == 1)
        goto LAB158;

LAB159:
LAB160:    goto LAB149;

LAB152:    t38 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB153;

LAB154:    *((unsigned int *)t47) = 1;
    goto LAB157;

LAB156:    t44 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB157;

LAB158:    t71 = *((unsigned int *)t55);
    t72 = *((unsigned int *)t67);
    *((unsigned int *)t55) = (t71 | t72);
    t68 = (t45 + 4);
    t69 = (t47 + 4);
    t73 = *((unsigned int *)t68);
    t74 = (~(t73));
    t75 = *((unsigned int *)t45);
    t87 = (t75 & t74);
    t76 = *((unsigned int *)t69);
    t79 = (~(t76));
    t80 = *((unsigned int *)t47);
    t88 = (t80 & t79);
    t81 = (~(t87));
    t82 = (~(t88));
    t83 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t83 & t81);
    t84 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t84 & t82);
    goto LAB160;

LAB161:    *((unsigned int *)t8) = 1;
    goto LAB164;

LAB163:    t78 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB164;

LAB165:    t101 = ((char*)((ng2)));
    goto LAB166;

LAB167:    t102 = ((char*)((ng3)));
    goto LAB168;

LAB169:    xsi_vlog_unsigned_bit_combine(t7, 32, t101, 32, t102, 32);
    goto LAB173;

LAB171:    memcpy(t7, t101, 8);
    goto LAB173;

LAB176:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB177;

LAB178:    *((unsigned int *)t8) = 1;
    goto LAB181;

LAB180:    t26 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB181;

LAB182:    t33 = ((char*)((ng2)));
    goto LAB183;

LAB184:    t34 = ((char*)((ng3)));
    goto LAB185;

LAB186:    xsi_vlog_unsigned_bit_combine(t7, 32, t33, 32, t34, 32);
    goto LAB190;

LAB188:    memcpy(t7, t33, 8);
    goto LAB190;

LAB192:    *((unsigned int *)t12) = 1;
    goto LAB194;

LAB193:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB194;

LAB195:    *((unsigned int *)t8) = 1;
    goto LAB198;

LAB197:    t26 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB198;

LAB199:    t33 = ((char*)((ng2)));
    goto LAB200;

LAB201:    t34 = ((char*)((ng3)));
    goto LAB202;

LAB203:    xsi_vlog_unsigned_bit_combine(t7, 32, t33, 32, t34, 32);
    goto LAB207;

LAB205:    memcpy(t7, t33, 8);
    goto LAB207;

}


extern void work_m_00000000000843473622_1579609468_init()
{
	static char *pe[] = {(void *)Always_11_0};
	xsi_register_didat("work_m_00000000000843473622_1579609468", "isim/mips_tb_isim_beh.exe.sim/work/m_00000000000843473622_1579609468.didat");
	xsi_register_executes(pe);
}
