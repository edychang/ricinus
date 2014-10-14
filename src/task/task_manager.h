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

#ifndef __RICINUS_TASK_MANAGER_H__
#define __RICINUS_TASK_MANAGER_H__

#include "define.h"
#include "task.h"

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 计划任务管理类.
 *
 * 该类负责管理所有的计划任务。
 * @see task
 */
class task_manager {
public:
    /**
     * @brief 添加计划任务.
     * @param t 计划任务定义类.
     * @note 一旦添加，计划任务将被加入调度队列；一旦时间条件满足，定义任务将被执行。
     * @return 整型格式的任务唯一标示符.
     */
    virtual int add_task(const task& t) = 0;
    /**
     * @brief 取消任务.
     * @param id 待取消的任务唯一标示符.
     */
    virtual void cancel_task(const int id) = 0;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_TASK_MANAGER_H__
