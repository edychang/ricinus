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

media_player_widget* media_player_widget_factory::create(const media_t &m) {
    switch (m.type) {
    case media_t::VIDEO:
        return new video_widget(m);
    case media_t::IMAGE:
        return new image_widget(m);
    case media_t::SUBTITLE:
        return new subtitle_widget(m);
    case media_t::CLOCK:
        return new clock_widget(m);
    default:
        throw err_unrecognized_media(m);
    };
}

scene_impl::~scene_impl() {
    cleanup();
}

void scene_impl::setup(const std::string &pid) {
    program_t prog = m_pmgr->get_program(pid);
    for(size_t i = 0, n = prog.medias.size(); i < n; ++i) {
        media_player_widget* widget =
                media_player_widget_factory::create(prog.medias[i]);
        // exception shall thrown if media not recognizable
        m_widgets.push_back(widget);
    }
    this->m_pid = pid;
    m_state = READY;
}

void scene_impl::cleanup() {
    // Everyone leave! We are closing!
    if ((m_state == PLAYING) || (m_state = PAUSED)) stop();
    for(size_t i = 0, n = m_widgets.size(); i < n; ++i) {
        delete m_widgets.at(i);
    }
    m_pid = ""; // this program is offline
    m_state = IDLE;
}

bool scene_impl::prepared(std::string& pid) const {
    return (this->m_pid.compare(pid) == 0);
}

void scene_impl::play() {
    for(size_t i = 0, n = m_widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (m_widgets[i])->play();
    }
    m_state = PLAYING;
}

void scene_impl::pause() {
    for(size_t i = 0, n = m_widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (m_widgets[i])->pause();
    }
    m_state = PAUSED;
}

void scene_impl::resume() {
    for(size_t i = 0, n = m_widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (m_widgets[i])->resume();
    }
    m_state = PLAYING;
}

void scene_impl::stop() {
    for(size_t i = 0, n = m_widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (m_widgets[i])->stop();
    }
    m_state = STOPPED;
}

void *scene_impl::get_container() const {
    return m_container;
}
