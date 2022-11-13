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
static const char *ng0 = "E:/Desktop/P6/FWD_CTRL.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {3U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {1U, 0U};



static void Cont_47_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t25[8];
    char t26[8];
    char t30[8];
    char t48[8];
    char t49[8];
    char t53[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;
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
    char *t50;
    char *t51;
    char *t52;
    char *t54;
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

LAB0:    t1 = (t0 + 4768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1848U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t2))
        goto LAB6;

LAB4:    t7 = (t5 + 4);
    t8 = (t2 + 4);
    if (*((unsigned int *)t7) != *((unsigned int *)t8))
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB6:    memset(t4, 0, 8);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t9) != 0)
        goto LAB9;

LAB10:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t16) > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) > 0)
        goto LAB17;

LAB18:    memcpy(t3, t25, 8);

LAB19:    t72 = (t0 + 6224);
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
    t85 = (t0 + 6080);
    *((int *)t85) = 1;

LAB1:    return;
LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    t20 = ((char*)((ng1)));
    goto LAB12;

LAB13:    t27 = (t0 + 1848U);
    t28 = *((char **)t27);
    t27 = (t0 + 2648U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    if (*((unsigned int *)t28) != *((unsigned int *)t29))
        goto LAB22;

LAB20:    t27 = (t28 + 4);
    t31 = (t29 + 4);
    if (*((unsigned int *)t27) != *((unsigned int *)t31))
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB22:    memset(t26, 0, 8);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t32) != 0)
        goto LAB25;

LAB26:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB27;

LAB28:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t39) > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t26) > 0)
        goto LAB33;

LAB34:    memcpy(t25, t48, 8);

LAB35:    goto LAB14;

LAB15:    xsi_vlog_unsigned_bit_combine(t3, 32, t20, 32, t25, 32);
    goto LAB19;

LAB17:    memcpy(t3, t20, 8);
    goto LAB19;

LAB23:    *((unsigned int *)t26) = 1;
    goto LAB26;

LAB25:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB26;

LAB27:    t43 = ((char*)((ng2)));
    goto LAB28;

LAB29:    t50 = (t0 + 1848U);
    t51 = *((char **)t50);
    t50 = (t0 + 3128U);
    t52 = *((char **)t50);
    memset(t53, 0, 8);
    if (*((unsigned int *)t51) != *((unsigned int *)t52))
        goto LAB38;

LAB36:    t50 = (t51 + 4);
    t54 = (t52 + 4);
    if (*((unsigned int *)t50) != *((unsigned int *)t54))
        goto LAB38;

LAB37:    *((unsigned int *)t53) = 1;

LAB38:    memset(t49, 0, 8);
    t55 = (t53 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t53);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t55) != 0)
        goto LAB41;

LAB42:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB43;

LAB44:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t62) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t49) > 0)
        goto LAB49;

LAB50:    memcpy(t48, t71, 8);

LAB51:    goto LAB30;

LAB31:    xsi_vlog_unsigned_bit_combine(t25, 32, t43, 32, t48, 32);
    goto LAB35;

LAB33:    memcpy(t25, t43, 8);
    goto LAB35;

LAB39:    *((unsigned int *)t49) = 1;
    goto LAB42;

LAB41:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB42;

LAB43:    t66 = ((char*)((ng3)));
    goto LAB44;

LAB45:    t71 = ((char*)((ng1)));
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t48, 32, t66, 32, t71, 32);
    goto LAB51;

LAB49:    memcpy(t48, t66, 8);
    goto LAB51;

}

static void Cont_52_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t25[8];
    char t26[8];
    char t30[8];
    char t48[8];
    char t49[8];
    char t53[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;
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
    char *t50;
    char *t51;
    char *t52;
    char *t54;
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

LAB0:    t1 = (t0 + 5016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2008U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t2))
        goto LAB6;

LAB4:    t7 = (t5 + 4);
    t8 = (t2 + 4);
    if (*((unsigned int *)t7) != *((unsigned int *)t8))
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB6:    memset(t4, 0, 8);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t9) != 0)
        goto LAB9;

LAB10:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t16) > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) > 0)
        goto LAB17;

LAB18:    memcpy(t3, t25, 8);

LAB19:    t72 = (t0 + 6288);
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
    t85 = (t0 + 6096);
    *((int *)t85) = 1;

LAB1:    return;
LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    t20 = ((char*)((ng1)));
    goto LAB12;

LAB13:    t27 = (t0 + 2008U);
    t28 = *((char **)t27);
    t27 = (t0 + 2648U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    if (*((unsigned int *)t28) != *((unsigned int *)t29))
        goto LAB22;

LAB20:    t27 = (t28 + 4);
    t31 = (t29 + 4);
    if (*((unsigned int *)t27) != *((unsigned int *)t31))
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB22:    memset(t26, 0, 8);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t32) != 0)
        goto LAB25;

LAB26:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB27;

LAB28:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t39) > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t26) > 0)
        goto LAB33;

LAB34:    memcpy(t25, t48, 8);

LAB35:    goto LAB14;

LAB15:    xsi_vlog_unsigned_bit_combine(t3, 32, t20, 32, t25, 32);
    goto LAB19;

LAB17:    memcpy(t3, t20, 8);
    goto LAB19;

LAB23:    *((unsigned int *)t26) = 1;
    goto LAB26;

LAB25:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB26;

LAB27:    t43 = ((char*)((ng2)));
    goto LAB28;

LAB29:    t50 = (t0 + 2008U);
    t51 = *((char **)t50);
    t50 = (t0 + 3128U);
    t52 = *((char **)t50);
    memset(t53, 0, 8);
    if (*((unsigned int *)t51) != *((unsigned int *)t52))
        goto LAB38;

LAB36:    t50 = (t51 + 4);
    t54 = (t52 + 4);
    if (*((unsigned int *)t50) != *((unsigned int *)t54))
        goto LAB38;

LAB37:    *((unsigned int *)t53) = 1;

LAB38:    memset(t49, 0, 8);
    t55 = (t53 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t53);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t55) != 0)
        goto LAB41;

LAB42:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB43;

LAB44:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t62) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t49) > 0)
        goto LAB49;

LAB50:    memcpy(t48, t71, 8);

LAB51:    goto LAB30;

LAB31:    xsi_vlog_unsigned_bit_combine(t25, 32, t43, 32, t48, 32);
    goto LAB35;

LAB33:    memcpy(t25, t43, 8);
    goto LAB35;

LAB39:    *((unsigned int *)t49) = 1;
    goto LAB42;

LAB41:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB42;

LAB43:    t66 = ((char*)((ng3)));
    goto LAB44;

LAB45:    t71 = ((char*)((ng1)));
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t48, 32, t66, 32, t71, 32);
    goto LAB51;

LAB49:    memcpy(t48, t66, 8);
    goto LAB51;

}

static void Cont_57_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t25[8];
    char t26[8];
    char t30[8];
    char t48[8];
    char t49[8];
    char t53[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;
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
    char *t50;
    char *t51;
    char *t52;
    char *t54;
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

LAB0:    t1 = (t0 + 5264U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2328U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t2))
        goto LAB6;

LAB4:    t7 = (t5 + 4);
    t8 = (t2 + 4);
    if (*((unsigned int *)t7) != *((unsigned int *)t8))
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB6:    memset(t4, 0, 8);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t9) != 0)
        goto LAB9;

LAB10:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t16) > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) > 0)
        goto LAB17;

LAB18:    memcpy(t3, t25, 8);

LAB19:    t72 = (t0 + 6352);
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
    t85 = (t0 + 6112);
    *((int *)t85) = 1;

LAB1:    return;
LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    t20 = ((char*)((ng1)));
    goto LAB12;

LAB13:    t27 = (t0 + 2328U);
    t28 = *((char **)t27);
    t27 = (t0 + 3128U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    if (*((unsigned int *)t28) != *((unsigned int *)t29))
        goto LAB22;

LAB20:    t27 = (t28 + 4);
    t31 = (t29 + 4);
    if (*((unsigned int *)t27) != *((unsigned int *)t31))
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB22:    memset(t26, 0, 8);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t32) != 0)
        goto LAB25;

LAB26:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB27;

LAB28:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t39) > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t26) > 0)
        goto LAB33;

LAB34:    memcpy(t25, t48, 8);

LAB35:    goto LAB14;

LAB15:    xsi_vlog_unsigned_bit_combine(t3, 32, t20, 32, t25, 32);
    goto LAB19;

LAB17:    memcpy(t3, t20, 8);
    goto LAB19;

LAB23:    *((unsigned int *)t26) = 1;
    goto LAB26;

LAB25:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB26;

LAB27:    t43 = ((char*)((ng3)));
    goto LAB28;

LAB29:    t50 = (t0 + 2328U);
    t51 = *((char **)t50);
    t50 = (t0 + 3608U);
    t52 = *((char **)t50);
    memset(t53, 0, 8);
    if (*((unsigned int *)t51) != *((unsigned int *)t52))
        goto LAB38;

LAB36:    t50 = (t51 + 4);
    t54 = (t52 + 4);
    if (*((unsigned int *)t50) != *((unsigned int *)t54))
        goto LAB38;

LAB37:    *((unsigned int *)t53) = 1;

LAB38:    memset(t49, 0, 8);
    t55 = (t53 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t53);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t55) != 0)
        goto LAB41;

LAB42:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB43;

LAB44:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t62) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t49) > 0)
        goto LAB49;

LAB50:    memcpy(t48, t71, 8);

LAB51:    goto LAB30;

LAB31:    xsi_vlog_unsigned_bit_combine(t25, 32, t43, 32, t48, 32);
    goto LAB35;

LAB33:    memcpy(t25, t43, 8);
    goto LAB35;

LAB39:    *((unsigned int *)t49) = 1;
    goto LAB42;

LAB41:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB42;

LAB43:    t66 = ((char*)((ng4)));
    goto LAB44;

LAB45:    t71 = ((char*)((ng1)));
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t48, 32, t66, 32, t71, 32);
    goto LAB51;

LAB49:    memcpy(t48, t66, 8);
    goto LAB51;

}

static void Cont_61_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t25[8];
    char t26[8];
    char t30[8];
    char t48[8];
    char t49[8];
    char t53[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;
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
    char *t50;
    char *t51;
    char *t52;
    char *t54;
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

LAB0:    t1 = (t0 + 5512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2488U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t2))
        goto LAB6;

LAB4:    t7 = (t5 + 4);
    t8 = (t2 + 4);
    if (*((unsigned int *)t7) != *((unsigned int *)t8))
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB6:    memset(t4, 0, 8);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t9) != 0)
        goto LAB9;

LAB10:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t16) > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) > 0)
        goto LAB17;

LAB18:    memcpy(t3, t25, 8);

LAB19:    t72 = (t0 + 6416);
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
    t85 = (t0 + 6128);
    *((int *)t85) = 1;

LAB1:    return;
LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    t20 = ((char*)((ng1)));
    goto LAB12;

LAB13:    t27 = (t0 + 2488U);
    t28 = *((char **)t27);
    t27 = (t0 + 3128U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    if (*((unsigned int *)t28) != *((unsigned int *)t29))
        goto LAB22;

LAB20:    t27 = (t28 + 4);
    t31 = (t29 + 4);
    if (*((unsigned int *)t27) != *((unsigned int *)t31))
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB22:    memset(t26, 0, 8);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t32) != 0)
        goto LAB25;

LAB26:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB27;

LAB28:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t39) > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t26) > 0)
        goto LAB33;

LAB34:    memcpy(t25, t48, 8);

LAB35:    goto LAB14;

LAB15:    xsi_vlog_unsigned_bit_combine(t3, 32, t20, 32, t25, 32);
    goto LAB19;

LAB17:    memcpy(t3, t20, 8);
    goto LAB19;

LAB23:    *((unsigned int *)t26) = 1;
    goto LAB26;

LAB25:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB26;

LAB27:    t43 = ((char*)((ng3)));
    goto LAB28;

LAB29:    t50 = (t0 + 2488U);
    t51 = *((char **)t50);
    t50 = (t0 + 3608U);
    t52 = *((char **)t50);
    memset(t53, 0, 8);
    if (*((unsigned int *)t51) != *((unsigned int *)t52))
        goto LAB38;

LAB36:    t50 = (t51 + 4);
    t54 = (t52 + 4);
    if (*((unsigned int *)t50) != *((unsigned int *)t54))
        goto LAB38;

LAB37:    *((unsigned int *)t53) = 1;

LAB38:    memset(t49, 0, 8);
    t55 = (t53 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t53);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t55) != 0)
        goto LAB41;

LAB42:    t62 = (t49 + 4);
    t63 = *((unsigned int *)t49);
    t64 = *((unsigned int *)t62);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB43;

LAB44:    t67 = *((unsigned int *)t49);
    t68 = (~(t67));
    t69 = *((unsigned int *)t62);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t62) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t49) > 0)
        goto LAB49;

LAB50:    memcpy(t48, t71, 8);

LAB51:    goto LAB30;

LAB31:    xsi_vlog_unsigned_bit_combine(t25, 32, t43, 32, t48, 32);
    goto LAB35;

LAB33:    memcpy(t25, t43, 8);
    goto LAB35;

LAB39:    *((unsigned int *)t49) = 1;
    goto LAB42;

LAB41:    t61 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t61) = 1;
    goto LAB42;

LAB43:    t66 = ((char*)((ng4)));
    goto LAB44;

LAB45:    t71 = ((char*)((ng1)));
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t48, 32, t66, 32, t71, 32);
    goto LAB51;

LAB49:    memcpy(t48, t66, 8);
    goto LAB51;

}

static void Cont_65_4(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t25[8];
    char t26[8];
    char t30[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    char *t8;
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;
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
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;

LAB0:    t1 = (t0 + 5760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2968U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t2))
        goto LAB6;

LAB4:    t7 = (t5 + 4);
    t8 = (t2 + 4);
    if (*((unsigned int *)t7) != *((unsigned int *)t8))
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB6:    memset(t4, 0, 8);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t9) != 0)
        goto LAB9;

LAB10:    t16 = (t4 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB11;

LAB12:    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t16) > 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) > 0)
        goto LAB17;

LAB18:    memcpy(t3, t25, 8);

LAB19:    t49 = (t0 + 6480);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    memset(t53, 0, 8);
    t54 = 3U;
    t55 = t54;
    t56 = (t3 + 4);
    t57 = *((unsigned int *)t3);
    t54 = (t54 & t57);
    t58 = *((unsigned int *)t56);
    t55 = (t55 & t58);
    t59 = (t53 + 4);
    t60 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t60 | t54);
    t61 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t61 | t55);
    xsi_driver_vfirst_trans(t49, 0, 1);
    t62 = (t0 + 6144);
    *((int *)t62) = 1;

LAB1:    return;
LAB7:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB10;

LAB11:    t20 = ((char*)((ng1)));
    goto LAB12;

LAB13:    t27 = (t0 + 2968U);
    t28 = *((char **)t27);
    t27 = (t0 + 3608U);
    t29 = *((char **)t27);
    memset(t30, 0, 8);
    if (*((unsigned int *)t28) != *((unsigned int *)t29))
        goto LAB22;

LAB20:    t27 = (t28 + 4);
    t31 = (t29 + 4);
    if (*((unsigned int *)t27) != *((unsigned int *)t31))
        goto LAB22;

LAB21:    *((unsigned int *)t30) = 1;

LAB22:    memset(t26, 0, 8);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t32) != 0)
        goto LAB25;

LAB26:    t39 = (t26 + 4);
    t40 = *((unsigned int *)t26);
    t41 = *((unsigned int *)t39);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB27;

LAB28:    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t39) > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t26) > 0)
        goto LAB33;

LAB34:    memcpy(t25, t48, 8);

LAB35:    goto LAB14;

LAB15:    xsi_vlog_unsigned_bit_combine(t3, 32, t20, 32, t25, 32);
    goto LAB19;

LAB17:    memcpy(t3, t20, 8);
    goto LAB19;

LAB23:    *((unsigned int *)t26) = 1;
    goto LAB26;

LAB25:    t38 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB26;

LAB27:    t43 = ((char*)((ng4)));
    goto LAB28;

LAB29:    t48 = ((char*)((ng1)));
    goto LAB30;

LAB31:    xsi_vlog_unsigned_bit_combine(t25, 32, t43, 32, t48, 32);
    goto LAB35;

LAB33:    memcpy(t25, t43, 8);
    goto LAB35;

}


extern void work_m_00000000003645400731_3776730196_init()
{
	static char *pe[] = {(void *)Cont_47_0,(void *)Cont_52_1,(void *)Cont_57_2,(void *)Cont_61_3,(void *)Cont_65_4};
	xsi_register_didat("work_m_00000000003645400731_3776730196", "isim/mips_txt_isim_beh.exe.sim/work/m_00000000003645400731_3776730196.didat");
	xsi_register_executes(pe);
}
