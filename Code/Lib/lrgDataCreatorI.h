/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgDataCreatorI_h
#define lrgDataCreatorI_h

#include <vector>

namespace lrg {

    class DataCreatorI {
        public:
            virtual std::vector<std::pair<double, double>> GetData() = 0;
    };

} // end namespace

#endif
