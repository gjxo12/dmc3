file (GLOB SOURCES "./*.cpp")

add_standard_flag("c++20")

compile_all("false" "usercode" "${SOURCES}")