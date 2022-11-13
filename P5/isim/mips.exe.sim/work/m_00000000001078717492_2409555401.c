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
static unsigned int ng1[] = {15U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {3U, 0U};
static unsigned int ng4[] = {12U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {8U, 0U};



static void Always_42_0(char *t0)
{
    char t13[8];
    char t37[8];
    char t39[8];
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
    char *t15;
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
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t38;
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
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3008);
    *((int *)t2) = 1;
    t3 = (t0 + 2720);
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

LAB7:
LAB75:    t2 = ((char*)((ng0)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB8:    goto LAB2;

LAB6:
LAB9:    t11 = (t0 + 1368U);
    t12 = *((char **)t11);
    t11 = ((char*)((ng0)));
    memset(t13, 0, 8);
    t14 = (t12 + 4);
    t15 = (t11 + 4);
    t16 = *((unsigned int *)t12);
    t17 = *((unsigned int *)t11);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t14);
    t20 = *((unsigned int *)t15);
    t21 = (t19 ^ t20);
    t22 = (t18 | t21);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t15);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB13;

LAB10:    if (t25 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t13) = 1;

LAB13:    t29 = (t13 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB14;

LAB15:    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t13, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t16 = (t9 ^ t10);
    t17 = (t8 | t16);
    t18 = *((unsigned int *)t4);
    t19 = *((unsigned int *)t5);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB20;

LAB17:    if (t20 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t13) = 1;

LAB20:    t12 = (t13 + 4);
    t23 = *((unsigned int *)t12);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB21;

LAB22:    t2 = (t0 + 1368U);
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
    t16 = (t9 ^ t10);
    t17 = (t8 | t16);
    t18 = *((unsigned int *)t4);
    t19 = *((unsigned int *)t5);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB42;

LAB39:    if (t20 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t13) = 1;

LAB42:    t12 = (t13 + 4);
    t23 = *((unsigned int *)t12);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB43;

LAB44:
LAB45:
LAB23:
LAB16:    goto LAB8;

LAB12:    t28 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB13;

LAB14:    t35 = ((char*)((ng1)));
    t36 = (t0 + 1768);
    xsi_vlogvar_assign_value(t36, t35, 0, 0, 4);
    goto LAB16;

LAB19:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB20;

LAB21:
LAB24:    t14 = (t0 + 1048U);
    t15 = *((char **)t14);
    memset(t37, 0, 8);
    t14 = (t37 + 4);
    t28 = (t15 + 4);
    t30 = *((unsigned int *)t15);
    t31 = (t30 >> 1);
    t32 = (t31 & 1);
    *((unsigned int *)t37) = t32;
    t33 = *((unsigned int *)t28);
    t34 = (t33 >> 1);
    t38 = (t34 & 1);
    *((unsigned int *)t14) = t38;
    t29 = ((char*)((ng0)));
    memset(t39, 0, 8);
    t35 = (t37 + 4);
    t36 = (t29 + 4);
    t40 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t29);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t35);
    t44 = *((unsigned int *)t36);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t35);
    t48 = *((unsigned int *)t36);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB28;

LAB25:    if (t49 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t39) = 1;

LAB28:    t53 = (t39 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t39);
    t57 = (t56 & t55);
    t58 = (t57 != 0);
    if (t58 > 0)
        goto LAB29;

LAB30:    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 1);
    t16 = (t10 & 1);
    *((unsigned int *)t2) = t16;
    t5 = ((char*)((ng2)));
    memset(t37, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 ^ t21);
    t23 = (t19 | t22);
    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t30 = (t23 & t27);
    if (t30 != 0)
        goto LAB35;

LAB32:    if (t26 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t37) = 1;

LAB35:    t15 = (t37 + 4);
    t31 = *((unsigned int *)t15);
    t32 = (~(t31));
    t33 = *((unsigned int *)t37);
    t34 = (t33 & t32);
    t38 = (t34 != 0);
    if (t38 > 0)
        goto LAB36;

LAB37:
LAB38:
LAB31:    goto LAB23;

LAB27:    t52 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB28;

LAB29:    t59 = ((char*)((ng3)));
    t60 = (t0 + 1768);
    xsi_vlogvar_assign_value(t60, t59, 0, 0, 4);
    goto LAB31;

LAB34:    t14 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB35;

LAB36:    t28 = ((char*)((ng4)));
    t29 = (t0 + 1768);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 4);
    goto LAB38;

LAB41:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB42;

LAB43:
LAB46:    t14 = (t0 + 1048U);
    t15 = *((char **)t14);
    memset(t37, 0, 8);
    t14 = (t37 + 4);
    t28 = (t15 + 4);
    t30 = *((unsigned int *)t15);
    t31 = (t30 >> 0);
    *((unsigned int *)t37) = t31;
    t32 = *((unsigned int *)t28);
    t33 = (t32 >> 0);
    *((unsigned int *)t14) = t33;
    t34 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t34 & 3U);
    t38 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t38 & 3U);
    t29 = ((char*)((ng0)));
    memset(t39, 0, 8);
    t35 = (t37 + 4);
    t36 = (t29 + 4);
    t40 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t29);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t35);
    t44 = *((unsigned int *)t36);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t35);
    t48 = *((unsigned int *)t36);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB50;

LAB47:    if (t49 != 0)
        goto LAB49;

LAB48:    *((unsigned int *)t39) = 1;

LAB50:    t53 = (t39 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t39);
    t57 = (t56 & t55);
    t58 = (t57 != 0);
    if (t58 > 0)
        goto LAB51;

LAB52:    t2 = (t0 + 1048U);
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
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 3U);
    t5 = ((char*)((ng2)));
    memset(t37, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 ^ t21);
    t23 = (t19 | t22);
    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t30 = (t23 & t27);
    if (t30 != 0)
        goto LAB57;

LAB54:    if (t26 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t37) = 1;

LAB57:    t15 = (t37 + 4);
    t31 = *((unsigned int *)t15);
    t32 = (~(t31));
    t33 = *((unsigned int *)t37);
    t34 = (t33 & t32);
    t38 = (t34 != 0);
    if (t38 > 0)
        goto LAB58;

LAB59:    t2 = (t0 + 1048U);
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
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 3U);
    t5 = ((char*)((ng5)));
    memset(t37, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 ^ t21);
    t23 = (t19 | t22);
    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t30 = (t23 & t27);
    if (t30 != 0)
        goto LAB64;

LAB61:    if (t26 != 0)
        goto LAB63;

LAB62:    *((unsigned int *)t37) = 1;

LAB64:    t15 = (t37 + 4);
    t31 = *((unsigned int *)t15);
    t32 = (~(t31));
    t33 = *((unsigned int *)t37);
    t34 = (t33 & t32);
    t38 = (t34 != 0);
    if (t38 > 0)
        goto LAB65;

LAB66:    t2 = (t0 + 1048U);
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
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 3U);
    t5 = ((char*)((ng3)));
    memset(t37, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 ^ t21);
    t23 = (t19 | t22);
    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t30 = (t23 & t27);
    if (t30 != 0)
        goto LAB71;

LAB68:    if (t26 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t37) = 1;

LAB71:    t15 = (t37 + 4);
    t31 = *((unsigned int *)t15);
    t32 = (~(t31));
    t33 = *((unsigned int *)t37);
    t34 = (t33 & t32);
    t38 = (t34 != 0);
    if (t38 > 0)
        goto LAB72;

LAB73:
LAB74:
LAB67:
LAB60:
LAB53:    goto LAB45;

LAB49:    t52 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB50;

LAB51:    t59 = ((char*)((ng2)));
    t60 = (t0 + 1768);
    xsi_vlogvar_assign_value(t60, t59, 0, 0, 4);
    goto LAB53;

LAB56:    t14 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB57;

LAB58:    t28 = ((char*)((ng5)));
    t29 = (t0 + 1768);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 4);
    goto LAB60;

LAB63:    t14 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB64;

LAB65:    t28 = ((char*)((ng6)));
    t29 = (t0 + 1768);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 4);
    goto LAB67;

LAB70:    t14 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB71;

LAB72:    t28 = ((char*)((ng7)));
    t29 = (t0 + 1768);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 4);
    goto LAB74;

}


extern void work_m_00000000001078717492_2409555401_init()
{
	static char *pe[] = {(void *)Always_42_0};
	xsi_register_didat("work_m_00000000001078717492_2409555401", "isim/mips.exe.sim/work/m_00000000001078717492_2409555401.didat");
	xsi_register_executes(pe);
}
