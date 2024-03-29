#ifndef TIMINGBASE_HPP
#define TIMINGBASE_HPP
#include "Timing.hpp"

namespace Timing
{
template<typename T>
class TimingBase
{
public:
    TimingBase()
    {
        sec_ = 0UL;
        nsec_ = 0UL;
    }

    explicit TimingBase(uint32_t sec, uint32_t nanosec)
    {
        sec_ = sec;
        nsec_ = nanosec;
    }

    virtual uint32_t nanosec()
    {
        return nsec_;
    }

    virtual uint32_t sec()
    {
        return sec_;
    }

    static T from_microsecs(uint32_t microseconds)
    {
        return T(microseconds / MiS, static_cast<uint32_t>((microseconds % MiS) * MS));
    }

    static T from_millisecs(uint32_t milliseconds)
    {
        return T(milliseconds / MS, static_cast<uint32_t>((milliseconds % MS) * MiS));
    }

    static T from_secs(double seconds)
    {
        uint32_t int_secs =  static_cast<uint32_t>(seconds);
        uint32_t nanos = static_cast<uint32_t>((seconds - int_secs) * NS);
        return T(int_secs, nanos);
    }

    static T from_minutes(double minutes)
    {
        return T::from_secs((minutes * 60));
    }

    static T from_hours(double hours)
    {
        return T::from_minutes((hours * 60));
    }

    int compare(const T& that) const
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

    template<class O>
    bool operator >(const O& that) const
    {
        return sec_ >= that.sec_ && (sec_ > that.sec_ || nsec_ > that.nsec_);
    }

    template<class O>
    bool operator >=(const O& that)
    {
        return sec() >= that.sec() && nanosec() >= that.nanosec();
    }

    template<class O>
    bool operator ==(const O& that) const
    {
        return sec_ == that.sec_ && nsec_ == that.nsec_;
    }

    template<class O>
    bool operator <=(const O& that) const
    {
        return sec_ <= that.sec_ && nsec_ <= that.nsec_;
    }

    template<class O>
    bool operator <(const O& that) const
    {
        return sec_ <= that.sec_ && (sec_ < that.sec_ || nsec_ < that.nsec_);
    }

    uint32_t to_millisecs() const
    {
        return (static_cast<uint32_t>(sec_) * MS) + (nsec_ / MiS);
    }
    uint32_t to_microsecs() const
    {
        return (static_cast<uint32_t>(sec_) * MiS) + (nsec_ / MS);
    }
    double to_secs() const
    {
        return static_cast<double>(sec_) + (static_cast<double>(nsec_) / NS);
    }

    double to_minutes() const
    {
        return static_cast<double>(this->to_secs() / 60);
    }

    double to_hours() const
    {
        return static_cast<double>(this->to_minutes() / 60);
    }

protected:
    uint32_t sec_;
    uint32_t nsec_;
};
}
#endif
