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

    @file ServerInit.h
    @author Stan Kladko
    @date 2019
*/

#ifndef SGXWALLET_SERVERINIT_H
#define SGXWALLET_SERVERINIT_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void init_all(bool check_cert, bool sign_automatically, void (*func)());

EXTERNC void init_daemon();

EXTERNC void init_enclave();



#endif //SGXWALLET_SERVERINIT_H
