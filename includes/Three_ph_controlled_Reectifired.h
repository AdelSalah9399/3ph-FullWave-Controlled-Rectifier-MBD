/*
 * File: Three_ph_controlled_Reectifired.h
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

#ifndef RTW_HEADER_Three_ph_controlled_Reectifired_h_
#define RTW_HEADER_Three_ph_controlled_Reectifired_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef Three_ph_controlled_Reectifired_COMMON_INCLUDES_
#define Three_ph_controlled_Reectifired_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                    /* Three_ph_controlled_Reectifired_COMMON_INCLUDES_ */

#include "Three_ph_controlled_Reectifired_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T StateSpace_o1[7];             /* '<S41>/State-Space' */
  real_T StateSpace_o2[12];            /* '<S41>/State-Space' */
  real_T StateSpace_RWORK[2];          /* '<S41>/State-Space' */
  real_T SineWaveA;                    /* '<S40>/Sine Wave A' */
  real_T SineWaveB;                    /* '<S40>/Sine Wave B' */
  real_T SineWaveC;                    /* '<S40>/Sine Wave C' */
  real_T PulseT1;                      /* '<Root>/Pulse T1' */
  real_T PulseT2;                      /* '<Root>/Pulse T2' */
  real_T PulseT3;                      /* '<Root>/Pulse T3' */
  real_T PulseT4;                      /* '<Root>/Pulse T4' */
  real_T PulseT5;                      /* '<Root>/Pulse T5' */
  real_T PulseT6;                      /* '<Root>/Pulse T6' */
  int_T StateSpace_IWORK[23];          /* '<S41>/State-Space' */
  int_T StateSpace_MODE[7];            /* '<S41>/State-Space' */
  int32_T clockTickCounter;            /* '<Root>/Pulse T1' */
  int32_T clockTickCounter_n;          /* '<Root>/Pulse T2' */
  int32_T clockTickCounter_h;          /* '<Root>/Pulse T3' */
  int32_T clockTickCounter_g;          /* '<Root>/Pulse T4' */
  int32_T clockTickCounter_m;          /* '<Root>/Pulse T5' */
  int32_T clockTickCounter_g3;         /* '<Root>/Pulse T6' */
  void *StateSpace_PWORK[22];          /* '<S41>/State-Space' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<S41>/State-Space' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<S41>/State-Space' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[6];      /* '<S41>/State-Space' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Vf)
   * Referenced by:
   *   '<S13>/ddd'
   *   '<S15>/ddd'
   *   '<S17>/ddd'
   *   '<S19>/ddd'
   *   '<S21>/ddd'
   *   '<S23>/ddd'
   */
  real_T pooled1;

  /* Computed Parameter: StateSpace_P1_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P1_Size[2];

  /* Expression: S.Mg
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P1[874];

  /* Computed Parameter: StateSpace_P2_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P2_Size[2];

  /* Expression: [S.nb.x S.nb.u S.nb.y S.nb.s]
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P2[4];

  /* Computed Parameter: StateSpace_P3_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P3_Size[2];

  /* Expression: S.x0
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P3[6];

  /* Computed Parameter: StateSpace_P4_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P4_Size[2];

  /* Computed Parameter: StateSpace_P4
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P4[1518];

  /* Computed Parameter: StateSpace_P5_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P5_Size[2];

  /* Expression: S.SwitchVf
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P5[12];

  /* Computed Parameter: StateSpace_P6_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P6_Size[2];

  /* Expression: S.SwitchType
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P6[6];

  /* Computed Parameter: StateSpace_P7_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P7_Size[2];

  /* Expression: S.SwitchGateInitialValue
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P7[6];

  /* Computed Parameter: StateSpace_P8_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P8_Size[2];

  /* Expression: S.SwitchTolerance
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P8[6];

  /* Computed Parameter: StateSpace_P9_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P9_Size[2];

  /* Expression: S.SaveMatrices
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P9;

  /* Computed Parameter: StateSpace_P10_Size
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P10_Size[2];

  /* Expression: S.BufferSize
   * Referenced by: '<S41>/State-Space'
   */
  real_T StateSpace_P10;
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[9];
      real_T const *UPtrs1[6];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn0;
  } NonInlinedSFcns;

  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Three_ph_controlled_Reectifired_initialize(void);
extern void Three_ph_controlled_Reectifired_step(void);
extern void Three_ph_controlled_Reectifired_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Gain2' : Unused code path elimination
 * Block '<S12>/To Workspace' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S13>/Ron' : Unused code path elimination
 * Block '<S13>/Sum' : Unused code path elimination
 * Block '<S15>/Ron' : Unused code path elimination
 * Block '<S15>/Sum' : Unused code path elimination
 * Block '<S17>/Ron' : Unused code path elimination
 * Block '<S17>/Sum' : Unused code path elimination
 * Block '<S19>/Ron' : Unused code path elimination
 * Block '<S19>/Sum' : Unused code path elimination
 * Block '<S21>/Ron' : Unused code path elimination
 * Block '<S21>/Sum' : Unused code path elimination
 * Block '<S23>/Ron' : Unused code path elimination
 * Block '<S23>/Sum' : Unused code path elimination
 * Block '<S8>/Kv' : Unused code path elimination
 * Block '<S8>/Kv1' : Unused code path elimination
 * Block '<S28>/do not delete this gain' : Unused code path elimination
 * Block '<S29>/do not delete this gain' : Unused code path elimination
 * Block '<S30>/do not delete this gain' : Unused code path elimination
 * Block '<S31>/do not delete this gain' : Unused code path elimination
 * Block '<S32>/do not delete this gain' : Unused code path elimination
 * Block '<S33>/do not delete this gain' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Three_ph_controlled_Reectifired'
 * '<S1>'   : 'Three_ph_controlled_Reectifired/Multimeter'
 * '<S2>'   : 'Three_ph_controlled_Reectifired/T1'
 * '<S3>'   : 'Three_ph_controlled_Reectifired/T2'
 * '<S4>'   : 'Three_ph_controlled_Reectifired/T3'
 * '<S5>'   : 'Three_ph_controlled_Reectifired/T4'
 * '<S6>'   : 'Three_ph_controlled_Reectifired/T5'
 * '<S7>'   : 'Three_ph_controlled_Reectifired/T6'
 * '<S8>'   : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement'
 * '<S9>'   : 'Three_ph_controlled_Reectifired/Three-Phase Source'
 * '<S10>'  : 'Three_ph_controlled_Reectifired/powergui'
 * '<S11>'  : 'Three_ph_controlled_Reectifired/Multimeter/Model'
 * '<S12>'  : 'Three_ph_controlled_Reectifired/Multimeter/StoreData'
 * '<S13>'  : 'Three_ph_controlled_Reectifired/T1/Model'
 * '<S14>'  : 'Three_ph_controlled_Reectifired/T1/Model/Measurement list'
 * '<S15>'  : 'Three_ph_controlled_Reectifired/T2/Model'
 * '<S16>'  : 'Three_ph_controlled_Reectifired/T2/Model/Measurement list'
 * '<S17>'  : 'Three_ph_controlled_Reectifired/T3/Model'
 * '<S18>'  : 'Three_ph_controlled_Reectifired/T3/Model/Measurement list'
 * '<S19>'  : 'Three_ph_controlled_Reectifired/T4/Model'
 * '<S20>'  : 'Three_ph_controlled_Reectifired/T4/Model/Measurement list'
 * '<S21>'  : 'Three_ph_controlled_Reectifired/T5/Model'
 * '<S22>'  : 'Three_ph_controlled_Reectifired/T5/Model/Measurement list'
 * '<S23>'  : 'Three_ph_controlled_Reectifired/T6/Model'
 * '<S24>'  : 'Three_ph_controlled_Reectifired/T6/Model/Measurement list'
 * '<S25>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Mode I'
 * '<S26>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Mode V'
 * '<S27>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model'
 * '<S28>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I A:'
 * '<S29>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I B:'
 * '<S30>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I C:'
 * '<S31>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U A:'
 * '<S32>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U B:'
 * '<S33>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U C:'
 * '<S34>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I A:/Model'
 * '<S35>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I B:/Model'
 * '<S36>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/I C:/Model'
 * '<S37>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U A:/Model'
 * '<S38>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U B:/Model'
 * '<S39>'  : 'Three_ph_controlled_Reectifired/Three-Phase V-I Measurement/Model/U C:/Model'
 * '<S40>'  : 'Three_ph_controlled_Reectifired/Three-Phase Source/Model'
 * '<S41>'  : 'Three_ph_controlled_Reectifired/powergui/EquivalentModel1'
 * '<S42>'  : 'Three_ph_controlled_Reectifired/powergui/EquivalentModel1/Gates'
 * '<S43>'  : 'Three_ph_controlled_Reectifired/powergui/EquivalentModel1/Sources'
 * '<S44>'  : 'Three_ph_controlled_Reectifired/powergui/EquivalentModel1/Status'
 * '<S45>'  : 'Three_ph_controlled_Reectifired/powergui/EquivalentModel1/Yout'
 */
#endif                       /* RTW_HEADER_Three_ph_controlled_Reectifired_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
