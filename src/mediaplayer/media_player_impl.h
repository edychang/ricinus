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

#ifndef __RICINUS_MEDIA_PLAYER_IMPL_H__
#define __RICINUS_MEDIA_PLAYER_IMPL_H__

#include "media_player.h"
#include "program/program_manager.h"

#include <vector>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 不能识别的媒体描述类异常.
 */
struct unrecognized_media {
    unrecognized_media(const media& m) : me(m) {} ///< 构造函数
    media me;   ///< 媒体描述类对象
};

/**
 * @brief 媒体播放控件工厂类.
 *
 * 负责媒体播放控件对象的创建等全局性的函数操作.
 */
class media_player_widget_factory {
public:
    /**
     * @brief 创建媒体播放控件对象.
     * @param m 媒体描述类.
     * @return 媒体播放控件对象.
     * @throw unrecognized_media
     */
    static media_player_widget* create(const media& m);
};

/**
 * @brief 基于QT4的节目舞台具体实现类.
 */
class scene_impl : public scene {
public:
    ~scene_impl();

    void setup(const std::string &pid);
    void cleanup();
    bool prepared(std::string &pid) const;

    void play();
    void pause();
    void resume();
    void stop();

private:
    /**
     * @brief 媒体播放控件指针列表.
     *
     * @note 一份所有演职员名单。
     */
    std::vector<media_player_widget*> widgets;
    std::string pid;        ///< 当前准备播放或者正在播放的节目标示符
    program_manager* pmgr;  ///< 节目管理类实现实例
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_MEDIA_PLAYER_IMPL_H__
