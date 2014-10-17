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
 * @brief 节目标识符所对应的节目不存在错误.
 */
struct err_program_id_not_exist {
    /**
     * @brief 构造函数
     * @param id_ 有问题的节目标识符
     */
    err_program_id_not_exist(const std::string& id_) : id(id_) {}
    std::string id; ///< 节目标识符
};

/**
 * @brief 指定节目标示符对应的节目已经被安装.
 */
struct err_program_already_exist {
    /**
     * @brief 构造函数
     * @param id_ 有问题的节目标识符
     */
    err_program_already_exist(const std::string& id_) : id(id_) {}
    std::string id; ///< 节目标识符
};

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
     * @param program 节目描述类实例.
     * @note 节目包文件为打包的单个文件.
     * @note 调用本函数前，要求节目文件已经被下载/拷贝到本地磁盘.
     * @see program_t
     * @throw err_program_already_exist
     */
    virtual void install(const program_t& program) = 0;
    /**
     * @brief 卸载节目.
     * @param id 待卸载的节目唯一标示符.
     */
    virtual void uninstall(const std::string& id) = 0;
    /**
     * @brief 获取节目类对象的一份拷贝.
     * @param id 节目唯一标识符.
     * @return 系统中符合标识符的节目对象的拷贝.
     * @throw err_program_id_not_exist
     * @see program_t
     */
    virtual program_t get_program(const std::string& id) const = 0;
    /**
     * @brief 查询指定标识符的节目是否已经被安装.
     * @param id 节目唯一标识符.
     * @return 已经安装返回true，否则返回false。
     */
    virtual bool program_installed(const std::string& id) const = 0;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_PROGRAM_MANAGER_H__
