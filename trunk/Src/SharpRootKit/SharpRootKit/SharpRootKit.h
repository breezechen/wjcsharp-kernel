///////////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2012 - <company name here>
///
/// Original filename: SharpRootKit.h
/// Project          : SharpRootKit
/// Date of creation : <see SharpRootKit.cpp>
/// Author(s)        : <see SharpRootKit.cpp>
///
/// Purpose          : <see SharpRootKit.cpp>
///
/// Revisions:         <see SharpRootKit.cpp>
///
///////////////////////////////////////////////////////////////////////////////

// $Id$

#ifndef __SHARPROOTKIT_H_VERSION__
#define __SHARPROOTKIT_H_VERSION__ 100

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif


#include "drvcommon.h"
#include "drvversion.h"

#define DEVICE_NAME			"\\Device\\SHARPROOTKIT_DeviceName"
#define SYMLINK_NAME		"\\DosDevices\\SHARPROOTKIT_DeviceName"
PRESET_UNICODE_STRING(usDeviceName, DEVICE_NAME);
PRESET_UNICODE_STRING(usSymlinkName, SYMLINK_NAME);

#ifndef FILE_DEVICE_SHARPROOTKIT
#define FILE_DEVICE_SHARPROOTKIT 0x8000
#endif

// Values defined for "Method"
// METHOD_BUFFERED
// METHOD_IN_DIRECT
// METHOD_OUT_DIRECT
// METHOD_NEITHER
// 
// Values defined for "Access"
// FILE_ANY_ACCESS
// FILE_READ_ACCESS
// FILE_WRITE_ACCESS

const ULONG IOCTL_SHARPROOTKIT_OPERATION = CTL_CODE(FILE_DEVICE_SHARPROOTKIT, 0x01, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA);

#endif // __SHARPROOTKIT_H_VERSION__
