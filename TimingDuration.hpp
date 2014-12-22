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
#ifndef DURATION_HPP
#define DURATION_HPP
#include "Commoninc.hpp"
#include "Timing.hpp"
#include "TimingBase.hpp"

namespace Timing
{
class Duration;
}

namespace Timing
{
class Duration : public TimingBase<Duration>
{
public:
    static const Duration zero();       // {0, 0}
    static const Duration infinite();   // {0x7fffffff, 0x7fffffff}
    /**
     * Create a Duration elapsing zero seconds.
     */
    Duration();

    /**
     * Create a Duration elapsing a specific amount of time.
     */
    explicit Duration(uint32_t sec, uint32_t nanosec);

    uint32_t nanosec() const;

    uint32_t sec() const;

    /*
        static const Duration from_microsecs(uint32_t microseconds);
        static const Duration from_millisecs(uint32_t milliseconds);
        static const Duration from_secs(double seconds);
    */

    /**
     * Set number of seconds
     * @param s number of seconds
     */
    void    sec(uint32_t s);

    /**
     * Set number of nanoseconds
     * @param ns number of nanoseconds
     */
    void     nanosec(uint32_t ns);

    /**
     * Add a Duration to this Duration
     *
     * @param a_ti Duration to add
     * @return this Duration + a_ti
     */
    Duration& operator+=(const Duration& a_ti);

    /**
     * Subtract a Duration from this Duration
     *
     * @param a_ti Duration to subtract
     * @return this Duration - a_ti
     */
    Duration& operator-=(const Duration& a_ti);

    /**
     * Multiply this Duration by a factor
     *
     * @param factor the factor to multiply this Duration by
     * @return this Duration * factor
     */
    Duration& operator*=(uint32_t factor);

    /**
     * Add a Duration to Duration
     *
     * @param other a Duration
     * @return Duration + other
     */
    const Duration operator +(const Duration& other) const;

    /**
     * Subtract a Duration from Duration
     *
     * @param other a Duration
     * @return the Duration - other
     */
    const Duration operator -(const Duration& other) const;
};
#if 0
/**
 * Multiply Duration by a factor
 *
 * @param lhs factor by which to multiply
 * @param rhs Duration to multiply
 *
 * @return factor * Duration
 */
const Duration operator *(uuint32_t lhs,
                          const Duration& rhs);

/**
 * Multiply Duration by a factor
 *
 * @param lhs Duration to multiply
 * @param rhs factor by which to multiply
 *
 * @return Duration * factor
 */
const Duration operator *(const Duration& lhs,
                          uuint32_t rhs);

/**
 * Divide Duration by a factor
 *
 * @param lhs Duration to divide
 * @param rhs factor by which to divide
 */
const Duration operator /(const Duration& lhs,
                          uuint32_t rhs);

};
#endif
}
#endif
