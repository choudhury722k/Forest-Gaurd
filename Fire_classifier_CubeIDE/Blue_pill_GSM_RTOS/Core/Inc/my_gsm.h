/*
 * my_gsm.h
 *
 *  Created on: 06-Jun-2023
 *      Author: SOUMYA
 */

#ifndef INC_MY_GSM_H_
#define INC_MY_GSM_H_

#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _ENABLE_RTOS                    0
#define _GSM_DEBUG                      1       //  use printf debug

#define _GSM_MAIN_POWER                 1       //  control gsm main power
#define _GSM_SIM_DETECTOR               1       //  use this feature when the SIM card holder has the ability to detect the SIM card
#define _GSM_CALL                       0       //  enable call
#define _GSM_MSG                        1       //  enable message
#define _GSM_GPRS                       1       //  enable gprs
#define _GSM_BLUETOOTH                  0       //  enable bluetooth , coming soon

#if (_GSM_DEBUG == 1)
#define gsm_printf(...)     printf(__VA_ARGS__)
#else
#define gsm_printf(...)     {};
#endif

#if (_ENABLE_RTOS == 0)
#define gsm_delay(x)  HAL_Delay(x)
#else
#include "cmsis_os.h"
#define gsm_delay(x)  osDelay(x)
#endif


bool            gsm_init(void);

#endif /* INC_MY_GSM_H_ */
