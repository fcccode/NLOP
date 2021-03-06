#ifndef STEPSIZESEARCHBASE_HPP
#define STEPSIZESEARCHBASE_HPP

#include "Utils/Functor.hpp"
#include "StepsizeSearchParams/StepsizeSearchParamsBase.hpp"
#include <iostream>

namespace NLOP {
/// @class NLOP::StepsizeSearchBase
/// @brief Abstract base class for all stepsize search methods
/// @param FunctorType Target function
template<typename FunctorType>
class StepsizeSearchBase
{
protected:
    using T = typename FunctorType::Scalar;
    using InputType = typename FunctorType::InputType;
    using ValueType = typename FunctorType::ValueType;
    using JacobianType = typename FunctorType::JacobianType;

public:
    /// @brief Iteratively search stepsize
    /// @param d Direction for stepsize searching
    virtual T search(JacobianType& d) = 0;

    /// @brief Bind objective function
    void bind(FunctorType* f) { this->f = f; }

    /// @brief Set params for stepsize searcher
    virtual void setParams(StepsizeSearchParamsBase* given_params) {}

    /// @brief Reset stepsize searcher
    virtual void reset(StepsizeSearchParamsBase* params) = 0;

protected:
    FunctorType* f;    // objective function
};
}

#endif
