//	Copyright (C) 2009, 2010, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Getting Input.sln.
 *
 *	Getting Input.sln is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Getting Input.sln is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Getting Input.sln.  If not, see <http://www.gnu.org/licenses/>.
 */

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
