/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file   : board.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef BOARD_INC_BOARD_H_
#define BOARD_INC_BOARD_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/
#define NUCLEO_F103RC		(0)
#define NUCLEO_F401RE		(1)
#define NUCLEO_F446RE		(2)
#define NUCLEO_F429ZI		(3)
#define NUCLEO_F439ZI		(4)
#define NUCLEO_F413ZH		(5)
#define STM32F429I_DISCO1	(6)

#define BOARD (NUCLEO_F103RC)

/* STM32 Nucleo Boards - 64 Pins */
#if ((BOARD == NUCLEO_F103RC) || (BOARD == NUCLEO_F401RE) || (BOARD == NUCLEO_F446RE))

#define BTN_PACK_IN_PIN					B2_Pin
#define BTN_PACK_IN_PORT				B2_GPIO_Port
#define BTN_PACK_IN_PRESSED				GPIO_PIN_RESET
#define BTN_PACK_IN_HOVER				GPIO_PIN_SET

#define BTN_PACK_OUT_PIN				B3_Pin
#define BTN_PACK_OUT_PORT				B3_GPIO_Port
#define BTN_PACK_OUT_PRESSED			GPIO_PIN_RESET
#define BTN_PACK_OUT_HOVER				GPIO_PIN_SET

#define DIP_NORMAL_OR_SETUP_PIN			B4_Pin
#define DIP_NORMAL_OR_SETUP_PORT		B4_GPIO_Port
#define DIP_NORMAL_OR_SETUP_PRESSED		GPIO_PIN_RESET
#define DIP_NORMAL_OR_SETUP_HOVER		GPIO_PIN_SET

#define DIP_INFRARED_PIN				B5_Pin
#define DIP_INFRARED_PORT				B5_GPIO_Port
#define DIP_INFRARED_PRESSED			GPIO_PIN_RESET
#define DIP_INFRARED_HOVER				GPIO_PIN_SET

#define DIP_CTRL_SYST_PIN				B6_Pin
#define DIP_CTRL_SYST_PORT				B6_GPIO_Port
#define DIP_CTRL_SYST_PRESSED			GPIO_PIN_RESET
#define DIP_CTRL_SYST_HOVER				GPIO_PIN_SET

#define BTN_SETUP_ENTER_PIN				D5_Pin
#define BTN_SETUP_ENTER_PORT			D5_GPIO_Port
#define BTN_SETUP_ENTER_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_ENTER_HOVER			GPIO_PIN_SET

#define BTN_SETUP_NEXT_PIN				D4_Pin
#define BTN_SETUP_NEXT_PORT				D4_GPIO_Port
#define BTN_SETUP_NEXT_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_NEXT_HOVER			GPIO_PIN_SET

#define BTN_SETUP_ESCAPE_PIN			D6_Pin
#define BTN_SETUP_ESCAPE_PORT			D6_GPIO_Port
#define BTN_SETUP_ESCAPE_PRESSED		GPIO_PIN_RESET
#define BTN_SETUP_ESCAPE_HOVER			GPIO_PIN_SET

#define LED_MAX_SPEED_PIN				L1_Pin
#define LED_MAX_SPEED_PORT				L1_GPIO_Port
#define LED_MAX_SPEED_ON				GPIO_PIN_SET
#define LED_MAX_SPEED_OFF				GPIO_PIN_RESET

#define LED_MIN_SPEED_PIN				L2_Pin
#define LED_MIN_SPEED_PORT				L2_GPIO_Port
#define LED_MIN_SPEED_ON				GPIO_PIN_SET
#define LED_MIN_SPEED_OFF				GPIO_PIN_RESET

#define LED_CTRL_SYST_PIN				L3_Pin
#define LED_CTRL_SYST_PORT				L3_GPIO_Port
#define LED_CTRL_SYST_ON				GPIO_PIN_SET
#define LED_CTRL_SYST_OFF				GPIO_PIN_RESET

#define BUZZER_PIN						BZ_Pin
#define BUZZER_PORT						BZ_GPIO_Port
#define BUZZER_ON						GPIO_PIN_SET
#define BUZZER_OFF						GPIO_PIN_RESET

#endif/* STM32 Nucleo Boards - 144 Pins */

#if ((BOARD == NUCLEO_F429ZI) || (BOARD == NUCLEO_F439ZI) || (BOARD == NUCLEO_F413ZH))

#define BTN_PACK_IN_PIN					B2_Pin
#define BTN_PACK_IN_PORT				B2_GPIO_Port
#define BTN_PACK_IN_PRESSED				GPIO_PIN_RESET
#define BTN_PACK_IN_HOVER				GPIO_PIN_SET

#define BTN_PACK_OUT_PIN				B3_Pin
#define BTN_PACK_OUT_PORT				B3_GPIO_Port
#define BTN_PACK_OUT_PRESSED			GPIO_PIN_RESET
#define BTN_PACK_OUT_HOVER				GPIO_PIN_SET

#define DIP_NORMAL_OR_SETUP_PIN			B4_Pin
#define DIP_NORMAL_OR_SETUP_PORT		B4_GPIO_Port
#define DIP_NORMAL_OR_SETUP_PRESSED		GPIO_PIN_RESET
#define DIP_NORMAL_OR_SETUP_HOVER		GPIO_PIN_SET

#define DIP_INFRARED_PIN				B5_Pin
#define DIP_INFRARED_PORT				B5_GPIO_Port
#define DIP_INFRARED_PRESSED			GPIO_PIN_RESET
#define DIP_INFRARED_HOVER				GPIO_PIN_SET

#define DIP_CTRL_SYST_PIN				B6_Pin
#define DIP_CTRL_SYST_PORT				B6_GPIO_Port
#define DIP_CTRL_SYST_PRESSED			GPIO_PIN_RESET
#define DIP_CTRL_SYST_HOVER				GPIO_PIN_SET

#define BTN_SETUP_ENTER_PIN				D5_Pin
#define BTN_SETUP_ENTER_PORT			D5_GPIO_Port
#define BTN_SETUP_ENTER_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_ENTER_HOVER			GPIO_PIN_SET

#define BTN_SETUP_NEXT_PIN				D4_Pin
#define BTN_SETUP_NEXT_PORT				D4_GPIO_Port
#define BTN_SETUP_NEXT_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_NEXT_HOVER			GPIO_PIN_SET

#define BTN_SETUP_ESCAPE_PIN			D6_Pin
#define BTN_SETUP_ESCAPE_PORT			D6_GPIO_Port
#define BTN_SETUP_ESCAPE_PRESSED		GPIO_PIN_RESET
#define BTN_SETUP_ESCAPE_HOVER			GPIO_PIN_SET

#define LED_MAX_SPEED_PIN				L1_Pin
#define LED_MAX_SPEED_PORT				L1_GPIO_Port
#define LED_MAX_SPEED_ON				GPIO_PIN_SET
#define LED_MAX_SPEED_OFF				GPIO_PIN_RESET

#define LED_MIN_SPEED_PIN				L2_Pin
#define LED_MIN_SPEED_PORT				L2_GPIO_Port
#define LED_MIN_SPEED_ON				GPIO_PIN_SET
#define LED_MIN_SPEED_OFF				GPIO_PIN_RESET

#define LED_CTRL_SYST_PIN				L3_Pin
#define LED_CTRL_SYST_PORT				L3_GPIO_Port
#define LED_CTRL_SYST_ON				GPIO_PIN_SET
#define LED_CTRL_SYST_OFF				GPIO_PIN_RESET

#define BUZZER_PIN						BZ_Pin
#define BUZZER_PORT						BZ_GPIO_Port
#define BUZZER_ON						GPIO_PIN_SET
#define BUZZER_OFF						GPIO_PIN_RESET

#endif

/* STM32 Discovery Kits */
#if (BOARD == STM32F429I_DISCO1)

#define BTN_PACK_IN_PIN					B2_Pin
#define BTN_PACK_IN_PORT				B2_GPIO_Port
#define BTN_PACK_IN_PRESSED				GPIO_PIN_RESET
#define BTN_PACK_IN_HOVER				GPIO_PIN_SET

#define BTN_PACK_OUT_PIN				B3_Pin
#define BTN_PACK_OUT_PORT				B3_GPIO_Port
#define BTN_PACK_OUT_PRESSED			GPIO_PIN_RESET
#define BTN_PACK_OUT_HOVER				GPIO_PIN_SET

#define DIP_NORMAL_OR_SETUP_PIN			B4_Pin
#define DIP_NORMAL_OR_SETUP_PORT		B4_GPIO_Port
#define DIP_NORMAL_OR_SETUP_PRESSED		GPIO_PIN_RESET
#define DIP_NORMAL_OR_SETUP_HOVER		GPIO_PIN_SET

#define DIP_INFRARED_PIN				B5_Pin
#define DIP_INFRARED_PORT				B5_GPIO_Port
#define DIP_INFRARED_PRESSED			GPIO_PIN_RESET
#define DIP_INFRARED_HOVER				GPIO_PIN_SET

#define DIP_CTRL_SYST_PIN				B6_Pin
#define DIP_CTRL_SYST_PORT				B6_GPIO_Port
#define DIP_CTRL_SYST_PRESSED			GPIO_PIN_RESET
#define DIP_CTRL_SYST_HOVER				GPIO_PIN_SET

#define BTN_SETUP_ENTER_PIN				D5_Pin
#define BTN_SETUP_ENTER_PORT			D5_GPIO_Port
#define BTN_SETUP_ENTER_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_ENTER_HOVER			GPIO_PIN_SET

#define BTN_SETUP_NEXT_PIN				D4_Pin
#define BTN_SETUP_NEXT_PORT				D4_GPIO_Port
#define BTN_SETUP_NEXT_PRESSED			GPIO_PIN_RESET
#define BTN_SETUP_NEXT_HOVER			GPIO_PIN_SET

#define BTN_SETUP_ESCAPE_PIN			D6_Pin
#define BTN_SETUP_ESCAPE_PORT			D6_GPIO_Port
#define BTN_SETUP_ESCAPE_PRESSED		GPIO_PIN_RESET
#define BTN_SETUP_ESCAPE_HOVER			GPIO_PIN_SET

#define LED_MAX_SPEED_PIN				L1_Pin
#define LED_MAX_SPEED_PORT				L1_GPIO_Port
#define LED_MAX_SPEED_ON				GPIO_PIN_SET
#define LED_MAX_SPEED_OFF				GPIO_PIN_RESET

#define LED_MIN_SPEED_PIN				L2_Pin
#define LED_MIN_SPEED_PORT				L2_GPIO_Port
#define LED_MIN_SPEED_ON				GPIO_PIN_SET
#define LED_MIN_SPEED_OFF				GPIO_PIN_RESET

#define LED_CTRL_SYST_PIN				L3_Pin
#define LED_CTRL_SYST_PORT				L3_GPIO_Port
#define LED_CTRL_SYST_ON				GPIO_PIN_SET
#define LED_CTRL_SYST_OFF				GPIO_PIN_RESET

#define BUZZER_PIN						BZ_Pin
#define BUZZER_PORT						BZ_GPIO_Port
#define BUZZER_ON						GPIO_PIN_SET
#define BUZZER_OFF						GPIO_PIN_RESET

#endif

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* BOARD_INC_BOARD_H_ */

/********************** end of file ******************************************/
