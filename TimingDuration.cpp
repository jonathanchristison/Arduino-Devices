/*
  Duration.cpp - Arduino-Devices, a library to provide a easy to use
  abstractions of common electronic devices

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

/*
 * This file has been taken and modified from the community edition of opensplice
 * which is released under the LGPL the full project can be found at
 * https://github.com/PrismTech/opensplice and http://www.prismtech.com/
 */

#include "TimingDuration.hpp"
#define MS 1000
#define MiS 1000000
#define NS 1000000000


Timing::Duration::Duration()
    :  sec_(0),
       nsec_(0)
{ }

Timing::Duration::Duration(uint32_t s, uint32_t ns)
{
    sec(s);
    nanosec(ns);
}

uint32_t Timing::Duration::sec() const
{
    return sec_;
}

void Timing::Duration::sec(uint32_t s)
{
    sec_ = static_cast<int32_t>(s);
}

void Timing::Duration::nanosec(uint32_t ns)
{
    nsec_ = ns;
}

const Timing::Duration Timing::Duration::from_microsecs(uint32_t microseconds)
{
    return Duration(microseconds / MiS, static_cast<uint32_t>((microseconds % MiS) * MS));
}

const Timing::Duration Timing::Duration::from_millisecs(uint32_t milliseconds)
{
    return Duration(milliseconds / MS, static_cast<uint32_t>((milliseconds % MS) * MiS));
}

const Timing::Duration Timing::Duration::from_secs(double seconds)
{
    uint32_t int_secs =  static_cast<uint32_t>(seconds);
    uint32_t nanos = static_cast<uint32_t>((seconds - int_secs) * NS);
    return Duration(int_secs, nanos);
}

uint32_t Timing::Duration::nanosec() const
{
    return nsec_;
}

int Timing::Duration::compare(const Duration& that) const
{
    int ret;

    if(sec_ >= that.sec_ && (sec_ > that.sec_ || nsec_ > that.nsec_))
    {
        ret = 1;
    }
    else if(sec_ <= that.sec_ && (sec_ < that.sec_ || nsec_ < that.nsec_))
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

uint32_t Timing::Duration::to_millisecs() const
{
    return (static_cast<uint32_t>(sec_) * MS) + (nsec_ / MiS);
}

uint32_t Timing::Duration::to_microsecs() const
{
    return (static_cast<uint32_t>(sec_) * MiS) + (nsec_ / MS);
}


double Timing::Duration::to_secs() const
{
    return static_cast<double>(sec_) + (static_cast<double>(nsec_) / NS);
}

bool
Timing::Duration::operator >(const Duration& that) const
{
    return sec_ >= that.sec_ && (sec_ > that.sec_ || nsec_ > that.nsec_);
}

bool
Timing::Duration::operator >=(const Duration& that) const
{
    return sec_ >= that.sec_ && nsec_ >= that.nsec_;
}

bool
Timing::Duration::operator ==(const Duration& that) const
{
    return sec_ == that.sec_ && nsec_ == that.nsec_;
}

bool
Timing::Duration::operator <=(const Duration& that) const
{
    return sec_ <= that.sec_ && nsec_ <= that.nsec_;
}

bool
Timing::Duration::operator <(const Duration& that) const
{
    return sec_ <= that.sec_ && (sec_ < that.sec_ || nsec_ < that.nsec_);
}

Timing::Duration&
Timing::Duration::operator +=(const Duration& a_ti)
{
    sec_ += static_cast<int32_t>(a_ti.sec());
    uint32_t dns = nsec_ + a_ti.nanosec();
    if(dns > NS)
    {
        sec_++;
        nsec_ = dns % NS;
    }
    else
    {
        nsec_ = dns;
    }
    return *this;
}

Timing::Duration&
Timing::Duration::operator -=(const Duration& a_ti)
{
    Timing::Duration tmp(sec_ - a_ti.sec(), 0);
    uint32_t dns = a_ti.nanosec();
    uint32_t tmpNS;
    if(nsec_ < dns)
    {
        tmp.sec(tmp.sec() - 1);
        tmpNS = nsec_ + NS - dns;
    }
    else
    {
        tmpNS = nsec_ - dns;
    }
    tmp.nanosec(tmpNS);
    this->nanosec(tmp.nanosec());
    this->sec(tmp.sec());

    return *this;
}

const Timing::Duration Timing::Duration::operator +(const Duration& other) const
{
    return(Duration(sec_, nsec_) += other);
}

const Timing::Duration Timing::Duration::operator -(const Duration& other) const
{
    return (Duration(sec_, nsec_) -= other);
}

Timing::Duration&
Timing::Duration::operator *=(uint32_t factor)
{
    this->sec(this->sec_ * factor);
    uint32_t ns = this->nanosec() * factor;
    if(ns  > NS)
    {
        this->sec(this->sec_ + ns / NS);
        /* cast below is safe because ns % NS is always < NS which is 32 bit */
        this->nanosec(static_cast<uint32_t>(ns % NS));
    }
    else
    {
        /* cast below is safe necause ns < NS in this clause */
        this->nanosec(static_cast<uint32_t>(ns));
    }
    return *this;
}

const Timing::Duration operator *(uint32_t lhs, const Timing::Duration& rhs)
{
    return Timing::Duration(rhs.sec(), rhs.nanosec()) *= lhs;
}

const Timing::Duration operator *(const Timing::Duration& lhs, uint32_t rhs)
{
    return Timing::Duration(lhs.sec(), lhs.nanosec()) *= rhs;
}

const Timing::Duration operator /(const Timing::Duration& rhs, uint32_t lhs)
{
    return Timing::Duration((rhs.sec() / lhs), (rhs.nanosec() / static_cast<uint32_t>(lhs)));
}

const Timing::Duration
Timing::Duration::infinite()
{
    static Duration d(0x7fffffff, 0x7fffffff);
    return d;
}

const Timing::Duration
Timing::Duration::zero()
{
    static Duration d(0, 0);
    return d;
}
