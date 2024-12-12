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

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_RESET
#define BTN_A_HOVER		GPIO_PIN_SET

#define BTN_B_PIN		D2_Pin
#define BTN_B_PORT		D2_GPIO_Port
#define BTN_B_PRESSED	GPIO_PIN_RESET
#define BTN_B_HOVER		GPIO_PIN_SET

#define BTN_C_PIN		D4_Pin
#define BTN_C_PORT		D4_GPIO_Port
#define BTN_C_PRESSED	GPIO_PIN_RESET
#define BTN_C_HOVER		GPIO_PIN_SET

#define BTN_D_PIN		D5_Pin
#define BTN_D_PORT		D5_GPIO_Port
#define BTN_D_PRESSED	GPIO_PIN_RESET
#define BTN_D_HOVER		GPIO_PIN_SET

#define BTN_E_PIN		D7_Pin
#define BTN_E_PORT		D7_GPIO_Port
#define BTN_E_PRESSED	GPIO_PIN_RESET
#define BTN_E_HOVER		GPIO_PIN_SET

#define BTN_F_PIN		D8_Pin
#define BTN_F_PORT		D8_GPIO_Port
#define BTN_F_PRESSED	GPIO_PIN_RESET
#define BTN_F_HOVER		GPIO_PIN_SET

#define BTN_G_PIN		D9_Pin
#define BTN_G_PORT		D9_GPIO_Port
#define BTN_G_PRESSED	GPIO_PIN_RESET
#define BTN_G_HOVER		GPIO_PIN_SET

#define LED_A_PIN		LD2_Pin
#define LED_A_PORT		LD2_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#define LED_B_PIN		A0_Pin
#define LED_B_PORT		A0_GPIO_Port
#define LED_B_ON		GPIO_PIN_SET
#define LED_B_OFF		GPIO_PIN_RESET

#define LED_C_PIN		A1_Pin
#define LED_C_PORT		A1_GPIO_Port
#define LED_C_ON		GPIO_PIN_SET
#define LED_C_OFF		GPIO_PIN_RESET

#define LED_D_PIN		D6_Pin
#define LED_D_PORT		D6_GPIO_Port
#define LED_D_ON		GPIO_PIN_SET
#define LED_D_OFF		GPIO_PIN_RESET

#define LED_E_PIN		D10_Pin
#define LED_E_PORT		D10_GPIO_Port
#define LED_E_ON		GPIO_PIN_SET
#define LED_E_OFF		GPIO_PIN_RESET

#define LED_F_PIN		D14_Pin
#define LED_F_PORT		D14_GPIO_Port
#define LED_F_ON		GPIO_PIN_SET
#define LED_F_OFF		GPIO_PIN_RESET

#define LED_G_PIN		D15_Pin
#define LED_G_PORT		D15_GPIO_Port
#define LED_G_ON		GPIO_PIN_SET
#define LED_G_OFF		GPIO_PIN_RESET




#endif/* STM32 Nucleo Boards - 144 Pins */

#if ((BOARD == NUCLEO_F429ZI) || (BOARD == NUCLEO_F439ZI) || (BOARD == NUCLEO_F413ZH))

#define BTN_A_PIN		USER_Btn_Pin
#define BTN_A_PORT		USER_Btn_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD1_Pin
#define LED_A_PORT		LD1_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#endif

/* STM32 Discovery Kits */
#if (BOARD == STM32F429I_DISCO1)

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD3_Pin
#define LED_A_PORT		LD3_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

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