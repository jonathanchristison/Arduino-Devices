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

namespace Timing
{
    class Duration
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


        /**
         * Create a Duration from a number of microseconds
         * @param microseconds number of microseconds
         */
        static const Duration from_microsecs(uint32_t microseconds);
        /**
         * Create a Duration from a number of milliseconds
         * @param miliseconds number of milliseconds
         */
        static const Duration from_millisecs(uint32_t milliseconds);
        /**
         * Create a Duration from a number of seconds
         * @param seconds number of seconds
         */
        static const Duration from_secs(double seconds);

        /**
         * @return number of seconds
         */
        uint32_t sec() const;
        /**
         * Set number of seconds
         * @param s number of seconds
         */
        void    sec(uint32_t s);

        /**
         * @return number of nanoseconds
         */
        uint32_t nanosec() const;
        /**
         * Set number of nanoseconds
         * @param ns number of nanoseconds
         */
        void     nanosec(uint32_t ns);

        /**
         * Returns an integer value for a comparison of two Durations:
         * 1 if this Duration is greater than the comparator (that)
         * -1 if the Duration is less than the comparator (that)
         * 0 if the Duration matches the comparator (that)
         *
         * @param that Duration to compare
         *
         * @return comparison result
         */
        int compare(const Duration& that) const;

        /**
         * Returns true if the Duration is greater than the comparator
         *
         * @param that Duration to compare
         * @return comparison result
         */
        bool operator >(const Duration& that) const;

        /**
         * Returns true if the Duration is greater than or equal to the comparator
         * @param Duration &that
         */
        bool operator >=(const Duration& that) const;

        /**
         * Returns true if the Duration is equal to the comparator
         *
         * @param that Duration to compare
         * @return comparison result
         */
        bool operator ==(const Duration& that) const;

        /**
         * Returns true if the Duration is less than or equal to the comparator
         *
         * @param that Duration to compare
         * @return comparison result
         */
        bool operator <=(const Duration& that) const;

        /**
         * Returns true if the Duration is less than the comparator
         *
         * @param that Duration to compare
         * @return comparison result
         */
        bool operator <(const Duration& that) const;

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
        /**
         * Returns this Duration in milliseconds.
         *
         * @return the duration in milliseconds
         */
        uint32_t to_millisecs() const;

        /**
         * Returns this Duration in micro-seconds.
         *
         * @return the duration in micro-seconds
         */
        uint32_t to_microsecs() const;

        /**
         * Returns this Duration in seconds.
         *
         * @return the duration in seconds
         */
        double to_secs() const;

    private:
        uint32_t sec_;
        uint32_t nsec_;
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
