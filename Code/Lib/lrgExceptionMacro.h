/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgExceptionMacro_h
#define lrgExceptionMacro_h

#include "lrgException.h"

#define lrgExceptionThrow() throw lrg::Exception(__FILE__,__LINE__)

#endif
