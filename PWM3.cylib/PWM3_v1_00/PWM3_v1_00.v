
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright Kazufumi Ikemoto, 2016
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
`ifdef PWM3_V_v1_00_ALREADY_INCLUDED
`else
  `define PWMS_V_v1_00_ALREADY_INCLUDED
//`#end` -- edit above this line, do not edit this line
// Generated on 04/26/2016 at 20:42
// Component: PWM3_v1_00
  module PWM3_v1_00 (
    output  interrupt,  /* Intterupt request output signal  */
    output  pwm1,       /* PWM 1 output                     */
    output  pwm2,       /* PWM 2 output                     */
    output  pwm3,       /* PWM 3 output                     */
    output  tc,         /* Terminal count output            */
    input   capture,    /* Hardware capture (Hidden when Capture Type is set to None) */
    input   clock,      /* System clock                     */
    input   enable,     /* Hardware enable                  */
    input   kill,       /* Kill signal                      */
    input   reset,      /* System reset signal              */
    input   trigger     /* Trigger input                    */
  );

  //`#start body` -- edit after this line, do not edit this line

  localparam PWM_CAP_MODE_NONE    = 2'd0;
  localparam PWM_CAP_MODE_RISE    = 2'd1;
  localparam PWM_CAP_MODE_FALL    = 2'd2;
  localparam PWM_CAP_MODE_EITHER  = 2'd3;
  parameter [1:0] CaptureMode = PWM_CAP_MODE_NONE;

  parameter CompareStatusEdgeSense = 1;   /* boolean */

  localparam PWM_CTRL_CMPMODE_LT  = 3'h1; /* Compare Less than                */
  localparam PWM_CTRL_CMPMODE_LTE = 3'h2; /* Compare Less than or Equal to    */
  localparam PWM_CTRL_CMPMODE_GT  = 3'h3; /* Compare Greater than             */
  localparam PWM_CTRL_CMPMODE_GTE = 3'h4; /* Compare Greater than or Equal to */
  localparam PWM_CTRL_CMPMODE_SW  = 3'h5; /* Firmware control                 */
  localparam PWM_CTRL_CMPMODE_EQ  = 3'h0; /* Compare Equal to                 */
  parameter CompareType = PWM_CTRL_CMPMODE_LT;

  localparam PWM_ENMODE_CRONLY = 2'd0;
  localparam PWM_ENMODE_HWONLY = 2'd1;
  localparam PWM_ENMODE_CR_HW  = 2'd2;
  parameter [1:0] EnableMode = PWM_ENMODE_CRONLY;

  localparam PWM_KILLMODE_DISABLED    = 3'd0;
  localparam PWM_KILLMODE_ASYNCH      = 3'd1;
  localparam PWM_KILLMODE_SINGLE_CYC  = 3'd2;
  localparam PWM_KILLMODE_LATCHED     = 3'd3;
  localparam PWM_KILLMODE_MINTIME     = 3'd4;
  parameter [2:0] KillMode = PWM_KILLMODE_DISABLED;

  localparam PWM_MODE_LEFT_ALIGN      = 2'd0;
  localparam PWM_MODE_CENTER_ALIGN    = 2'd3;
  parameter [1:0] PWMMode = PWM_MODE_LEFT_ALIGN;

  localparam [7:0] PWM_8_BIT  = 8'd8;
  localparam [7:0] PWM_16_BIT = 8'd16;
  parameter  [7:0] Resolution = PWM_8_BIT;

  localparam PWM_RUNMODE_CONTINUOUS     = 2'd0;
  localparam PWM_RUNMODE_ONESHOT_SINGLE = 2'd1;
  localparam PWM_RUNMODE_ONESHOT_MULTI  = 2'd2;
  parameter [1:0] RunMode = PWM_RUNMODE_CONTINUOUS;

  localparam PWM_TRIGMODE_NONE         = 2'd0;
  localparam PWM_TRIGMODE_RISINGEDGE   = 2'd1;
  localparam PWM_TRIGMODE_FALLINGEDGE  = 2'd2;
  localparam PWM_TRIGMODE_EITHEREDGE   = 2'd3;
  parameter [1:0] TriggerMode = PWM_TRIGMODE_NONE;

  parameter UseStatus = 1;   /* boolean */

  /* Clock Enable block signal */
  wire ClockOutFromEnBlock;

  /* Clock Enable Block Component instance */
  cy_psoc3_udb_clock_enable_v1_0 #(.sync_mode(`TRUE))
  clock_enable_block (
    .clock_out(ClockOutFromEnBlock),    /* output */
    .clock_in(clock),                   /* input */ 
    .enable(1'b1)                       /* input */ 
  );

  /* Control Register Output */
  wire [7:0] control;

  /* Control Signals */
  wire ctrl_enable;
  wire [2:0] ctrl_cmpmode;
  reg runmode_enable;
  wire final_enable;

  /* Captures */
  reg prevCapture;
  wire capt_rising;
  wire capt_falling;
  wire hwEnable;
  wire hwCapture;

  /* Triggers */
  reg prevTrig;
  wire trig_rising;
  wire trig_falling;
  reg trig_disable;

  /* Kill Impl */
  reg sc_kill_tmp;
  wire sc_kill;
  reg ltch_kill_reg;
  reg min_kill_tmp;
  wire min_kill;
  wire final_kill;
  wire km_tc;
  wire km_run = min_kill_tmp;

  /* Control Register Bits */
  localparam PWM_CTRL_ENABLE      = 8'h7; /* Enable the PWM */
  localparam PWM_CTRL_UNUSED_3    = 8'h6; /* Unused */
  localparam PWM_CTRL_UNUSED_2    = 8'h5; /* Unused */
  localparam PWM_CTRL_UNUSED_1    = 8'h4; /* Unused */
  localparam PWM_CTRL_UNUSED_0    = 8'h3; /* Unused */
  localparam PWM_CTRL_CMPMODE_2   = 8'h2; /* Compare mode */
  localparam PWM_CTRL_CMPMODE_1   = 8'h1; /* Compare mode */
  localparam PWM_CTRL_CMPMODE_0   = 8'h0; /* Compare mode */

  /****************************************************/
  /* Control Register Implementation                  */
  /****************************************************/
  generate
  if((EnableMode != PWM_ENMODE_HWONLY) || (CompareType == PWM_CTRL_CMPMODE_SW))
  begin
    cy_psoc3_control #(.cy_force_order(`TRUE), .cy_ctrl_mode_1(8'h00), .cy_ctrl_mode_0(8'hFF))
    ctrlreg(
      .clock(ClockOutFromEnBlock),    /* input */
      .control(control)               /* output */
    );
    assign ctrl_enable = control[PWM_CTRL_ENABLE];
  end
  else
  begin
    assign control = 8'd0;
    assign ctrl_enable = 1'b1;
  end
  endgenerate

  generate
  if(CompareType == PWM_CTRL_CMPMODE_SW)
  begin : sCMPSW
    assign ctrl_cmpmode = {control[PWM_CTRL_CMPMODE_2], control[PWM_CTRL_CMPMODE_1], control[PWM_CTRL_CMPMODE_0]};
  end
  else 
  begin
    assign ctrl_cmpmode = CompareType;
  end
  endgenerate

  /****************************************************/
  /* Capture Input Implementations                    */
  /****************************************************/
  always @(posedge ClockOutFromEnBlock)
  begin
    prevCapture <= capture;
  end
  assign capt_rising = !prevCapture & capture;
  assign capt_falling = prevCapture & !capture;
  assign hwCapture = (CaptureMode == PWM_CAP_MODE_NONE) ? 1'b0 :
  (CaptureMode == PWM_CAP_MODE_RISE) ? capt_rising :
  (CaptureMode == PWM_CAP_MODE_FALL) ? capt_falling :
  /*(CaptureMode == PWM_CAP_MODE_EITHER) ?*/ (capt_rising | capt_falling);

  /****************************************************/
  /* Enable Mode Block Implementation                 */
  /****************************************************/
  assign hwEnable = (EnableMode == PWM_ENMODE_CRONLY) ? ctrl_enable :
  (EnableMode == PWM_ENMODE_HWONLY) ? enable :
  (ctrl_enable & enable);

  /****************************************************/
  /* Trigger Mode Block Implementations               */
  /****************************************************/
  always @(posedge ClockOutFromEnBlock)
  begin
    prevTrig <= trigger;
  end

  assign trig_rising = trigger & !prevTrig;
  assign trig_falling = !trigger & prevTrig;

  assign trig_out = (TriggerMode == PWM_TRIGMODE_NONE) ? 1'b1 :
  (TriggerMode == PWM_TRIGMODE_RISINGEDGE) ? trig_rising :
  (TriggerMode == PWM_TRIGMODE_FALLINGEDGE) ? trig_falling :
  /*(TriggerMode == PWM_TRIGMODE_EITHEREDGE) ?*/ (trig_rising | trig_falling);

  /****************************************************/
  /* Run Mode Block Implementations                   */
  /****************************************************/
  generate
  if(RunMode == PWM_RUNMODE_CONTINUOUS)
  begin : sRMC
    always @(posedge ClockOutFromEnBlock or posedge reset)
    begin
      if(reset)
        runmode_enable <= 1'b0;
      else if(!hwEnable)
        runmode_enable <= 1'b0;
      else if(trig_out & hwEnable)
        runmode_enable <= 1'b1;
    end

    assign final_enable = runmode_enable;
  end
  else if (RunMode == PWM_RUNMODE_ONESHOT_SINGLE)
  begin : sRMOSS
    always @(posedge ClockOutFromEnBlock or posedge reset)
    begin
      if(reset)
      begin
        runmode_enable <= 1'b0;
        trig_disable <= 1'b0;
      end
      else if(!hwEnable)
      begin
        runmode_enable <= 1'b0;
      end
      else if(runmode_enable & tc_i)
      begin
        runmode_enable <= 1'b0;
        trig_disable <= 1'b1;
      end
      else if(trig_out & !trig_disable & hwEnable)
      begin
        runmode_enable <= 1'b1;
      end
    end

    assign final_enable = runmode_enable;
  end
  else if(RunMode == PWM_RUNMODE_ONESHOT_MULTI)
  begin : sRMOSM
    always @(posedge ClockOutFromEnBlock or posedge reset)
    begin
      if(reset)
        runmode_enable <= 1'b0;
      else if(!hwEnable)
        runmode_enable <= 1'b0;
      else if(trig_out)
        runmode_enable <= 1'b1;
      else if(runmode_enable & tc_i & hwEnable)
        runmode_enable <= 1'b0;
    end

    assign final_enable = runmode_enable;
  end
  endgenerate

  /****************************************************/
  /* Kill Implementations                             */
  /****************************************************/
  /* Single Cycle */
  always @(posedge ClockOutFromEnBlock)
  begin
    if(tc_i)
    begin
      sc_kill_tmp <= 1'b0;
    end
    else if(kill)
    begin
      sc_kill_tmp <= !sc_kill_tmp ? 1'b1 : sc_kill_tmp;
    end
  end

  /* Latched Kill */
  always @(posedge ClockOutFromEnBlock or posedge reset)
  begin
    if(reset)
    begin
      ltch_kill_reg <= 1'b0;
    end
    else if(kill)
    begin
      ltch_kill_reg <= !ltch_kill_reg ? 1'b1 : ltch_kill_reg;
    end
  end

  /* Min Time Kill */
  always @(posedge ClockOutFromEnBlock or posedge reset)
  begin
    if(reset)
    begin
      min_kill_tmp <= 1'b0;
    end
    else if(kill)
    begin
      min_kill_tmp <= !min_kill_tmp ? 1'b1 : min_kill_tmp;
    end
    else if(km_tc)
    begin
      min_kill_tmp <= 1'b0;
    end
  end

  assign sc_kill = ~(kill | sc_kill_tmp);
  assign min_kill = kill | min_kill_tmp;

  assign final_kill = (KillMode == PWM_KILLMODE_ASYNCH) ? !kill :
  (KillMode == PWM_KILLMODE_SINGLE_CYC) ? sc_kill :
  (KillMode == PWM_KILLMODE_LATCHED) ? !ltch_kill_reg :
  (KillMode == PWM_KILLMODE_MINTIME) ? !min_kill :
  /*(KillMode == PWM_KILLMODE_DISABLED) ?*/ 1'b1;

  generate
  if(KillMode == PWM_KILLMODE_MINTIME)
  begin : sKM
    cy_psoc3_dp8 #(.cy_dpconfig_a(
      {
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM0:   Preload Period (A0 <= D0)*/
        `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM1:   Dec A0 (A0 <= A0 - 1)*/
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM2:    */
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM3:    */
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM4:    */
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM5:    */
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM6:    */
        `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
        `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
        `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
        `CS_CMP_SEL_CFGA, /*CFGRAM7:    */
        8'hFF, 8'h00,  /*CFG9:    */
        8'hFF, 8'hFF,  /*CFG11-10:    */
        `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
        `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
        `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
        `SC_SI_A_DEFSI, /*CFG13-12:    */
        `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
        1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
        `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
        `SC_FB_NOCHN, `SC_CMP1_NOCHN,
        `SC_CMP0_NOCHN, /*CFG15-14:    */
        10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
        `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
        `SC_WRK16CAT_DSBL /*CFG17-16:    */
      }
    )) killmodecounterdp(
      /*  input                   */  .reset(1'b0),
      /*  input                   */  .clk(ClockOutFromEnBlock),
      /*  input   [02:00]         */  .cs_addr({2'b0, km_run}),
      /*  input                   */  .route_si(1'b0),
      /*  input                   */  .route_ci(1'b0),
      /*  input                   */  .f0_load(1'b0),
      /*  input                   */  .f1_load(1'b0),
      /*  input                   */  .d0_load(1'b0),
      /*  input                   */  .d1_load(1'b0),
      /*  output                  */  .ce0(),
      /*  output                  */  .cl0(),
      /*  output                  */  .z0(km_tc),
      /*  output                  */  .ff0(),
      /*  output                  */  .ce1(),
      /*  output                  */  .cl1(),
      /*  output                  */  .z1(),
      /*  output                  */  .ff1(),
      /*  output                  */  .ov_msb(),
      /*  output                  */  .co_msb(),
      /*  output                  */  .cmsb(),
      /*  output                  */  .so(),
      /*  output                  */  .f0_bus_stat(),
      /*  output                  */  .f0_blk_stat(),
      /*  output                  */  .f1_bus_stat(),
      /*  output                  */  .f1_blk_stat()
    );
  end
  else
  begin
    assign km_tc = 1'b0;
  end
  endgenerate



//`#end` -- edit above this line, do not edit this line
  endmodule
  //`#start footer` -- edit after this line, do not edit this line
`endif  /* PWM3_V_v1_10_ALREADY_INCLUDED */
//`#end` -- edit above this line, do not edit this line




