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

#ifndef __RICINUS_PROGRAM_MANAGER_H__
#define __RICINUS_PROGRAM_MANAGER_H__

#include "define.h"
#include "program.h"

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 节目管理类.
 *
 * 节目管理的统一接口,其他模块通过调用本类实现对节目的管理.
 * @see program
 */
class program_manager {
public:
    virtual ~program_manager() {}
    /**
     * @brief 安装节目.
     * @param path 节目包文件的本地磁盘全路径.
     * @note 节目包文件为打包的单个文件.
     * @note 调用本函数前，要求节目文件已经被下载/拷贝到本地磁盘.
     * @return 节目安装结果码.
     */
    virtual int install(const std::string& path) const = 0;
    /**
     * @brief 卸载节目.
     * @param id 待卸载的节目唯一标示符.
     * @return 节目卸载结果码.
     */
    virtual int uninstall(const std::string& id) const = 0;
    /**
     * @brief 播放节目.
     * @note 因为屏幕只有一个,所以当前播放的节目应该也只有一个.
     * @param id 待播放的节目唯一标示符.
     * @return 节目播放节目码.
     */
    virtual int play(const std::string& id) const = 0;
    /**
     * @brief 停止播放当前节目.
     * @return 停止播放节目返回代码.
     */
    virtual int stop() const = 0;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_PROGRAM_MANAGER_H__
