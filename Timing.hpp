#ifndef TIMING_HPP
#define TIMING_HPP

#define MS 1000
#define MiS 1000000
#define NS 1000000000

/** Class for converting durations **/
#   include "TimingBase.hpp"
#   include "TimingDuration.hpp"
#   include "TimingTime.hpp"

/*
bool operator == (Timing::Time& lhs, const Timing::Duration& rhs)
{
    return lhs.sec() == rhs.sec() && lhs.nanosec() == rhs.nanosec() ? true : false;
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
*/
#endif
