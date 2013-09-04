#ifndef RENDERINGMONITOR_H_
#define RENDERINGMONITOR_H_

#include <SFML/System/Time.hpp>

class RenderingMonitor
{
public:
    RenderingMonitor();

    void update(sf::Time delta_time);
    void setUpdateInterval(sf::Time interval);

    inline void incrementSkips(int skips){
        skips_ += skips;
    }

    inline float currentFps(){
        return current_fps_;
    }
private:
    sf::Time elapsed_;
    sf::Time interval_size_;

    float current_fps_;

    int frames_;
    int skips_;
}; 

#endif /* RENDERINGMONITOR_H_ */
