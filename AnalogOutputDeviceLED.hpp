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

#include "Commoninc.hpp"
#include "CommonColour.hpp"
#include "TimingDuration.hpp"

namespace AnalogOutputDevice
{
class LED
{
public:
    LED(int pinR, int pinG, int pinB);
    Colour colour();
    void colour(Colour);
    void fadeIn();
    void fadeOut();
    void fadeTime(Timing::Duration fadeTime);
    Timing::Duration fadeTime();
    void pulse(uint8_t pulsecount);
    void instant();

private:
    Colour cVal_;

    int pinR_;
    int pinG_;
    int pinB_;

    Timing::Duration fadeTime_;
};
}
