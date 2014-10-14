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

#ifndef __RICINUS_PLAYER_MANAGER_H__
#define __RICINUS_PLAYER_MANAGER_H__

#include "define.h"
#include "media_player.h"

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 节目播放管理类.
 *
 * 该类为该模块对外的统一接口，其他模块通过该类来实现播放相关的操作。
 * @see scene
 */
class player_manager {
public:
    /**
     * @brief 空闲舞台.
     *
     * 当现在没有节目播放的时候，显示给观众看的东西。
     * @note 空闲舞台的内容是不经常变动的，往往在程序初始化的时候设置好。
     */
    scene idle_scene;
    /**
     * @brief 真正的播放节目的舞台.
     *
     * 默认所有的节目都在这个舞台上播放。真是忙啊，当然，如果一直没节目就另当别论了。
     */
    scene play_scene;
    /**
     * @brief 插播舞台.
     *
     * 有时会有这种情况，比如一个很紧急的通知。这种情况下需要暂停正常播放舞台并保存。
     * 直到插播结束，继续播放正常的节目。
     */
    scene insert_play_scene;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_PLAYER_MANAGER_H__
