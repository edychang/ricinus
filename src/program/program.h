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

#ifndef __RICINUS_PROGRAM_H__
#define __RICINUS_PROGRAM_H__

#include "define.h"
#include "task/task.h"

#include <map>
#include <vector>
#include <string>

RICINUS_NAMESPACE_BEGIN

/**
 * @brief 媒体布局类.
 *
 * 描述媒体素材在屏幕上如何显示和排布.
 */
struct geometry_t {
    geometry_t() : x(0), y(0), width(0), height(0), z(0) {} ///< 构造函数

    uint16_t x;          ///< 距离显示屏左上角的横向像素距离
    uint16_t y;          ///< 距离显示屏左上角的纵向像素距离
    uint16_t width;      ///< 宽度
    uint16_t height;     ///< 高度
    /**
     * @brief z 垂直方向显示次序.
     *
     * (在多个media存在交叠时)垂直方向显示次序,数值越大越靠前显示.
     * @note z值相同时,按照media在program中的添加次序显示,后添加的覆盖前面的.
     */
    uint16_t z;
};

/**
 * @brief 媒体素材类.
 *
 * 每个素材定义了布局,类型,播放参数等信息.
 * @see geometry
 */
struct media_t {
    /**
     * @brief 媒体素材类型.
     * @todo 初版中所提供的是最基本的媒体类型,未来可能会要支持更多的类型,如网页等.
     */
    enum media_type_t {
        VIDEO = 0,      ///< 视频媒体素材
        IMAGE,          ///< 图片媒体素材
        SUBTITLE,       ///< 字幕媒体素材
        CLOCK,          ///< 时钟媒体素材
        RESERVED        ///< 留作日后扩展
    };

    media_type_t type;    ///< 媒体素材类型值
    geometry_t geo;       ///< 媒体素材布局定义

    /**
     * @brief 自定义参数列表对象.
     */
    typedef std::map<std::string, std::string> prop_t;
    prop_t params;  ///< 媒体素材具体参数
};

/**
 * @brief 节目类.
 *
 * Ricinus以节目为单位播放多媒体信息，一个节目可以包含多个素材.
 * @see media,schedule
 */
struct program_t {
    std::vector<media_t> medias;  ///< 媒体素材列表
    schedule_t schdule;           ///< 节目播放排程
    /**
     * @brief 节目播放优先级.
     *
     * 在一次调度轮询中，队列中优先级更高的节目会优先被播放.
     */
    uint32_t priority;
    /**
     * @brief 节目的唯一标识符.
     */
    std::string id;
};

RICINUS_NAMESPACE_END

#endif // __RICINUS_PROGRAM_H__
