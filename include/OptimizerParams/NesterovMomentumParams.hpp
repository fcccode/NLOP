#ifndef NESTEROVMOMENTUMPARAMS_HPP
#define NESTEROVMOMENTUMPARAMS_HPP

#include <OptimizerParams/LineSearchParams.hpp>

namespace NLOP {
/// @class NLOP::NesterovMomentumParams
/// @brief Params of Momentum optimization methods
class NesterovMomentumParams: public LineSearchParams
{
public:
    /// @brief Constructor
    NesterovMomentumParams() {}

    /// @brief Set mininum gradient to control iterations to stop
    void setMinGradient(const double value)
    {
        min_gradient = value;
    }

    double min_gradient = 0.01; // Gradient threshold to stop the iterations

    double alpha = 0.001; // learning rate
    double beta = 0.9; // momentum hyper-parameters

};
}

#endif
