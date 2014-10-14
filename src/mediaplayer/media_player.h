﻿//Ricinus, platform independent Digital Signage Player
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

#ifndef __RICINUS_MEDIA_PLAYER_H__
#define __RICINUS_MEDIA_PLAYER_H__

#include "define.h"

#include <string>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 节目播放舞台类.
 *
 * 节目播放的GUI容器,存储并显示具体的播放GUI控件.
 * @note 类比剧场播放的概念,假如说一个播放器是一个剧场,那么该剧场中可能有多个舞台.
 * 每个舞台都能播放一个节目,舞台间可以快速切换,这样可以节省布置舞台的时间.
 */
class scene {
public:
    virtual ~scene() {}
    /**
     * @brief 布置舞台.
     * @note 一个舞台同时只能播放一个节目,需要在真正播放节目前调用.
     * @param id 待播放节目的唯一标示符.
     */
    virtual void setup(const std::string& id) = 0;
    /**
     * @brief 拆卸舞台.
     *
     * 一个节目播放完毕了,需要拆卸舞台,为下一台节目做准备.
     */
    virtual void cleanup() = 0;
    /**
     * @brief 舞台是否已经布置好.
     * @param id 如果当前已经有布置好的节目准备播放,该参数将被设置成该节目id.
     * @return 布置好返回true,反之false.
     */
    virtual bool prepared(std::string& id) const = 0;
    /**
     * @brief 开始播放.
     */
    virtual void play() = 0;
    /**
     * @brief 当前是否正在播放节目.
     * @return 正在播放返回true,反之false.
     */
    virtual bool playing() const = 0;
    /**
     * @brief 暂停播放.
     *
     * 考虑到插播节目的情形,如果有一个更高优先级的节目需要播放,则需要
     * 暂停播放当前节目,保存当前播放状态,以便后面继续播放.
     */
    virtual void pause() = 0;
    /**
     * @brief 继续播放之前暂停播放的节目.
     */
    virtual void resume() = 0;
    /**
     * @brief 停止播放节目.
     */
    virtual void stop() = 0;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_MEDIA_PLAYER_H__
