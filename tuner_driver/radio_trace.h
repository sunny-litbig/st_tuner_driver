//****************************************************************************************************************
//
// File name   :	radio_trace.h  
// Author	   :	SZ team
// Description :	ST RADIO reference application software header file
//
// Copyright (C) 2019-2020 STMicroelectronics - All Rights Reserved
//
// License terms: STMicroelectronics Proprietary in accordance with licensing
// terms accepted at time of software delivery 
// 
// THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
// INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// EVALUATION ONLY - NOT FOR USE IN PRODUCTION
//****************************************************************************************************************/


#ifndef H_RADIO_TRACE_H
#define H_RADIO_TRACE_H

/*The main switch for debug information printing out. */
#define RADIO_TRACE_ON

#ifdef RADIO_TRACE_ON

/* For star command protocol debugging, file(star_protol.c) */
//#define TRACE_STAR_CMD_PROTOCOL


/* For star driver debugging, file(star_driver.c) */
#define TRACE_STAR_DRIVER
#ifdef TRACE_STAR_DRIVER
/* STAR DRIVER DEBUG INFORM OPTIONS */
//#define TRACE_STAR_CMD_WRITE
//#define TRACE_STAR_CMD_CHANGE_BAND
//#define TRACE_STAR_CMD_TUNE
//#define TRACE_STAR_CMD_SEEK
//#define TRACE_STAR_CMD_PING
//#define TRACE_STAR_CMD_FM_STEREO_MODE
//#define TRACE_STAR_CMD_MUTE
//#define TRACE_STAR_CMD_SET_VPA
//#define TRACE_STAR_CMD_GET_RECEPTION_QUALITY
//#define TRACE_STAR_CMD_SET_BB_IF
//#define TRACE_STAR_CMD_CONF_BB_SAI
//#define TRACE_STAR_CMD_CONF_JESD204
//#define TRACE_STAR_CMD_RDS
//#define TRACE_STAR_TUN_WAIT_READY
//#define TRACE_STAR_TUN_GET_TUNER_BUSY_STATUS
//#define TRACE_STAR_TUN_GET_TUNEDFREQ
#endif


/* For radio timer debugging, file(radio_timer.c) */
//#define TRACE_TIMER


/* For radio fmam debugging, file(radio_fmam.c) */
#define TRACE_RADIO_FMAM
#ifdef TRACE_RADIO_FMAM
//#define TRACE_RADIO_FMAM_SEEK_PROCESS
//#define TRACE_RADIO_FMAM_AUTOSTORE_PROCESS
//#define TRACE_RADIO_FMAM_PRESETSCAN
//#define TRACE_RADIO_FMAM_TUNE_PRESET
//#define TRACE_RADIO_FMAM_TUNE_FREQ
//#define TRACE_RADIO_FMAM_STARTUP
//#define TRACE_RADIO_FMAM_CHANGE_BAND
//#define TRACE_RADIO_FMAM_MUTE
//#define TRACE_RADIO_FMAM_STEREO_ONOFF
//#define TRACE_RADIO_FMAM_TASK
//#define TRACE_RADIO_FMAM_OPEN_CLOSE
//#define TRACE_RADIO_FMAM_BG_SEEK_PROCESS
//#define TRACE_RADIO_FMAM_LEARN_PROCESS
//#define TRACE_RADIO_FMAM_DSP_STUCK
//#define TRACE_RADIO_FMAM_SHARED_BACKGROUND
#endif


/* For radio platform debugging, file(radio_platform.c) */
//#define TRACE_RADIO_PLATFORM


/* For radio manager debugging, file(radio_manager.c) */
#define TRACE_RADIO_MANAGER
#ifdef TRACE_RADIO_MANAGER
//#define TRACE_RADIO_POWER_UP_POWER_DOWN
//#define TRACE_RADIO_NOTIFICATION_FROM_FMAM
//#define TRACE_RADIO_MANAGER_TASK
//#define TRACE_RADIO_MESSAGE_QUEUE
#endif


/* For RDS information tracing. */
#define TRACE_RADIO_RDS
#ifdef TRACE_RADIO_RDS
//#define TRACE_RADIO_RDS_FETCHING
//#define TRACE_RADIO_RDS_APPSTATE

//#define TRACE_RADIO_RDS_DECODING
//#define TRACE_RADIO_RDS_DATA_EXTRACTGROP
//#define TRACE_RADIO_RDS_DATA_EXTRACTGROP_BLOCKB
//#define TRACE_RADIO_RDS_STATION_INFOR
//#define TRACE_RADIO_RDS_STRATEGY_AF_CHECK
//#define TRACE_RADIO_RDS_STRATEGY_TA
//#define TRACE_RADIO_RDS_STRATEGY_PI_SEEK
#endif


#if defined (DAB_ENABLE)

//#define TRACE_DCOP_DRIVER
//#define TRACE_DCOP_DRIVER_CMD
//#define TRACE_DCOP_DRIVER_AUTO_MSG
#define TRACE_RADIO_DAB

#ifdef TRACE_RADIO_DAB
//#define TRACE_RADIO_DAB_OPEN_CLOSE
//#define TRACE_RADIO_DAB_TASK
//#define TRACE_RADIO_NOTIFICATION_FROM_DAB

//#define TRACE_RADIO_DAB_TUNEFREQ_PROCESS
//#define TRACE_RADIO_DAB_SEEK_PROCESS
//#define TRACE_RADIO_DAB_LEARN_PROCESS
//#define TRACE_RADIO_DAB_RECFG_PROCESS
//#define TRACE_RADIO_DAB_BGSCAN_PROCESS

#endif
#endif


#define PRINTF(fmt, args...)  printf("%s(%d): %s, "#fmt"\n",__FILE__,__LINE__,__func__, ##args);
#else
#define PRINTF(fmt, args...)  
#endif


typedef struct 
{
	char Name[60];
} Key_Msg_Evt_State_IDName;

extern Key_Msg_Evt_State_IDName EventIDName[];
extern Key_Msg_Evt_State_IDName UIKeyMsgIDName[];
extern Key_Msg_Evt_State_IDName FMAMMsgIDName[];
extern Key_Msg_Evt_State_IDName RMWorkModeName[];
extern Key_Msg_Evt_State_IDName FMAMWorkModeName[];
extern Key_Msg_Evt_State_IDName PSWorkModeName[];
extern Key_Msg_Evt_State_IDName RetStatusName[];
extern Key_Msg_Evt_State_IDName BandModeName[];
extern Key_Msg_Evt_State_IDName AFCheckModeName[];

#if defined (DAB_ENABLE)
extern Key_Msg_Evt_State_IDName DABMsgIDName[];
extern Key_Msg_Evt_State_IDName DABWorkModeName[];
extern Key_Msg_Evt_State_IDName DABTuneFreqModeName[];
extern Key_Msg_Evt_State_IDName DABSeekModeName[];
extern Key_Msg_Evt_State_IDName DABLearnModeName[];
extern Key_Msg_Evt_State_IDName DABReconfigModeName[];
#if defined (DAB_BACKGROUND)
extern Key_Msg_Evt_State_IDName DABBGSCANModeName[];
#endif
#endif


#endif /* H_RADIO_TRACE_H */




