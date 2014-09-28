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
    class Strain : DeviceBase
    {
        public:
        Strain();
        Strain(int pin);
        Strain(int pin, Timing::Duration bounceTime);
        Strain(int pin, unsigned int resolution);
        Strain(int pin, Timing::Duration bounceTime, unsigned int resolution);

        unsigned int averageValue();
        unsigned int baseline();
        void baseline(unsigned int baseline);


        private:
        //Set the baseline nothing will be registered below this
        unsigned int baseline_;
        unsigned int resolution_;
    };
}
