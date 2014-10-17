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

/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2011, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#ifndef __RICINUS_CURL_HELPER_H__
#define __RICINUS_CURL_HELPER_H__

/**
 * @brief 无法初始化libcurl.
 *
 * 作为CRULcode的补充，是curl_ftp_get可能的返回值之一。
 */
#define ERR_CURL_CANNOT_INIT -255

/**
 * @brief 使用libcurl实现的ftp下载函数
 * @param url 下载ftp链接
 * @param tofile 下载到本地文件全路径
 * @return <a href="http://curl.haxx.se/libcurl/c/libcurl-errors.html">下载结果码</a>
 */
extern int curl_ftp_get(
        const char* url,
        const char* tofile
        );

#endif // __RICINUS_CURL_HELPER_H__
