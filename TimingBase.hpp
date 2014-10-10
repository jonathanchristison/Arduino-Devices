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

    virtual uint32_t nanosec() const=0;

    virtual uint32_t sec() const=0;

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

    bool operator >(const T& that) const
    {
        return sec_ >= that.sec_ && (sec_ > that.sec_ || nsec_ > that.nsec_);
    }

    bool operator >=(const T& that) const
    {
        return sec_ >= that.sec_ && nsec_ >= that.nsec_;
    }

    bool operator ==(const T& that) const
    {
        return sec_ == that.sec_ && nsec_ == that.nsec_;
    }

    bool operator <=(const T& that) const
    {
        return sec_ <= that.sec_ && nsec_ <= that.nsec_;
    }

    bool operator <(const T& that) const
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

protected:
    uint32_t sec_;
    uint32_t nsec_;
};
}
#endif
