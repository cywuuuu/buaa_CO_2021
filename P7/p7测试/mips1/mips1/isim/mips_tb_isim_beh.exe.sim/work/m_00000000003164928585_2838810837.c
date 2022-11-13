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
static const char *ng0 = "C:/Users/86135/Desktop/test_demo/test_p7/test_cmp1.3/mips1/src/M_CHK.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {1U, 0U};



static void Always_14_0(char *t0)
{
    char t7[8];
    char t8[8];
    char t9[8];
    char t12[8];
    char t45[8];
    char t49[8];
    char t55[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
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
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;

LAB0:    t1 = (t0 + 3008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(14, ng0);
    t2 = (t0 + 3576);
    *((int *)t2) = 1;
    t3 = (t0 + 3040);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(14, ng0);

LAB5:    xsi_set_current_line(15, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(16, ng0);
    t10 = (t0 + 1048U);
    t11 = *((char **)t10);
    memset(t12, 0, 8);
    t10 = (t12 + 4);
    t13 = (t11 + 4);
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t12) = t16;
    t17 = *((unsigned int *)t13);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t10) = t19;
    memset(t9, 0, 8);
    t20 = (t12 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t12);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t20) == 0)
        goto LAB14;

LAB16:    t26 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t26) = 1;

LAB17:    memset(t8, 0, 8);
    t27 = (t9 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t9);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t27) != 0)
        goto LAB20;

LAB21:    t34 = (t8 + 4);
    t35 = *((unsigned int *)t8);
    t36 = *((unsigned int *)t34);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB22;

LAB23:    t39 = *((unsigned int *)t8);
    t40 = (~(t39));
    t41 = *((unsigned int *)t34);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t34) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t8) > 0)
        goto LAB28;

LAB29:    memcpy(t7, t43, 8);

LAB30:    t44 = (t0 + 2088);
    xsi_vlogvar_assign_value(t44, t7, 0, 0, 1);
    goto LAB13;

LAB9:    xsi_set_current_line(17, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t9 + 4);
    t10 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t10);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t3) = t19;
    memset(t12, 0, 8);
    t11 = (t9 + 4);
    t21 = *((unsigned int *)t11);
    t22 = (~(t21));
    t23 = *((unsigned int *)t9);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t11) != 0)
        goto LAB33;

LAB34:    t20 = (t12 + 4);
    t28 = *((unsigned int *)t12);
    t29 = *((unsigned int *)t20);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB35;

LAB36:    memcpy(t55, t12, 8);

LAB37:    memset(t8, 0, 8);
    t87 = (t55 + 4);
    t88 = *((unsigned int *)t87);
    t89 = (~(t88));
    t90 = *((unsigned int *)t55);
    t91 = (t90 & t89);
    t92 = (t91 & 1U);
    if (t92 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t87) != 0)
        goto LAB51;

LAB52:    t94 = (t8 + 4);
    t95 = *((unsigned int *)t8);
    t96 = *((unsigned int *)t94);
    t97 = (t95 || t96);
    if (t97 > 0)
        goto LAB53;

LAB54:    t99 = *((unsigned int *)t8);
    t100 = (~(t99));
    t101 = *((unsigned int *)t94);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t94) > 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t8) > 0)
        goto LAB59;

LAB60:    memcpy(t7, t103, 8);

LAB61:    t104 = (t0 + 2088);
    xsi_vlogvar_assign_value(t104, t7, 0, 0, 1);
    goto LAB13;

LAB14:    *((unsigned int *)t9) = 1;
    goto LAB17;

LAB18:    *((unsigned int *)t8) = 1;
    goto LAB21;

LAB20:    t33 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB21;

LAB22:    t38 = ((char*)((ng2)));
    goto LAB23;

LAB24:    t43 = ((char*)((ng3)));
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t7, 32, t38, 32, t43, 32);
    goto LAB30;

LAB28:    memcpy(t7, t38, 8);
    goto LAB30;

LAB31:    *((unsigned int *)t12) = 1;
    goto LAB34;

LAB33:    t13 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB34;

LAB35:    t26 = (t0 + 1048U);
    t27 = *((char **)t26);
    t26 = ((char*)((ng3)));
    memset(t45, 0, 8);
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
    t46 = (t41 | t42);
    t47 = (~(t46));
    t48 = (t40 & t47);
    if (t48 != 0)
        goto LAB39;

LAB38:    if (t46 != 0)
        goto LAB40;

LAB41:    memset(t49, 0, 8);
    t43 = (t45 + 4);
    t50 = *((unsigned int *)t43);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t43) != 0)
        goto LAB44;

LAB45:    t56 = *((unsigned int *)t12);
    t57 = *((unsigned int *)t49);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t12 + 4);
    t60 = (t49 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB46;

LAB47:
LAB48:    goto LAB37;

LAB39:    *((unsigned int *)t45) = 1;
    goto LAB41;

LAB40:    t38 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB41;

LAB42:    *((unsigned int *)t49) = 1;
    goto LAB45;

LAB44:    t44 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB45;

LAB46:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t12 + 4);
    t70 = (t49 + 4);
    t71 = *((unsigned int *)t12);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t49);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t79 = (t72 & t74);
    t80 = (t76 & t78);
    t81 = (~(t79));
    t82 = (~(t80));
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t84 & t82);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    t86 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t86 & t82);
    goto LAB48;

LAB49:    *((unsigned int *)t8) = 1;
    goto LAB52;

LAB51:    t93 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t93) = 1;
    goto LAB52;

LAB53:    t98 = ((char*)((ng2)));
    goto LAB54;

LAB55:    t103 = ((char*)((ng3)));
    goto LAB56;

LAB57:    xsi_vlog_unsigned_bit_combine(t7, 32, t98, 32, t103, 32);
    goto LAB61;

LAB59:    memcpy(t7, t98, 8);
    goto LAB61;

}

static void Cont_22_1(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;

LAB0:    t1 = (t0 + 3256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 2088);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = (~(t20));
    t22 = *((unsigned int *)t14);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t24, 8);

LAB16:    t18 = (t0 + 3672);
    t25 = (t18 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t3, 8);
    xsi_driver_vfirst_trans(t18, 0, 31);
    t29 = (t0 + 3592);
    *((int *)t29) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 1208U);
    t19 = *((char **)t18);
    goto LAB9;

LAB10:    t18 = (t0 + 1368U);
    t24 = *((char **)t18);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t19, 32, t24, 32);
    goto LAB16;

LAB14:    memcpy(t3, t19, 8);
    goto LAB16;

}


extern void work_m_00000000003164928585_2838810837_init()
{
	static char *pe[] = {(void *)Always_14_0,(void *)Cont_22_1};
	xsi_register_didat("work_m_00000000003164928585_2838810837", "isim/mips_tb_isim_beh.exe.sim/work/m_00000000003164928585_2838810837.didat");
	xsi_register_executes(pe);
}
