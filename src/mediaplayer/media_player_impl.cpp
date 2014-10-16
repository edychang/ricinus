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

#include "media_player_impl.h"

RICINUS_NAMESPACE_USE;

media_player_widget* media_player_widget_factory::create(const media &m) {
    switch (m.type) {
    case media::VIDEO:
        return new video_widget(m);
    case media::IMAGE:
        return new image_widget(m);
    case media::SUBTITLE:
        return new subtitle_widget(m);
    case media::CLOCK:
        return new clock_widget(m);
    default:
        throw unrecognized_media(m);
    };
}

scene_impl::~scene_impl() {
    cleanup();
}

void scene_impl::setup(const std::string &pid) {
    program prog = pmgr->get_program(pid);
    for(size_t i = 0, n = prog.medias.size(); i < n; ++i) {
        media_player_widget* widget =
                media_player_widget_factory::create(prog.medias[i]);
        // exception shall thrown if media not recognizable
        widgets.push_back(widget);
    }
    this->pid = pid;
    state = READY;
}

void scene_impl::cleanup() {
    // Everyone leave! We are closing!
    if ((state == PLAYING) || (state = PAUSED)) stop();
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        delete widgets.at(i);
    }
    pid = ""; // this program is offline
    state = IDLE;
}

bool scene_impl::prepared(std::string& pid) const {
    return (this->pid.compare(pid) == 0);
}

void scene_impl::play() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->play();
    }
    state = PLAYING;
}

void scene_impl::pause() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->pause();
    }
    state = PAUSED;
}

void scene_impl::resume() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->resume();
    }
    state = PLAYING;
}

void scene_impl::stop() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->stop();
    }
    state = STOPPED;
}
