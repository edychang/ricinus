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

scene_impl::~scene_impl() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        delete widgets.at(i);
    }
}

void scene_impl::setup(const std::string &pid) {
    id = pid;
    // TODO
}

void scene_impl::cleanup() {
    // TODO
}

bool scene_impl::prepared(std::string& id) const {
    // TODO
    return false;
}

void scene_impl::play() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->play();
    }
    is_playing = true;
}

void scene_impl::pause() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->pause();
    }
}

void scene_impl::resume() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->resume();
    }
}

void scene_impl::stop() {
    for(size_t i = 0, n = widgets.size(); i < n; ++i) {
        static_cast<media_player_widget*> (widgets[i])->stop();
    }
}

bool scene_impl::playing() const {
    return is_playing;
}
