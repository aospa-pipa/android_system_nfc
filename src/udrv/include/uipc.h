/******************************************************************************
 *
 *  Copyright (C) 2007-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  UIPC wrapper interface
 *
 ******************************************************************************/
#ifndef UIPC_H
#define UIPC_H

#ifndef UDRV_API
#define UDRV_API
#endif


#define UIPC_CH_ID_ALL  0   /* used to address all the ch id at once */
#define UIPC_CH_ID_0    1   /* shared mem interface */
#define UIPC_CH_ID_1    2   /* TCP socket (GPS) */
#define UIPC_CH_ID_2    3   /* BTIF control socket */
#define UIPC_CH_ID_3    4   /* BTIF HH */
#define UIPC_CH_ID_4    5   /* Future usage */
#define UIPC_CH_ID_5    6   /* Future usage */
#define UIPC_CH_ID_6    7   /* Future usage */
#define UIPC_CH_ID_7    8   /* Future usage */
#define UIPC_CH_ID_8    9   /* Future usage */
#define UIPC_CH_ID_9    10  /* Future usage */
#define UIPC_CH_ID_10   11  /* Future usage */
#define UIPC_CH_ID_11   12  /* Future usage */
#define UIPC_CH_ID_12   13  /* Future usage */
#define UIPC_CH_ID_13   14  /* Future usage */
#define UIPC_CH_ID_14   15  /* Future usage */
#define UIPC_CH_ID_15   16  /* Future usage */
#define UIPC_CH_ID_16   17  /* Future usage */
#define UIPC_CH_ID_17   18  /* Future usage */
#define UIPC_CH_ID_18   19  /* Future usage */
#define UIPC_CH_ID_19   20  /* Future usage */
#define UIPC_CH_ID_20   21  /* Future usage */
#define UIPC_CH_ID_21   22  /* Future usage */
#define UIPC_CH_ID_22   23  /* Future usage */
#define UIPC_CH_ID_23   24  /* Future usage */
#define UIPC_CH_ID_24   25  /* Future usage */



#define UIPC_CH_NUM 25

typedef uint8_t tUIPC_CH_ID;


typedef void (tUIPC_RCV_CBACK)(NFC_HDR *p_msg); /* points to NFC_HDR which describes event type and length of data; len contains the number of bytes of entire message (sizeof(NFC_HDR) + offset + size of data) */

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
**
** Function         UIPC_Init
**
** Description      Initialize UIPC module
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern void UIPC_Init(void *);

/*******************************************************************************
**
** Function         UIPC_Open
**
** Description      Open UIPC interface
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern bool    UIPC_Open(tUIPC_CH_ID ch_id, tUIPC_RCV_CBACK *p_cback);

/*******************************************************************************
**
** Function         UIPC_Close
**
** Description      Close UIPC interface
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern void UIPC_Close(tUIPC_CH_ID ch_id);

/*******************************************************************************
**
** Function         UIPC_SendBuf
**
** Description      Called to transmit a message over UIPC.
**                  Message buffer will be freed by UIPC_SendBuf.
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern bool    UIPC_SendBuf(tUIPC_CH_ID ch_id, NFC_HDR *p_msg);

/*******************************************************************************
**
** Function         UIPC_Send
**
** Description      Called to transmit a message over UIPC.
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern bool    UIPC_Send(tUIPC_CH_ID ch_id, uint16_t msg_evt, uint8_t *p_buf, uint16_t msglen);

/*******************************************************************************
**
** Function         UIPC_Read
**
** Description      Called to read a message from UIPC.
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern uint32_t UIPC_Read(tUIPC_CH_ID ch_id, uint16_t *p_msg_evt, uint8_t *p_buf, uint32_t len);

/*******************************************************************************
**
** Function         UIPC_Ioctl
**
** Description      Called to control UIPC.
**
** Returns          void
**
*******************************************************************************/
UDRV_API extern bool    UIPC_Ioctl(tUIPC_CH_ID ch_id, uint32_t request, void *param);

#ifdef __cplusplus
}
#endif


#endif  /* UIPC_H */


