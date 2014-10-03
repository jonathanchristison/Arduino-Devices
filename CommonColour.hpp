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
#ifndef COLOUR_HPP
#define COLOUR_HPP

#include "Commoninc.hpp"
#include <Printable.h>

#define WHITE 255U,255U,255U
#define OFF 0U,0U,0U

class Colour : public Printable
{
public:
    //None is the default
    Colour()
    {
        this->init(0U, 0U, 0U);
    }

    Colour(byte red, byte green, byte blue)
    {
        this->init(red, green, blue);
    }

    Colour energy(const uint16_t energy)
    {
        uint16_t e = energy;
        map(e, 0, 1023, 0, 765);
        byte r,g,b;
        r = g = b = 0;

        if( (e / 255) < 1)
        {
            r = e % 255;
        }
        else if( 1 == (e / 255) )
        {
            r = 255;
            g = e % 255;
        }
        else if( 2 == (e / 255))
        {
             r = 255;
             g = 255;
             b = e % 255;
        }
        else if( 3 == (e / 255))
        {
            r = 255;
            g = 255;
            b = 255;
        }

        return Colour(r, g, b);
    }
    void red(byte red)
    {
        red_ = red;
    }
    void green(byte green)
    {
        green_ = green;
    }
    void blue(byte blue)
    {
        blue_ = blue;
    }
    byte red()
    {
        return red_;
    }
    byte green()
    {
        return green_;
    }
    byte blue()
    {
        return blue_;
    }

    String hex()
    {
        String red(this->red(), HEX);
        String green(this->green(), HEX);
        String blue(this->blue(), HEX);
        return String(red + green + blue);
    }

    void hex(String hex)
    {
        hex.trim();
        unsigned long hl = strtoul(hex.c_str(), NULL, 16);
        if(hl > 16777215 || hex.length() < 1)
        {
            Serial.print(F("Invalid Colour Code:"));
            Serial.println("'" + hex + "'");
        }
        else
        {
            this->red((hl >> 16 & 0xFF));
            this->green((hl >> 8 & 0xFF));
            this->blue((hl & 0xFF));
        }
    }

    virtual size_t printTo(Print& p) const
    {
        size_t n = 0;
        n += p.print("R:\t");
        n += p.print(red_, DEC);
        n += p.print("\nG:\t");
        n += p.print(green_, DEC);
        n += p.print("\nB:\t");
        n += p.print(blue_, DEC);
        return n;
    }
private:
    void init(byte red, byte green, byte blue)
    {
        red_ = red;
        green_ = green;
        blue_ = blue;
    }
    byte red_;
    byte green_;
    byte blue_;
};
#endif
