#/*============================================================================
#
#  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(PHAS0100ASSIGNMENT1_LIBRARY_NAME phas0100assignment1)

set(PHAS0100ASSIGNMENT1_LIBRARY_SRCS
  lrgBasicTypes.cpp
  lrgMyFunctions.cpp
  lrgException.cpp
  lrgLinearDataCreator.cpp
  lrgFileLoaderDataCreator.cpp
  lrgNormalEquationSolverStrategy.cpp
)

set(PHAS0100ASSIGNMENT1_LIBRARY_HDRS
  lrgExceptionMacro.h
  lrgDataCreatorI.h
  lrgLinearModelSolverStrategyI.h
)

add_library(${PHAS0100ASSIGNMENT1_LIBRARY_NAME} ${PHAS0100ASSIGNMENT1_LIBRARY_HDRS} ${PHAS0100ASSIGNMENT1_LIBRARY_SRCS})

if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-DPHAS0100ASSIGNMENT1_WINDOWS_EXPORT)
  endif(WIN32)
endif(BUILD_SHARED_LIBS)

target_link_libraries(${PHAS0100ASSIGNMENT1_LIBRARY_NAME} PRIVATE ${ALL_THIRD_PARTY_LIBRARIES})
