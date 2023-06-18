# CMake generated Testfile for 
# Source directory: D:/repos/Prata/matrix/build/Test
# Build directory: D:/repos/Prata/matrix/build/build/Test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[matrixtest]=] "D:/repos/Prata/matrix/build/build/Test/Debug/matrixtest.exe")
  set_tests_properties([=[matrixtest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/repos/Prata/matrix/build/Test/CMakeLists.txt;16;add_test;D:/repos/Prata/matrix/build/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[matrixtest]=] "D:/repos/Prata/matrix/build/build/Test/Release/matrixtest.exe")
  set_tests_properties([=[matrixtest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/repos/Prata/matrix/build/Test/CMakeLists.txt;16;add_test;D:/repos/Prata/matrix/build/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[matrixtest]=] "D:/repos/Prata/matrix/build/build/Test/MinSizeRel/matrixtest.exe")
  set_tests_properties([=[matrixtest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/repos/Prata/matrix/build/Test/CMakeLists.txt;16;add_test;D:/repos/Prata/matrix/build/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[matrixtest]=] "D:/repos/Prata/matrix/build/build/Test/RelWithDebInfo/matrixtest.exe")
  set_tests_properties([=[matrixtest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/repos/Prata/matrix/build/Test/CMakeLists.txt;16;add_test;D:/repos/Prata/matrix/build/Test/CMakeLists.txt;0;")
else()
  add_test([=[matrixtest]=] NOT_AVAILABLE)
endif()
