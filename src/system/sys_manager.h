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

#ifndef __RICINUS_SYS_MANAGER_H__
#define __RICINUS_SYS_MANAGER_H__

#include "define.h"

#include <utility>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 系统管理接口类.
 *
 * 该类定义了系统管理功能的接口。实际的系统管理类继承该接口，针对不同平台/硬件独立编写。
 */
class system_manager {
public:
    virtual ~system_manager() {}
    /**
     * @brief 关闭显示器.
     */
    virtual void turn_off_monitor() const = 0;
    /**
     * @brief 打开显示器.
     */
    virtual void turn_on_monitor() const = 0;

    /**
     * @brief 自定义分辨率数据结构.
     */
    typedef std::pair<uint16_t, uint16_t> resolution_t;
    /**
     * @brief 获取屏幕分辨率.
     * @return 屏幕分辨率.
     * @see resolution
     */
    virtual resolution_t get_resolution() const = 0;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_SYS_MANAGER_H__
