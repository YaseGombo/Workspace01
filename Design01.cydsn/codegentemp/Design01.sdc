# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\KI\Documents\PSoC Creator\Workspace01\Design01.cydsn\Design01.cyprj
# Date: Sat, 23 Jul 2016 15:43:17 GMT
#set_units -time ns
create_clock -name {ADC_DelSig_1_Ext_CP_Clk(routed)} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyXTAL} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {CydwClock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_clock -name {CydwClock_1(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/dclk_glb_ff_0}]
create_clock -name {ADC_DelSig_1_Ext_CP_Clk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 105 209} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {ADC_DelSig_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 375 751} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {ADC_DelSig_1_theACLK(fixed-function)} -period 7812.5 -waveform {0 3906.25} [get_pins {ClockBlock/aclk_glb_ff_0}]

set_false_path -from [get_pins {__ONE__/q}]
set_false_path -from [get_pins {__ZERO__/q}]

# Component constraints for E:\KI\Documents\PSoC Creator\Workspace01\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: E:\KI\Documents\PSoC Creator\Workspace01\Design01.cydsn\Design01.cyprj
# Date: Sat, 23 Jul 2016 15:43:10 GMT
