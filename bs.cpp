#include"bs.hpp"

int main() {
  double const K = 100.0;                    // Strike price.
  //auto const S = make_fvar<double, 2>(105);  // Stock price.
  double const S = 105;
  double const sigma = 5;                    // Volatility.
  double const tau = 30.0 / 365;             // Time to expiration in years. (30 days).
  double const r = 1.25 / 100;               // Interest rate.
  auto const call_price = black_scholes_option_price(CP::call, K, S, sigma, tau, r);
  auto const put_price = black_scholes_option_price(CP::put, K, S, sigma, tau, r);

//   std::cout << "black-scholes call price = " << call_price.derivative(0) << '\n'
//             << "black-scholes put  price = " << put_price.derivative(0) << '\n'
//             << "call delta = " << call_price.derivative(1) << '\n'
//             << "put  delta = " << put_price.derivative(1) << '\n'
//             << "call gamma = " << call_price.derivative(2) << '\n'
//             << "put  gamma = " << put_price.derivative(2) << '\n'
       std::cout << "call vega = "<< vega(S, K, tau, r, sigma) << "\n";
  return 0;
}