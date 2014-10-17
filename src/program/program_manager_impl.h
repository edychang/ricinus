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

#ifndef __RICINUS_PROGRAM_MANAGER_IMPL_H__
#define __RICINUS_PROGRAM_MANAGER_IMPL_H__

#include "program_manager.h"

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 节目管理实现类
 */
class program_manager_impl : public program_manager {
public:
    void install(const program_t& program);
    void uninstall(const std::string &id);
    program_t get_program(const std::string& id) const;
    bool program_installed(const std::string& id) const;

private:
    /**
     * @brief 全局的已安装节目列表
     */
    std::map<std::string, program_t> m_programs;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_PROGRAM_MANAGER_IMPL_H__
