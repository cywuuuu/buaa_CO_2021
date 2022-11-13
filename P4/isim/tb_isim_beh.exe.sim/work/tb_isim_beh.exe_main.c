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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002977261959_2593248389_init();
    work_m_00000000004282339459_1733832700_init();
    work_m_00000000003358627717_0757879789_init();
    work_m_00000000000375193601_0467708899_init();
    work_m_00000000000985513734_1621229167_init();
    work_m_00000000000451558361_1785967555_init();
    work_m_00000000002038104326_0886308060_init();
    work_m_00000000001245424467_2924402094_init();
    work_m_00000000002318464687_1941408880_init();
    work_m_00000000000463453276_1917266896_init();
    work_m_00000000000599423260_3877310806_init();
    work_m_00000000002047498008_3671711236_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002047498008_3671711236");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
