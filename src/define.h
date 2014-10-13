//Copyright (C)2014 by Edward Zhang
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

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
