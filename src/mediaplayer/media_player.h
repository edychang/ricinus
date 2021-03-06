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
#include "program/program.h"

#include <string>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 媒体播放控件类接口.
 *
 * 每个媒体类型都有专门对应的媒体播放控件，比如视屏播放控件、图片播放控件和时钟控件等。
 * 具体的媒体播放控件类继承该接口。
 * @note 如果说媒体播放控件是一个演员，那么舞台类就是演出的总指挥。
 * 舞台类手上有所有演员的列表，把各个演员的任务安排下去，等到节目开始的时候，各个演员各司其职。
 */
class media_player_widget {
public:
    media_player_widget(const media_t& m) : m_media(m) {}  ///< 构造函数
    virtual ~media_player_widget() {}

    /**
     * @brief 开始播放.
     */
    virtual void play() = 0;
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
    /**
     * @brief 获取图形化控件.
     * @return 图形化控件指针.
     * @note 不同的图形库，指针的类型不一样，所以此处用void*作为指针类型。
     * 在实际的实现类中，将其强制转换成各图形库对应的类接口。
     */
    virtual void* get_widget() = 0;
protected:
    media_t m_media;   ///< 播放控件中存储一份媒体描述实例的拷贝
};

/**
 * @brief 视频播放控件类.
 * @todo 留待实现.
 */
class video_widget : public media_player_widget {
public:
    video_widget(const media_t& m) : media_player_widget(m) {}  ///< 构造函数
    void play() {}
    void pause() {}
    void resume() {}
    void stop() {}
    void* get_widget() { return NULL; }
};

/**
 * @brief 图片播放控件类.
 * @todo 留待实现.
 */
class image_widget : public media_player_widget {
public:
    image_widget(const media_t& m) : media_player_widget(m) {}  ///< 构造函数
    void play() {}
    void pause() {}
    void resume() {}
    void stop() {}
    void* get_widget() { return NULL; }
};

/**
 * @brief 字幕播放控件类.
 * @todo 留待实现.
 */
class subtitle_widget : public media_player_widget {
public:
    subtitle_widget(const media_t& m) : media_player_widget(m) {}  ///< 构造函数
    void play() {}
    void pause() {}
    void resume() {}
    void stop() {}
    void* get_widget() { return NULL; }
};

/**
 * @brief 时钟控件类.
 * @todo 留待实现.
 */
class clock_widget : public media_player_widget {
public:
    clock_widget(const media_t& m) : media_player_widget(m) {}  ///< 构造函数
    void play() {}
    void pause() {}
    void resume() {}
    void stop() {}
    void* get_widget() { return NULL; }
};

/**
 * @brief 节目播放舞台类.
 *
 * 节目播放的GUI容器,存储并显示具体的播放GUI控件.
 * @note 类比剧场播放的概念,假如说一个播放器是一个剧场,那么该剧场中可能有多个舞台.
 * 每个舞台都能播放一个节目,舞台间可以快速切换,这样可以节省布置舞台的时间.
 */
class scene {
public:
    scene() : m_state(IDLE) {}    ///< 构造函数
    virtual ~scene() {}         ///< 析构函数
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
    /**
     * @brief 代表舞台的各个状态的枚举变量.
     */
    enum play_state_t {
        IDLE = 0,   ///< 舞台空
        READY,      ///< 舞台准备就绪
        PLAYING,    ///< 正在演出
        PAUSED,     ///< 演出暂停
        STOPPED     ///< 演出结束
    };
    /**
     * @brief 获取当前舞台状态.
     * @return 当前舞台状态值.
     * @see play_state
     */
    inline play_state_t get_state() const { return m_state; }
    /**
     * @brief 获取图形化控件容器.
     *
     * 容器中布置所有的媒体播放控件对象，在不同的图形库中有不同的实现类型。
     * @return 图形化控件容器指针.
     */
    virtual void* get_container() const = 0;

protected:
    play_state_t m_state;   ///< 当前舞台状态
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_MEDIA_PLAYER_H__
