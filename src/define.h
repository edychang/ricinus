//Ricinus, platform independent Digital Signage Player
//Copyright (C) 2014 Edward Zhang

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __RICINUS_DEFINE_H__
#define __RICINUS_DEFINE_H__

#define RICINUS_NAMESPACE_BEGIN     namespace ricinus {
#define RICINUS_NAMESPACE_END       }
#define RICINUS_NAMESPACE_USE       using namespace ricinus

typedef unsigned char BYTE;

typedef unsigned char UINT_8;

#if defined(_MSC_VER) // MS Visual C++
typedef __int16                     INT_16;
typedef unsigned __int16            UINT_16;
typedef __int32                     INT_32;
typedef unsigned __int32            UINT_32;
typedef __int64                     INT_64;
typedef unsigned __int64            UINT_64;
#else
#include <stdint.h>
typedef int16_t                     INT_16;
typedef uint16_t                    UINT_16;
typedef int32_t                     INT_32;
typedef uint32_t                    UINT_32;
typedef int64_t                     INT_64;
typedef uint64_t                    UINT_64;
#endif

#endif
