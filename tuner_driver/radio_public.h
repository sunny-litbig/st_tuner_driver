//****************************************************************************************************************
//
// File name   :	radio_public.h  
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


#ifndef H_RADIO_PUBLIC_H
#define H_RADIO_PUBLIC_H

/*  Radio general definations  */
#ifndef	TRUE
#define TRUE        1
#endif

#ifndef FALSE
#define FALSE       0
#endif

#ifndef NULL
#define NULL        0
#endif

#ifndef INVALID
#define INVALID     0xFF
#endif


/* types general definations,  may need moved common header file */
typedef unsigned char       tU8;
typedef signed char         tS8;
typedef unsigned short      tU16;
typedef unsigned int        tU32;
typedef unsigned char       tBool;

// Error definations
typedef enum
{
	RET_SUCCESS               	= 0x0,	/* No error */
	RET_ERROR                   	,	/* Generic error */

	RET_ERR_CMD_ID 		,	/* Command ID error */
	RET_ERR_CMD_CHECKSUM ,	/* Command checksum error */
	RET_ERR_CMD_COLLISION ,	/* Command collision */
	RET_ERR_CMD_ANWSER_CHECKSUM ,	/* Command answer checksum error */
	RET_ERR_NO_DATA ,
	RET_ERR_PARMETER		,	/* Function parameter error */
	RET_ERR_TIME_OUT		,  	/* For time out case */
	RET_ERR_BOOTCODE		,	/* tuner bootcode download error */
	RET_ERR_SYS_FAILURE 	,	/* System failure, need reboot */
	RET_ERR_BUSY,
	
	RET_ERR_MAX_NUM
} Tun_Status;

#endif /* H_RADIO_PUBLIC_H */



