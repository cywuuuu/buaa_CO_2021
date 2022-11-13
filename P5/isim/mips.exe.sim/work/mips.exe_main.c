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
    work_m_00000000003459139932_1733832700_init();
    work_m_00000000001562163199_2057833544_init();
    work_m_00000000003755994488_0757879789_init();
    work_m_00000000000940983283_2593248389_init();
    work_m_00000000000985513734_1621229167_init();
    work_m_00000000000451558361_1785967555_init();
    work_m_00000000003004256675_1579609468_init();
    work_m_00000000004083862455_3256118061_init();
    work_m_00000000003917471152_0886308060_init();
    work_m_00000000004174116542_4111503280_init();
    work_m_00000000004217507073_0127943618_init();
    work_m_00000000001078717492_2409555401_init();
    work_m_00000000003098688854_2509864985_init();
    work_m_00000000000178975513_0939848761_init();
    work_m_00000000003645400731_3776730196_init();
    work_m_00000000000767759247_3674845529_init();
    work_m_00000000001900698854_1200043877_init();
    work_m_00000000002440506025_3877310806_init();
    work_m_00000000002047498008_0258635663_init();


    xsi_register_tops("work_m_00000000002047498008_0258635663");


    return xsi_run_simulation(argc, argv);

}
