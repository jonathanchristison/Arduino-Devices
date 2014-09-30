/*
  $filename - Arduino-Devices, a library to provide a easy to use
  abstractions of common electronic devices

  Tinam Limited, hereby disclaims all copyright interest in the
  library "Arduino-Devices" written by Jonathan Christison

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "AnalogOutputDeviceLED.hpp"

namespace AnalogOutputDevice
{
LED::LED(int pinR, int pinG, int pinB)
{
    pinR_ = pinR;
    pinG_ = pinG;
    pinB_ = pinB;
}

void LED::colour(Colour cval)
{
	cVal_ = cval;
}

Colour LED::colour()
{
    return cVal_;
}

void LED::fadeIn()
{
		for(int fadeValue = 0; fadeValue < 255; fadeValue++)
		{
			if(fadeValue < cVal_.red())
				analogWrite(pinR_, fadeValue);
			if(fadeValue < cVal_.green())
				analogWrite(pinG_, fadeValue);
			if(fadeValue < cVal_.blue())
				analogWrite(pinB_, fadeValue);

			delayMicroseconds(fadeTime_.to_microsecs());
		}
}

void LED::fadeOut()
{
		for(int fadeValue = 255; fadeValue > -1; fadeValue--)
		{
			if(cVal_.red() > fadeValue)
				analogWrite(pinR_, fadeValue);
			if(cVal_.green() > fadeValue)
				analogWrite(pinG_, fadeValue);
			if(cVal_.blue() > fadeValue)
				analogWrite(pinB_, fadeValue);

			delayMicroseconds(fadeTime_.to_microsecs());
		}

}

void LED::pulse(uint8_t pulsecount)
{
	Timing::Duration ft = this->fadeTime();
	this->fadeTime(Timing::Duration::from_millisecs(2));
	do
	{
		this->fadeIn();
		this->fadeOut();
		pulsecount--;
	}while(pulsecount > 0);
    this->fadeTime(ft);
}

void LED::fadeTime(Timing::Duration fadeTime)
{
	fadeTime_ = fadeTime;
}

Timing::Duration LED::fadeTime()
{
	return fadeTime_;
}

void LED::instant()
{
    analogWrite(pinR_, cVal_.red());
    analogWrite(pinG_, cVal_.green());
    analogWrite(pinB_, cVal_.blue());
}
}
