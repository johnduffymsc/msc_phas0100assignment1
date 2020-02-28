/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgWin32ExportHeader_h
#define lrgWin32ExportHeader_h

/**
* \file lrgWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(PHAS0100ASSIGNMENT1_STATIC)
  #ifdef PHAS0100ASSIGNMENT1_WINDOWS_EXPORT
    #define PHAS0100ASSIGNMENT1_WINEXPORT __declspec(dllexport)
  #else
    #define PHAS0100ASSIGNMENT1_WINEXPORT __declspec(dllimport)
  #endif  /* PHAS0100ASSIGNMENT1_WINEXPORT */
#else
/* linux/mac needs nothing */
  #define PHAS0100ASSIGNMENT1_WINEXPORT
#endif

#endif
