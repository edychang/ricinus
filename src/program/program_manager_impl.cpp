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

#include "program_manager_impl.h"

RICINUS_NAMESPACE_USE;

void program_manager_impl::install(const program_t &program) {
    if (program_installed(program.id))
        throw err_program_already_exist(program.id);
    m_programs[program.id] = program;
}

void program_manager_impl::uninstall(const std::string &id) {
    m_programs.erase(m_programs.find(id));
}

program_t program_manager_impl::get_program(const std::string& id) const {
    std::map<std::string, program_t>::const_iterator it = m_programs.find(id);
    if (it != m_programs.end())
        return it->second;
    throw err_program_id_not_exist(id);
}

bool program_manager_impl::program_installed(const std::string& id) const {
    return (m_programs.find(id) != m_programs.end());
}
