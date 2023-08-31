/*
 * File: Three_ph_controlled_Reectifired.c
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

#include "Three_ph_controlled_Reectifired.h"
#include "Three_ph_controlled_Reectifired_private.h"

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Projection for root system: '<Root>' */
void Three_ph_controlled_Reectifired_projection(void)
{
  /* Projection for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */
  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnProjection(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Three_ph_controlled_Reectifired_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Three_ph_controlled_Reectifired_step();
  Three_ph_controlled_Reectifired_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Three_ph_controlled_Reectifired_step();
  Three_ph_controlled_Reectifired_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  Three_ph_controlled_Reectifired_step();
  Three_ph_controlled_Reectifired_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Three_ph_controlled_Reectifired_step(void)
{
  real_T SineWaveA_tmp;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Sin: '<S40>/Sine Wave A' incorporates:
   *  Sin: '<S40>/Sine Wave B'
   *  Sin: '<S40>/Sine Wave C'
   */
  SineWaveA_tmp = 314.15926535897933 * rtM->Timing.t[0];

  /* Sin: '<S40>/Sine Wave A' */
  rtDW.SineWaveA = sin(SineWaveA_tmp) * 310.26870075253595;

  /* Sin: '<S40>/Sine Wave B' */
  rtDW.SineWaveB = sin(SineWaveA_tmp + -2.0943951023931953) * 310.26870075253595;

  /* Sin: '<S40>/Sine Wave C' */
  rtDW.SineWaveC = sin(SineWaveA_tmp + 2.0943951023931953) * 310.26870075253595;

  /* S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */

  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  if (rtmIsMajorTimeStep(rtM)) {
    /* DiscretePulseGenerator: '<Root>/Pulse T1' */
    rtDW.PulseT1 = ((rtDW.clockTickCounter < 18) && (rtDW.clockTickCounter >= 0));

    /* DiscretePulseGenerator: '<Root>/Pulse T1' */
    if (rtDW.clockTickCounter >= 179) {
      rtDW.clockTickCounter = 0;
    } else {
      rtDW.clockTickCounter++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse T2' */
    rtDW.PulseT2 = ((rtDW.clockTickCounter_n < 18) && (rtDW.clockTickCounter_n >=
      0));

    /* DiscretePulseGenerator: '<Root>/Pulse T2' */
    if (rtDW.clockTickCounter_n >= 179) {
      rtDW.clockTickCounter_n = 0;
    } else {
      rtDW.clockTickCounter_n++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse T3' */
    rtDW.PulseT3 = ((rtDW.clockTickCounter_h < 18) && (rtDW.clockTickCounter_h >=
      0));

    /* DiscretePulseGenerator: '<Root>/Pulse T3' */
    if (rtDW.clockTickCounter_h >= 179) {
      rtDW.clockTickCounter_h = 0;
    } else {
      rtDW.clockTickCounter_h++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse T4' */
    rtDW.PulseT4 = ((rtDW.clockTickCounter_g < 18) && (rtDW.clockTickCounter_g >=
      0));

    /* DiscretePulseGenerator: '<Root>/Pulse T4' */
    if (rtDW.clockTickCounter_g >= 179) {
      rtDW.clockTickCounter_g = 0;
    } else {
      rtDW.clockTickCounter_g++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse T5' */
    rtDW.PulseT5 = ((rtDW.clockTickCounter_m < 18) && (rtDW.clockTickCounter_m >=
      0));

    /* DiscretePulseGenerator: '<Root>/Pulse T5' */
    if (rtDW.clockTickCounter_m >= 179) {
      rtDW.clockTickCounter_m = 0;
    } else {
      rtDW.clockTickCounter_m++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse T6' */
    rtDW.PulseT6 = ((rtDW.clockTickCounter_g3 < 18) && (rtDW.clockTickCounter_g3
      >= 0));

    /* DiscretePulseGenerator: '<Root>/Pulse T6' */
    if (rtDW.clockTickCounter_g3 >= 179) {
      rtDW.clockTickCounter_g3 = 0;
    } else {
      rtDW.clockTickCounter_g3++;
    }
  }

  if (rtmIsMajorTimeStep(rtM)) {
    /* Update for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
     *  Constant: '<S13>/ddd'
     *  Constant: '<S15>/ddd'
     *  Constant: '<S17>/ddd'
     *  Constant: '<S19>/ddd'
     *  Constant: '<S21>/ddd'
     *  Constant: '<S23>/ddd'
     */
    /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = rtM->childSfunctions[0];
      sfcnUpdate(rts,0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.00011111111111111112s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.00011111111111111112, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Three_ph_controlled_Reectifired_derivatives(void)
{
  /* Derivatives for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */
  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    real_T *sfcndX_fx = (real_T *) &((XDot *) rtM->derivs)->StateSpace_CSTATE[0];
    ssSetdX(rts, sfcndX_fx);
    sfcnDerivatives(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model initialize function */
void Three_ph_controlled_Reectifired_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtM->solverInfoPtr = (&rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rtM->Timing.sampleTimes = (&rtM->Timing.sampleTimesArray[0]);
    rtM->Timing.offsetTimes = (&rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    rtM->Timing.sampleTimes[0] = (0.0);
    rtM->Timing.sampleTimes[1] = (0.00011111111111111112);

    /* task offsets */
    rtM->Timing.offsetTimes[0] = (0.0);
    rtM->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.00011111111111111112;
  rtM->solverInfoPtr = (&rtM->solverInfo);
  rtM->Timing.stepSize = (0.00011111111111111112);
  rtsiSetFixedStepSize(&rtM->solverInfo, 0.00011111111111111112);
  rtsiSetSolverMode(&rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rtM->NonInlinedSFcns.sfcnInfo;
    rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rtM->Sizes.numSampTimes);
    rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(rtM)[0]);
    rtM->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(rtM)[1]);
    rtssSetTPtrPtr(sfcnInfo,rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(rtM));
    rtssSetStepSizePtr(sfcnInfo, &rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &rtM->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rtM->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &rtM->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rtM->solverInfoPtr);
  }

  rtM->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&rtM->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    rtM->childSfunctions = (&rtM->NonInlinedSFcns.childSFunctionPtrs[0]);
    rtM->childSfunctions[0] = (&rtM->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: Three_ph_controlled_Reectifired/<S41>/State-Space (sfun_spid_contc) */
    {
      SimStruct *rts = rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &rtM->
        NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &rtM->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &rtM->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts, &rtM->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rtM->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &rtDW.SineWaveA;
          sfcnUPtrs[1] = &rtDW.SineWaveB;
          sfcnUPtrs[2] = &rtDW.SineWaveC;
          sfcnUPtrs[3] = &rtConstP.pooled1;
          sfcnUPtrs[4] = &rtConstP.pooled1;
          sfcnUPtrs[5] = &rtConstP.pooled1;
          sfcnUPtrs[6] = &rtConstP.pooled1;
          sfcnUPtrs[7] = &rtConstP.pooled1;
          sfcnUPtrs[8] = &rtConstP.pooled1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rtM->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &rtDW.PulseT1;
          sfcnUPtrs[1] = &rtDW.PulseT2;
          sfcnUPtrs[2] = &rtDW.PulseT3;
          sfcnUPtrs[3] = &rtDW.PulseT4;
          sfcnUPtrs[4] = &rtDW.PulseT5;
          sfcnUPtrs[5] = &rtDW.PulseT6;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 6);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts, &rtM->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 7);
          ssSetOutputPortSignal(rts, 0, ((real_T *) rtDW.StateSpace_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 12);
          ssSetOutputPortSignal(rts, 1, ((real_T *) rtDW.StateSpace_o2));
        }
      }

      /* states */
      ssSetContStates(rts, &rtX.StateSpace_CSTATE[0]);

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts,
                "Three_ph_controlled_Reectifired/powergui/EquivalentModel1/State-Space");
      ssSetRTModel(rts,rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtConstP.StateSpace_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtConstP.StateSpace_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtConstP.StateSpace_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtConstP.StateSpace_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)rtConstP.StateSpace_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)rtConstP.StateSpace_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)rtConstP.StateSpace_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)rtConstP.StateSpace_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)rtConstP.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)rtConstP.StateSpace_P10_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &rtDW.StateSpace_RWORK[0]);
      ssSetIWork(rts, (int_T *) &rtDW.StateSpace_IWORK[0]);
      ssSetPWork(rts, (void **) &rtDW.StateSpace_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 4);

        /* MODE */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDW.StateSpace_MODE[0]);

        /* RWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rtDW.StateSpace_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 2, 23);
        ssSetDWorkDataType(rts, 2,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &rtDW.StateSpace_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 3, 22);
        ssSetDWorkDataType(rts, 3,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &rtDW.StateSpace_PWORK[0]);
      }

      ssSetModeVector(rts, (int_T *) &rtDW.StateSpace_MODE[0]);

      /* registration */
      sfun_spid_contc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Start for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */
  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T1' */
  rtDW.clockTickCounter = -5;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T2' */
  rtDW.clockTickCounter_n = -95;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T3' */
  rtDW.clockTickCounter_h = -65;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T4' */
  rtDW.clockTickCounter_g = -155;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T5' */
  rtDW.clockTickCounter_m = -124;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse T6' */
  rtDW.clockTickCounter_g3 = -35;

  /* InitializeConditions for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */
  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void Three_ph_controlled_Reectifired_terminate(void)
{
  /* Terminate for S-Function (sfun_spid_contc): '<S41>/State-Space' incorporates:
   *  Constant: '<S13>/ddd'
   *  Constant: '<S15>/ddd'
   *  Constant: '<S17>/ddd'
   *  Constant: '<S19>/ddd'
   *  Constant: '<S21>/ddd'
   *  Constant: '<S23>/ddd'
   */
  /* Level2 S-Function Block: '<S41>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
