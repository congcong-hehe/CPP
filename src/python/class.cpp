#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

class CivilNet
{
public:
    CivilNet(const std::string &name) : name_(name) {}
    void setName(const std::string &name) { name_ = name; }
    const std::string& getName() const { return name_; }

private:
    std::string name_;
};

PYBIND11_MODULE(example, m)
{
    py::class_<CivilNet>(m, "CivilNet")
        .def(py::init<const std::string &> ())
        .def("setName", &CivilNet::setName)
        .def("getName", &CivilNet::getName);
}