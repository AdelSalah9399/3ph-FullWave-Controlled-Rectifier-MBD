/*
 * File: Three_ph_controlled_Reectifired_private.h
 *
 * Code generated for Simulink model 'Three_ph_controlled_Reectifired'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Aug 31 23:10:43 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Three_ph_controlled_Reectifired_private_h_
#define RTW_HEADER_Three_ph_controlled_Reectifired_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void sfun_spid_contc(SimStruct *rts);

/* private model entry point functions */
extern void Three_ph_controlled_Reectifired_derivatives(void);

#endif               /* RTW_HEADER_Three_ph_controlled_Reectifired_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
