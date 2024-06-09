#include <iostream>
#include <cmath>
#include <complex>
#include <math.h>
#include <emscripten/bind.h>

using namespace emscripten;
using namespace std::complex_literals;

// Corresponds to the CanvasPoint type in the TypeScript,
// used to input values into the compute function
struct CanvasPoint {
  float x;
  float y;
};

// Corresponds to the Epicycle type in the TypeScript,
// used to send computed results back
struct Epicycle {
  float radius;
  float angular_frequency;
  float phase;
};

// Calculates what values of k should be used
std::vector<int> get_values_of_k(int N) {
  std::vector<int> values;

  for (int i = 0; i < N; i++) {
    values.push_back(i - N / 2);
  }

  return values;
}

std::complex<double> calculate_X_k(std::vector<std::complex<double>> &x, int N, int m, int k) {
  auto summation = std::complex<double>(0, 0);

  for (int n = -m; n < m; n++) {
    summation += x.at(n + m) * std::complex<double>(
      cos(k * 2 * M_PI * n / N),
      -1 * sin(k * 2 * M_PI * n / N)
    );
  }

  return std::complex<double>(1.0 / N, 0) * summation;
}

// Compares two epicycles based on their amplitude (radius),
// used for sorting the vector
bool amplitude_comparator (Epicycle e1, Epicycle e2) {
  return e1.radius > e2.radius;
}

std::vector<Epicycle> compute(std::vector<CanvasPoint> input_points) {
  std::vector<std::complex<double>> x;
  
  for (auto point : input_points) {
    x.push_back(std::complex<double>(point.x, point.y));
  }

  int N = x.size();
  int m = N / 2;

  auto values_of_k = get_values_of_k(N);
  std::vector<Epicycle> epicycles;
    
  for (auto k : values_of_k) {
    auto X_k = calculate_X_k(x, N, m, k);
    struct Epicycle next_epicycle;
    next_epicycle.radius = std::abs(X_k);
    next_epicycle.angular_frequency = k;
    next_epicycle.phase = std::arg(X_k);
    epicycles.push_back(next_epicycle);
  }

  std::sort(epicycles.begin(), epicycles.end(), amplitude_comparator);

  return epicycles;
}

EMSCRIPTEN_BINDINGS(fourier) {
    value_array<Epicycle>("Epicycle")
      .element(&Epicycle::radius)
      .element(&Epicycle::angular_frequency)
      .element(&Epicycle::phase)
      ;

    value_array<CanvasPoint>("CanvasPoint")
      .element(&CanvasPoint::x)
      .element(&CanvasPoint::y)
      ;

    register_vector<Epicycle>("VectorEpicycle");
    register_vector<CanvasPoint>("VectorCanvasPoint");

    function("compute", &compute);
}
