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

#include <vector>

RICINUS_NAMESPACE_BEGIN

class scene_impl : public scene {
public:
    scene_impl() : is_playing(false) {}
    ~scene_impl();

    void setup(const std::string &pid);
    void cleanup();
    bool prepared(std::string &id) const;

    void play();
    void pause();
    void resume();
    void stop();
    bool playing() const;

private:
    /**
     * @brief 媒体播放控件指针列表.
     *
     * @note 一份所有演职员名单。
     */
    std::vector<media_player_widget*> widgets;
    std::string id;     ///< 当前准备播放或者正在播放的节目标示符
    bool is_playing;       ///< 当前是否正在播放节目
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_MEDIA_PLAYER_IMPL_H__
