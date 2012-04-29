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

#include "includes.h"	// :)


// global variables
WindowHandle mainWindow;
vector<DIDEVICEINSTANCE> devices;

struct DeviceVector : public vector<OperationalDevice*>
{
	~DeviceVector()
	{
		for(unsigned int c = 0 ; c < size() ; c++)
			delete (*this)[c];
	} // end DeviceVector destructor
} operationalDevices;


#include "secondary functions.h"


BOOL __stdcall callBack(LPCDIDEVICEINSTANCE device,LPVOID devices)
{
	if(device->guidInstance != GUID_SysMouse && device->guidInstance != GUID_SysKeyboard)
		((vector<DIDEVICEINSTANCE> *)devices)->push_back(*device);
	return DIENUM_CONTINUE;
} // end function callBack


void firstReshape(int w, int h)
{
	static DirectInput directInput(GetModuleHandle(NULL));

	mainWindow = FindWindow(0,"Getting Input");
	directInput.enumerateDevices(DI8DEVCLASS_ALL,callBack,&devices,DIEDFL_ATTACHEDONLY|DIEDFL_INCLUDEHIDDEN|DIEDFL_INCLUDEPHANTOMS);

	for(unsigned int c = 0 ; c < devices.size() ; ++c)
	{
		OperationalDevice *device = new OperationalDevice(directInput,devices[c].guidInstance);
		if(device->getDeviceObjects().size() != 0)	// if it has device objects that generate data
		{
			device->setCooperativeLevel(mainWindow,DISCL_BACKGROUND|DISCL_NONEXCLUSIVE);
			device->acquire();
			operationalDevices.push_back(device);
		}
		else
			delete device;
	} // end for

	reshape(w,h);
	glutReshapeFunc(reshape);
} // end function firstReshape


void always()
{
	system("CLS");

	try{
		for(unsigned int c = 0 ; c < /*6*/operationalDevices.size() ; ++c)
		{
			operationalDevices[c]->cacheData();
			cout << *operationalDevices[c];
			cout << "\n\n";
		} // end for
	}catch(RuntimeError &e)
	{
		ExceptionMessageBox(e,e,"RuntimeError");
	}catch(LogicError &e)
	{
		ExceptionMessageBox(e,e,"LogicError");
	}catch(InvalidArgument &e)
	{
		ExceptionMessageBox(e,e,"InvalidArgument");
	}catch(OutOfRange &e)
	{
		ExceptionMessageBox(e,e,"OutOfRange");
	} // end catch

	Sleep(30);
} // end function always


int main(int argc, char **argv)
{
	// glut initialization
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(320,320);
	glutInitWindowPosition(900,200);
	glutCreateWindow("Getting Input");

	// glew initialization
	glewInit();

	// OpenGL initialization

	// event handling initialization
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(firstReshape);
	glutIdleFunc(always);
	glutMainLoop();
	return 0;
} // end function main