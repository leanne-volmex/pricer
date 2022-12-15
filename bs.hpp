#include <boost/math/differentiation/autodiff.hpp>
#include <iostream>

using namespace boost::math::constants;
using namespace boost::math::differentiation;

//constexpr double RSQRT2PI = 0.39894228040143267793994605993438;

// template <typename X>
// X Phi(X const& x) {
//   return RSQRT2PI * exp(-0.5*x*x);
// }

// Standard normal cumulative distribution function
template <typename Y>
Y Phi(Y const& y) {
  return 0.5 * erfc(-one_div_root_two<Y>() * y);
}

enum class CP { call, put };

// Assume zero annual dividend yield (q=0).
template <typename Price, typename Sigma, typename Tau, typename Rate>
promote<Price, Sigma, Tau, Rate> black_scholes_option_price(CP cp,
                                                            double K,
                                                            Price const& S,
                                                            Sigma const& sigma,
                                                            Tau const& tau,
                                                            Rate const& r) {
  using namespace std;
  auto const d1 = (log(S / K) + (r + sigma * sigma / 2) * tau) / (sigma * sqrt(tau));
  auto const d2 = (log(S / K) + (r - sigma * sigma / 2) * tau) / (sigma * sqrt(tau));
  switch (cp) {
    case CP::call:
      return S * Phi(d1) - exp(-r * tau) * K * Phi(d2);
    case CP::put:
      return exp(-r * tau) * K * Phi(-d2) - S * Phi(-d1);
  }
  return 1;
}

// template<typename Price, typename Strike, typename Tau, typename Rate, typename Sigma>
// promote<Price, Sigma, Tau, Rate, Sigma> vega( Price const&S, Strike const&K, 
//                                                 Tau const&tau,
//                                                 Rate const&rate,
//                                                 Sigma const&sigma){
//                                                     double d1 = log(S/K)+((rate+sigma*sigma/2)*tau)/sigma*sqrt(tau);
//                                                     return S*sqrt(tau)*Phi(d1);
                                                    
//                                                 }

double vega( const double &S, const double&K, const double&tau, const double&rate, const double&sigma)
{
    double d1 = log(S/K)+((rate+sigma*sigma/2)*tau)/sigma*sqrt(tau);
    return S*sqrt(tau)*Phi(d1);
                                                    
}




