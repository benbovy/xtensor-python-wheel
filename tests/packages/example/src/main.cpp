#include "pybind11/pybind11.h"
#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyvectorize.hpp"

namespace py = pybind11;


double add(double a, double b)
{
    return a + b;
}

PYBIND11_MODULE(example, m)
{
    xt::import_numpy();
    m.doc() = "Test module for xtensor python bindings";

    m.def("add", xt::pyvectorize(add), "Vectorized add");
}
