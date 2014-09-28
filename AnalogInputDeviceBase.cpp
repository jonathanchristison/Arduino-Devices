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

#include "AnalogInputDeviceBase.hpp"

namespace AnalogInputDevice
{

    DeviceBase::DeviceBase()
    {
        this->init(0, Timing::Duration::zero());
    }

    DeviceBase::DeviceBase(uint8_t pin)
    {
        this->init(pin, Timing::Duration::zero());
    }

    DeviceBase::DeviceBase(uint8_t pin, Timing::Duration delayBetweenReads)
    {
        this->init(pin, delayBetweenReads);
    }

    void DeviceBase::init(uint8_t pin, Timing::Duration delayBetweenReads)
    {
        pin_ = pin;
        delayBetweenReads_ = delayBetweenReads;
    }

    void DeviceBase::pin(uint8_t pin)
    {
        pin_ = pin;
    }

    void DeviceBase::delayBetweenReads(Timing::Duration delayBetweenReads)
    {
        delayBetweenReads_ = delayBetweenReads;
    }

    uint16_t DeviceBase::pin()
    {
        return pin_;
    }

    Timing::Duration DeviceBase::delayBetweenReads()
    {
        return delayBetweenReads_;
    }

    uint16_t DeviceBase::value()
    {
        return analogRead(this->pin());
    }

/*
 * void DeviceBase::value(int &array, int items)
    {
        for(int i = 0; i < items; i++)
        {
            array[i]* = this->value();
            delay(delayBetweenReads_.to_microsecs())
        }
    }
    */
}

