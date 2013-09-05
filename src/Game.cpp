#include "Game.h"
#include "Identifier.h"
#include "TitleState.h"

#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <iomanip>

const float kTargetFramerate = 60.0f;

const int kWidth = 640;
const int kHeight = 480;
const int kMaxFrameSkips = 10;

const std::string kTitle = "SFML Application";

Game::Game() : 
    window_(sf::VideoMode(kWidth, kHeight), kTitle),
    textures_(),
    fonts_(),
    state_manager_(State::Context(window_, textures_, fonts_)),
    rendering_monitor_()
{
    window_.setKeyRepeatEnabled(false);
    fonts_.load(Fonts::kDefaultFont, "./res/Sansation.ttf");

    registerStates();
    state_manager_.requestStateChange(StateManager::kPushState, States::kTitleState);
}

void Game::registerStates(){
    state_manager_.registerState<TitleState>(States::kTitleState);
}

int Game::run(){

    int frame_skips;
    const sf::Time period = 
        sf::seconds(1.0f/kTargetFramerate);
    float frame_rate;

    // Sleep-related variables
    sf::Time sleep_time;
    sf::Time actual_sleep = sf::Time::Zero;
    sf::Time overslept_time = sf::Time::Zero;

    sf::Time excess = sf::Time::Zero;

    // Timekeeping variables
    sf::Time elapsed_time;
    sf::Clock clock;

    while (window_.isOpen()){

        elapsed_time = clock.restart() + actual_sleep; 
        
        // Check how long we need to sleep
        // to keep the framerate on target
        sleep_time = (period - elapsed_time) - overslept_time;

        // Game logic
        processEvents();
        update(elapsed_time);
        render();

        // Sleep Logic
        if (sleep_time > sf::Time::Zero){
            // Try to sleep
            sf::sleep(sleep_time);
            actual_sleep = clock.restart();

            overslept_time = actual_sleep - sleep_time;
        } else {
            // Slept too long
            excess -= sleep_time;
            overslept_time = sf::Time::Zero;
        }

        // Frame skips
        // Updates are lagging, update without renders
        frame_skips = 0;
        while (excess > period && frame_skips < kMaxFrameSkips){
            frame_skips++;
            excess -= period;

            processEvents();
            update(period);
        }
        rendering_monitor_.incrementSkips(frame_skips);
    }

    return 0;
}

void Game::processEvents(){

    sf::Event event;

    while (window_.pollEvent(event)){

        state_manager_.handleEvent(event);

        if (event.type == sf::Event::Closed ||
           (event.type == sf::Event::KeyPressed && 
            event.key.code == sf::Keyboard::Escape)){
            window_.close();
        }
    }
}

void Game::update(sf::Time delta_time){
    // state_manager_.update(delta_time);
    rendering_monitor_.update(delta_time);
}

void Game::render(){
    window_.clear();

    state_manager_.draw();
    window_.setView(window_.getDefaultView());

    float fps = rendering_monitor_.currentFps();
    std::cout << "  " << std::setw(2) << std::setprecision(4) << fps << '\r';
    std::cout.flush();

    // Frame-by-frame rendering goes here
    window_.display();
}
