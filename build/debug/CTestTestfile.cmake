# CMake generated Testfile for 
# Source directory: D:/Workset/polynomial_integral
# Build directory: D:/Workset/polynomial_integral/build/debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IntegratorUnitTests "D:/Workset/polynomial_integral/tests/bin/IntegratorUnitTests.exe")
set_tests_properties(IntegratorUnitTests PROPERTIES  _BACKTRACE_TRIPLES "D:/Workset/polynomial_integral/CMakeLists.txt;110;add_test;D:/Workset/polynomial_integral/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
