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

#ifndef __RICINUS_TASK_H__
#define __RICINUS_TASK_H__

#include "define.h"

#include <string>
#include <vector>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 排程类.
 */
struct schedule {
    /**
     * @brief cron格式的排程定义.
     * @note 格式详见:http://en.wikipedia.org/wiki/Cron.
     * 区别在于该类中没有执行动作的定义.
     */
    std::string cron;
};

/**
 * @brief 计划任务类.
 */
class task {
public:
    /**
     * @brief 显示计划任务.
     * @return 计划任务的字符串表示形式.
     */
    virtual std::string to_string() const = 0;

    schedule sch;                       ///< 任务计划排程.
    /**
     * @brief 具体执行操作.
     * @todo 应该是类似于函数指针之类的对象。。。吧。。。
     */
    std::string action;
    std::vector<std::string> params;    ///< 执行参数.
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_TASK_H__
