#include "RenderingMonitor.h"

RenderingMonitor::RenderingMonitor()
    : interval_size_(sf::seconds(1.0f)){}

void RenderingMonitor::update(sf::Time delta_time){
    frames_++;

    if ((elapsed_ += delta_time) > interval_size_){
        // Update
        current_fps_ = static_cast<float>(frames_)/elapsed_.asSeconds();
        // Reset
        elapsed_ = sf::Time::Zero;
        frames_ = 0;
        skips_ = 0;
    }
}

void RenderingMonitor::setUpdateInterval(sf::Time interval){
    interval_size_ = interval;
}

// inline float RenderingMonitor::currentFps(){
//     return current_fps_;
// }
// 
// inline void RenderingMonitor::incrementSkips(int skips){
//     skips_ += skips;
// }
