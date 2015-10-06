//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_POINTER_H
#define CIRCUITSIM_POINTER_H

#include <memory>
#include <functional>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "circuitsim.h"

namespace circuitsim
{
    template<typename F, typename... Args>
    void call(F&& f, Args&& ... args)
    {
        f(std::forward<Args>(args)...);

        if (circuitsim_last_error()[0])
        {
            throw std::logic_error(circuitsim_last_error());
        }
    }

    template<typename F, typename... Args>
    typename std::result_of<F&&(Args&& ...)>::type callr(F&& f, Args&& ... args)
    {
        auto const& result = f(std::forward<Args>(args)...);

        if (circuitsim_last_error()[0])
        {
            throw std::logic_error(circuitsim_last_error());
        }

        return result;
    }

    template<typename I, int IID>
    struct handle final
    {
        handle()
                : impl_(static_cast<I*>(circuitsim_new(IID)))
        {
            if (!this->impl_)
            {
                throw std::logic_error(circuitsim_last_error());
            }
        }

        ~handle()
        {
            circuitsim_delete(IID, static_cast<void*>(this->impl_));
        }

        handle(handle&& other)
                : impl_{other.impl_}
        {
        }

        handle& operator=(handle&& other)
        {
            circuitsim_delete(IID, static_cast<void*>(this->impl_));

            this->impl_ = other.impl_;
            return *this;
        }

        handle(const handle&) = delete;

        handle& operator=(const handle&) = delete;

        I& get() const
        {
            return *this->impl_;
        }

    private:
        I* impl_;
    };

}

#endif //CIRCUITSIM_POINTER_H
