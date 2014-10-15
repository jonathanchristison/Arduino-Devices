/*
  $filename - Arduino-Devices, a library to provide a easy to use
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
#ifndef TIME_HPP
#define TIME_HPP
#include "Commoninc.hpp"
#include "Timing.hpp"
#include "TimingBase.hpp"

namespace Timing
{
    class Time;
}

namespace Timing
{
class Time : public TimingBase<Time>
{
public:
    Time()
    {
        start_ = micros();
    }
    uint32_t nanosec() const
    {
        this->tick();
        return nsec_;
    }
    uint32_t sec() const
    {
        this->tick();
        return sec_;
    }

    void tick()
    {
        this = satic_cast<Time> Timing::Duration::from_microsecs(micros() - start_);
    }

    /**
     * Add a Time to this Time
     *
     * @param a_ti Time to add
     * @return this Time + a_ti
     */
    Time& operator+=(const Time& a_ti);

    /**
     * Subtract a Time from this Time
     *
     * @param a_ti Time to subtract
     * @return this Time - a_ti
     */
    Time& operator-=(const Time& a_ti);

    /**
     * Multiply this Time by a factor
     *
     * @param factor the factor to multiply this Time by
     * @return this Time * factor
     */
    Time& operator*=(uint32_t factor);

    /**
     * Add a Time to Time
     *
     * @param other a Time
     * @return Time + other
     */
    const Time operator +(const Time& other) const;

    /**
     * Subtract a Time from Time
     *
     * @param other a Time
     * @return the Time - other
     */
    const Time operator -(const Time& other) const;

private:
    const unsigned long start_;
};

bool operator == (const Timing::Time& lhs, const Timing::Duration& rhs)
{
    return lhs->sec() == rhs->sec() && lhs->nanosec() == rhs->nanosec() ? true : false;
}
bool operator >= (const Timing::Time& lhs, const Timing::Duration& rhs)
{
    return lhs->sec() >= rhs->sec() && lhs->nanosec() >= rhs->nanosec() ? true : false;
}
bool operator > (const Timing::Time& lhs, const Timing::Duration& rhs)
{
    return lhs->sec() > rhs->sec() && lhs->nanosec() > rhs->nanosec() ? true : false;
}
bool operator < (const Timing::Time& lhs, const Timing::Duration& rhs)
{
    return lhs->sec() < rhs->sec() && lhs->nanosec() < rhs->nanosec() ? true : false;
}
#if 0
/**
 * Multiply Time by a factor
 *
 * @param lhs factor by which to multiply
 * @param rhs Time to multiply
 *
 * @return factor * Time
 */
const Time operator *(uuint32_t lhs,
                          const Time& rhs);

/**
 * Multiply Time by a factor
 *
 * @param lhs Time to multiply
 * @param rhs factor by which to multiply
 *
 * @return Time * factor
 */
const Time operator *(const Time& lhs,
                          uuint32_t rhs);

/**
 * Divide Time by a factor
 *
 * @param lhs Time to divide
 * @param rhs factor by which to divide
 */
const Time operator /(const Time& lhs,
                          uuint32_t rhs);

};
#endif
}
#endif
