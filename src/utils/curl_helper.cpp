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

#include "curl_helper.h"

#include <curl/curl.h>

/**
 * @brief 文件下载回写函数参数结构体.
 */
struct ftp_file_t {
    /**
     * @brief 构造函数
     * @param fn 写入文件名
     * @param s 写入文件句柄
     */
    ftp_file_t(const char* fn, FILE* s) : file_name(fn), stream(s) {}
    const char* file_name;  ///< 写入文件名
    FILE* stream;           ///< 写入文件句柄
};

size_t my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream) {
    ftp_file_t *out = (ftp_file_t *) stream;
    if(out && !out->stream) {
        /* open file for writing */
        out->stream = fopen(out->file_name, "wb");
        if(!out->stream)
            return -1; /* failure, can't open file to write */
    }
    return fwrite(buffer, size, nmemb, out->stream);
}

int curl_ftp_get(const char* url, const char* tofile) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();
    CURLcode res;
    ftp_file_t ftp_file(tofile, NULL);
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftp_file);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    if (ftp_file.stream)
        fclose(ftp_file.stream);
    curl_global_cleanup();
    return (int) res;
}
