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
static const char *ng0 = "E:/Desktop/p77/p77/p77/CMP.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {3U, 0U};
static unsigned int ng4[] = {0U, 0U};
static int ng5[] = {0, 0};



static void Cont_28_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t9[8];
    char t25[8];
    char t26[8];
    char t32[8];
    char t48[8];
    char t49[8];
    char t55[8];
    char *t1;
    char *t2;
    char *t6;
    char *t8;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t51;
    char *t52;
    char *t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 1048U);
    t6 = *((char **)t2);
    t2 = (t0 + 1208U);
    t8 = *((char **)t2);
    memset(t9, 0, 8);
    xsi_vlog_signed_equal(t9, 32, t6, 32, t8, 32);
    memset(t4, 0, 8);
    t2 = (t9 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t9);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB8;

LAB9:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t25, 8);

LAB16:    t72 = (t0 + 3352);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    t75 = (t74 + 56U);
    t76 = *((char **)t75);
    memset(t76, 0, 8);
    t77 = 3U;
    t78 = t77;
    t79 = (t3 + 4);
    t80 = *((unsigned int *)t3);
    t77 = (t77 & t80);
    t81 = *((unsigned int *)t79);
    t78 = (t78 & t81);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t83 | t77);
    t84 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t84 | t78);
    xsi_driver_vfirst_trans(t72, 0, 1);
    t85 = (t0 + 3256);
    *((int *)t85) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB7;

LAB8:    t20 = ((char*)((ng1)));
    goto LAB9;

LAB10:    t28 = (t0 + 1048U);
    t29 = *((char **)t28);
    t28 = (t0 + 1208U);
    t31 = *((char **)t28);
    memset(t32, 0, 8);
    xsi_vlog_signed_greater(t32, 32, t29, 32, t31, 32);
    memset(t26, 0, 8);
    t28 = (t32 + 4);
    t33 = *((unsigned int *)t28);
    t34 = (~(t33));
    t35 = *((unsigned int *)t32);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t28) != 0)
        goto LAB19;

LAB20:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB21;

LAB22:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t39) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t26) > 0)
        goto LAB27;

LAB28:    memcpy(t25, t48, 8);

LAB29:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 2, t20, 2, t25, 2);
    goto LAB16;

LAB14:    memcpy(t3, t20, 8);
    goto LAB16;

LAB17:    *((unsigned int *)t26) = 1;
    goto LAB20;

LAB19:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB20;

LAB21:    t43 = ((char*)((ng2)));
    goto LAB22;

LAB23:    t51 = (t0 + 1048U);
    t52 = *((char **)t51);
    t51 = (t0 + 1208U);
    t54 = *((char **)t51);
    memset(t55, 0, 8);
    xsi_vlog_signed_less(t55, 32, t52, 32, t54, 32);
    memset(t49, 0, 8);
    t51 = (t55 + 4);
    t56 = *((unsigned int *)t51);
    t57 = (~(t56));
    t58 = *((unsigned int *)t55);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t51) != 0)
        goto LAB32;

LAB33:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB34;

LAB35:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t62) > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t49) > 0)
        goto LAB40;

LAB41:    memcpy(t48, t71, 8);

LAB42:    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t25, 2, t43, 2, t48, 2);
    goto LAB29;

LAB27:    memcpy(t25, t43, 8);
    goto LAB29;

LAB30:    *((unsigned int *)t49) = 1;
    goto LAB33;

LAB32:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB33;

LAB34:    t66 = ((char*)((ng3)));
    goto LAB35;

LAB36:    t71 = ((char*)((ng4)));
    goto LAB37;

LAB38:    xsi_vlog_unsigned_bit_combine(t48, 2, t66, 2, t71, 2);
    goto LAB42;

LAB40:    memcpy(t48, t66, 8);
    goto LAB42;

}

static void Cont_33_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t8[8];
    char t25[8];
    char t26[8];
    char t31[8];
    char t48[8];
    char t49[8];
    char t54[8];
    char *t1;
    char *t2;
    char *t6;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t28;
    char *t29;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t51;
    char *t52;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;

LAB0:    t1 = (t0 + 2936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1048U);
    t6 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t8, 0, 8);
    xsi_vlog_signed_equal(t8, 32, t6, 32, t2, 32);
    memset(t4, 0, 8);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t9) != 0)
        goto LAB6;

LAB7:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB8;

LAB9:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t25, 8);

LAB16:    t72 = (t0 + 3416);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    t75 = (t74 + 56U);
    t76 = *((char **)t75);
    memset(t76, 0, 8);
    t77 = 3U;
    t78 = t77;
    t79 = (t3 + 4);
    t80 = *((unsigned int *)t3);
    t77 = (t77 & t80);
    t81 = *((unsigned int *)t79);
    t78 = (t78 & t81);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t83 | t77);
    t84 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t84 | t78);
    xsi_driver_vfirst_trans(t72, 0, 1);
    t85 = (t0 + 3272);
    *((int *)t85) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB7;

LAB8:    t20 = ((char*)((ng1)));
    goto LAB9;

LAB10:    t28 = (t0 + 1048U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng5)));
    memset(t31, 0, 8);
    xsi_vlog_signed_greater(t31, 32, t29, 32, t28, 32);
    memset(t26, 0, 8);
    t32 = (t31 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t31);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t32) != 0)
        goto LAB19;

LAB20:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB21;

LAB22:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t39) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t26) > 0)
        goto LAB27;

LAB28:    memcpy(t25, t48, 8);

LAB29:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 2, t20, 2, t25, 2);
    goto LAB16;

LAB14:    memcpy(t3, t20, 8);
    goto LAB16;

LAB17:    *((unsigned int *)t26) = 1;
    goto LAB20;

LAB19:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB20;

LAB21:    t43 = ((char*)((ng2)));
    goto LAB22;

LAB23:    t51 = (t0 + 1048U);
    t52 = *((char **)t51);
    t51 = ((char*)((ng5)));
    memset(t54, 0, 8);
    xsi_vlog_signed_less(t54, 32, t52, 32, t51, 32);
    memset(t49, 0, 8);
    t55 = (t54 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t54);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t55) != 0)
        goto LAB32;

LAB33:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB34;

LAB35:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t62) > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t49) > 0)
        goto LAB40;

LAB41:    memcpy(t48, t71, 8);

LAB42:    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t25, 2, t43, 2, t48, 2);
    goto LAB29;

LAB27:    memcpy(t25, t43, 8);
    goto LAB29;

LAB30:    *((unsigned int *)t49) = 1;
    goto LAB33;

LAB32:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB33;

LAB34:    t66 = ((char*)((ng3)));
    goto LAB35;

LAB36:    t71 = ((char*)((ng4)));
    goto LAB37;

LAB38:    xsi_vlog_unsigned_bit_combine(t48, 2, t66, 2, t71, 2);
    goto LAB42;

LAB40:    memcpy(t48, t66, 8);
    goto LAB42;

}


extern void work_m_00000000003004256675_1579609468_init()
{
	static char *pe[] = {(void *)Cont_28_0,(void *)Cont_33_1};
	xsi_register_didat("work_m_00000000003004256675_1579609468", "isim/mips_txt_int_isim_beh.exe.sim/work/m_00000000003004256675_1579609468.didat");
	xsi_register_executes(pe);
}
