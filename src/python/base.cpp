#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "add plugin";
    m.def("add", &add, py::arg("i"), py::arg("j"), "add function (i, j)");
}