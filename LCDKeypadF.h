/**
 * Copyright (c) Aug 31, 2015 Ivelin Yanev <qnev89@gmail.com>.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 * 
 */

#ifndef LCDKEYPADF_H_
#define LCDKEYPADF_H_

//External Library
#include <Arduino.h>
#include "LiquidCrystal.h"

/*--------------------------------------------------------------------------------------
 Defines. More info about hardware http://linksprite.com/wiki/index.php5?title=16_X_2_LCD_Keypad_Shield_for_Arduino
 --------------------------------------------------------------------------------------*/
/*
 Pins used by LCD & Keypad Shield:

 A0:  Buttons, analog input from voltage ladder
 D4:  LCD bit 4
 D5:  LCD bit 5
 D6:  LCD bit 6
 D7:  LCD bit 7
 D8:  LCD RS
 D9:  LCD E
 D10: LCD K Backlight (high = on, also has pullup high so default is on)

 ADC voltages for the 5 buttons on analog input pin A0:

 RIGHT:  0.00V :   0 @ 8bit ;   0 @ 10 bit
 UP:     0.71V :  36 @ 8bit ; 145 @ 10 bit
 DOWN:   1.61V :  82 @ 8bit ; 329 @ 10 bit
 LEFT:   2.47V : 126 @ 8bit ; 507 @ 10 bit
 SELECT: 3.62V : 185 @ 8bit ; 741 @ 10 bit
 */

// Pins in use
#define PIN_BUTTON_ADC  A0 // A0 is the button ADC input
#define PIN_LCD_b4      4  //
#define PIN_LCD_b5      5  //
#define PIN_LCD_b6      6  //
#define PIN_LCD_b7      7  //
#define PIN_LCD_RS      8  //
#define PIN_LCD_E       9  //
#define PIN_LCD_K       10 // D10 controls LCD backlight

// LCD Dimensions
#define LCD_COL    16
#define LCD_ROW    2
#define CHAR_SIZE  LCD_5x10DOTS // from LiquidCrystal.h

// ADC readings expected for the 5 buttons on the ADC input
#define BTN_RIGHT_ADC   0
#define BTN_UP_ADC      145
#define BTN_DOWN_ADC    329
#define BTN_LEFT_ADC    507
#define BTN_SELECT_ADC  742
#define BTN_NONE_ADC    1023
#define BTN_ADC_GAP     20

//return values
#define NONE    0
#define RIGHT   1
#define UP      2
#define DOWN    3
#define LEFT    4
#define SELECT  5

// Controlling BackLihgt
#define OFF  false
#define ON   true

#define PRESSED   true
#define RELEASED  false

/**
 *
 */
class LCDKeypadF: public LiquidCrystal {
public:
	/**
	 * Constructor.
	 */
	LCDKeypadF();

	/**
	 * Destructor.
	 */
	~LCDKeypadF();
	void begin();
	void setBackLight(boolean);
	void setBackLightFlash(unsigned int);
	void setButtonsState(boolean);
	boolean getButtonsState();
	uint8_t readButtons();

private:
	boolean _btn_state;
	uint8_t _btn_last;
};


#endif /* LCDKEYPADF_H_ */
