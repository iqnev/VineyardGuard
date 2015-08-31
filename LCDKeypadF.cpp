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


#include <Arduino.h>
#include "LiquidCrystal.h"

// Local Headers
#include "LCDKeypadF.h"

/*
 CLASS LCD1602KeyPad
*/
LCDKeypadF::LCDKeypadF() : LiquidCrystal(PIN_LCD_RS, PIN_LCD_E, PIN_LCD_b4, PIN_LCD_b5, PIN_LCD_b6, PIN_LCD_b7)
{
	//button adc input
	pinMode( PIN_BUTTON_ADC, INPUT );
	digitalWrite( PIN_BUTTON_ADC, LOW );

	//lcd backlight control
	pinMode( PIN_LCD_K, OUTPUT );
	digitalWrite( PIN_LCD_K, HIGH );
}

// Destructor
LCDKeypadF::~LCDKeypadF()
{
	//do something here? (free(), delete()?)
}

// Initialization
void LCDKeypadF::begin()
{
	//set up the LCD number of columns, rows  and character size
	LiquidCrystal::begin( LCD_COL, LCD_ROW, CHAR_SIZE);

	//Initialice the cursor
	LiquidCrystal::setCursor( 0, 0 );

	//init privated
	_btn_state = RELEASED;
	_btn_last = NONE;
}

//
void LCDKeypadF::setBackLight(boolean onOff)
{
	digitalWrite( PIN_LCD_K, onOff );
}

//
void LCDKeypadF::setBackLightFlash(unsigned int delayTime)
{
	setBackLight(OFF);
	delay(delayTime);
	setBackLight(ON);
}

//
void LCDKeypadF::setButtonsState(boolean state)
{
	_btn_state = state;
}

//
boolean LCDKeypadF::getButtonsState()
{
	return _btn_state;
}

// Detect the button pressed and return the value
uint8_t LCDKeypadF::readButtons()
{
   unsigned int v; //0-1023 values
   uint8_t b = NONE;   // default return

   //read the button ADC pin voltage
   v = analogRead( PIN_BUTTON_ADC );

   //sense if the voltage falls within valid voltage windows
   if( v < ( BTN_RIGHT_ADC + BTN_ADC_GAP ) )
   {
      b = RIGHT;
   }
   else if( v <= ( BTN_UP_ADC + BTN_ADC_GAP ) )
   {
      b = UP;
   }
   else if( v <= ( BTN_DOWN_ADC + BTN_ADC_GAP ) )
   {
      b = DOWN;
   }
   else if( v <= ( BTN_LEFT_ADC + BTN_ADC_GAP ) )
   {
      b = LEFT;
   }
   else if( v <= ( BTN_SELECT_ADC + BTN_ADC_GAP ) )
   {
      b = SELECT;
   }

   //handle button flags for just pressed and just released events
   if( ( _btn_last == NONE ) && ( b != NONE ) )
   {
      _btn_state  = PRESSED;
   }
   if( ( _btn_last != NONE ) && ( b == NONE ) )
   {
      _btn_state  = RELEASED;
   }

   //save the latest button state
   _btn_last = b;

   return( b );
}

