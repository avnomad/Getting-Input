// compilation control #defines:
#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG
#endif

// #includes:
#include <iostream>
using std::cout;
using std::wcout;
using std::cin;
using std::endl;
using std::cerr;
using std::clog;
using std::left;
using std::right;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::wofstream;
using std::fstream;
using std::ios;

#include <cstdlib>
using std::system;
using std::exit;

#include <cstring>

#include <exception>
using std::exception;

#include <stdexcept>
using std::runtime_error;
using std::logic_error;
using std::invalid_argument;
using std::bad_alloc;

#include <vector>
using std::vector;

#include <gl/glew.h>
#include <gl/glut.h>

#include <Direct Input/DirectInput Wrapper.h>
#include <Direct Input/Operational Device.h>
#include <windows/common.h>
