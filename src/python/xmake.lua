add_rules("mode.debug", "mode.release")

set_languages("c++17")

add_includedirs("D:\\study_software\\pybind11\\pybind11-2.3.0\\include")
add_includedirs("C:\\Users\\11243\\AppData\\Local\\Programs\\Python\\Python39\\include")

add_linkdirs("C:/Users/11243/AppData/Local/Programs/Python/Python39/libs")

target("example")
    add_rules("python.library")
    add_files("class.cpp")