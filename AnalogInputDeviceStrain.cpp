/*
  Strain.cpp - Arduino-Devices, a library to provide a easy to use
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

#include "AnalogInputDeviceStrain.hpp"

namespace AnalogInputDevice
{
    Strain::Strain(int pin)
        : DeviceBase(pin)
    {
        resolution_ = 200;
    }
    Strain::Strain(int pin, Timing::Duration bounceTime)
        : DeviceBase(pin, bounceTime)
    {
        resolution_ = 200;
    }
    Strain::Strain(int pin, unsigned int resolution)
        : DeviceBase(pin)
    {
        resolution_ = resolution;
    }

    Strain::Strain(int pin, Timing::Duration bounceTime, unsigned int resolution)
        : DeviceBase(pin, bounceTime)
    {
        resolution_ = resolution;
    }

    unsigned int Strain::averageValue()
    {
        Average<uint16_t> average(resolution_);
        for(int i = 0; i < resolution_; i++)
        {
            uint16_t val = this->value();
            if(val < this->baseline())
                val = 0;
            average.push(this->value());
            delayMicroseconds(this->delayBetweenReads().to_microsecs());
        }
        return average.mean();
    }

    void Strain::baseline(unsigned int baseline)
    {
        baseline_ = baseline;
    }

    unsigned int Strain::baseline()
    {
        return baseline_;
    }

    void Strain::resolution(unsigned int resolution)
    {
        resolution_ = resolution;
    }
    unsigned int Strain::resolution()
    {
        return resolution_;
    }
}
