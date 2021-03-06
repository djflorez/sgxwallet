/*
    Copyright (C) 2019-Present SKALE Labs

    This file is part of sgxwallet.

    sgxwallet is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sgxwallet is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with sgxwallet.  If not, see <https://www.gnu.org/licenses/>.

    @file BLSEnclave.cpp
    @author Stan Kladko
    @date 2020
*/


#ifndef SGXWALLET_COMMON_H
#define SGXWALLET_COMMON_H

using namespace std;

#include <stdlib.h>
#include <iostream>
#include <map>
#include <memory>

#define CHECK_ARGUMENT(_EXPRESSION_) \
    if (!(_EXPRESSION_)) { \
        auto __msg__ = string("Argument Check failed:") + #_EXPRESSION_ + "\n" + __CLASS_NAME__ + ":" + __FUNCTION__ +  \
        + " " + string(__FILE__) + ":" + to_string(__LINE__); \
        throw runtime_error(__msg__);}

#define CHECK_STATE(_EXPRESSION_) \
    if (!(_EXPRESSION_)) { \
        auto __msg__ = string("State check failed::") + #_EXPRESSION_ +  " " + string(__FILE__) + ":" + to_string(__LINE__); \
        throw runtime_error(__msg__);}

#endif //SGXWALLET_COMMON_H
