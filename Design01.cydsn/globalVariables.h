/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "cytypes.h"

/* Error codes */
#define NO_ERROR 0
#define ERROR_HALL_SENSOR 1
#define ERROR_DIR_ROTATE 2
extern uint16 status_error;

#define LENGTH_TABLE 1536
#define LENGTH_TABLEdiv3 512
extern int16 const table_pphi[LENGTH_TABLE];  // Min:0, Max:4494
extern int16 const table_p_Lpphi[LENGTH_TABLE];  // Min:-868, Max:951
extern const int8 table_phase[8];
extern const uint8 table_hallState[8];

#define HALL_STATE_0 0b110
#define HALL_STATE_1 0b010
#define HALL_STATE_2 0b011
#define HALL_STATE_3 0b001
#define HALL_STATE_4 0b101
#define HALL_STATE_5 0b100
#define HALL_STATE_SHORT 0b000
#define HALL_STATE_OPEN 0b111

#define DIR_NORMAL 1
#define DIR_INVERSE -1
#define DIR_VERYSLOW 0
// #define DIR_ERROR 2

typedef struct {
  int32 thm0;
  int32 wm0;
  int32 am0;
  int8 direction;
  int8 updated;
} AngleParams;
extern AngleParams angleParams;

#define LENGTH_HIST 4
typedef struct {
  int8 phase[LENGTH_HIST];
  uint16 time[LENGTH_HIST];
} HallHist;
extern HallHist hallHist;

#define THETA_360DEG  0x18000000L
#define THETA_60DEG   0x04000000L
// #define THETA_120DEG  0x08000000L
#define THETA_OFFSET  0x00444444L // = 4deg
#define THETA_HIS     0x00111111L // = 1deg

#define BITs_BIAS_ACC 20
#define BIAS_ACC  0x100000L
// #define BITs_BIAS_OMEGA 0
// #define BIAS_OMEGA 1

void Set_angleParams_Center();
void Set_angleParams_Forward();
void Set_angleParams_Backward();

#define PRECISION_PWM 256

#define PERIOD_COUNTER_HALL 65536L
#define COMPARE_COUNTER_HALL 50000

extern int32 vbat_adc, vbat_ave;
extern int32 inv_vbat;
#define VBAT_NORMAL 0xA3A3  // = 7.20 V
#define VBAT_MAX    0xFFFF  // = 11.26 V
#define OFFSET_INVVBAT 12
#define BIAS_INVVBAT  0x1000L
#define VBAT_NORMALwithOFFSET_INVVBAT 171585164L  // = VBAT_NORMAL * BIAS_INVVBAT

extern int32 lambda;
#define PRECISION_LAMBDA 4096

inline uint32 pmod32(int32 i, int32 n);
inline uint16 pmod16(int16 i, int16 n);
inline unsigned int pmodi(int i, int n);

/* For measurement of CPU cycles */
#ifdef DEBUG
#define SYSTICK_MAXVAL 0x00FFFFFFUL
extern volatile uint32 SysCntVal;
extern volatile uint32 debugregs[4];
#endif

#endif  // GLOBAL_VARIABLES_H
/* [] END OF FILE */
