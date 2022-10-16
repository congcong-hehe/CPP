#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <map>
#include <string>

namespace py = pybind11;

// vector 和
std::vector<float> vecAdd(std::vector<float>& a, std::vector<float> &b)
{
    assert(a.size() == b.size());
    std::vector<float> ans(a.size());
    for(int i = 0; i < a.size(); ++i)
    {
        ans[i] = a[i] + b[i];
    }
    return ans;
}

// map 和 python中的dict对应
std::map<std::string, int> getMap(std::vector<std::string> &keys, std::vector<int> &values)
{
    assert(keys.size() == values.size());
    std::map<std::string, int> m;
    for(int i = 0; i < keys.size(); ++i)
    {
        m[keys[i]] = values[i];
    }
    return m;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "learn c++ stl python";

    m.def("vecAdd", &vecAdd, py::return_value_policy::reference);
    m.def("getMap", &getMap, py::return_value_policy::reference);
}