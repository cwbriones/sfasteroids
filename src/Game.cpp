#include "Game.h"
#include "Identifier.h"

#include "TitleState.h"
#include "GameplayState.h"
#include "PausedState.h"

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
    window_(sf::VideoMode(kWidth, kHeight), kTitle, sf::Style::Titlebar | sf::Style::Close),
    textures_(),
    fonts_(),
    state_manager_(State::Context(window_, textures_, fonts_)),
    rendering_monitor_()
{
    window_.setKeyRepeatEnabled(false);
    fonts_.load(Fonts::kDefaultFont, "../res/Sansation.ttf");

    registerStates();
    state_manager_.requestStateChange(StateManager::kPushState, States::kTitleState);
}

void Game::registerStates(){
    state_manager_.registerState<TitleState>(States::kTitleState);
    state_manager_.registerState<PausedState>(States::kPausedState);
    state_manager_.registerState<GameplayState>(States::kGameplayState);
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
    sf::Time elapsed_time = period;
    sf::Clock clock;

    while (window_.isOpen()){
        // Game logic
        processEvents();
        update(elapsed_time);
        render();

        // Check how long we need to sleep
        // to keep the framerate on target
        elapsed_time = clock.restart();
        sleep_time = (period - elapsed_time) - overslept_time;
        
        // Try to sleep
        if (sleep_time > sf::Time::Zero){
            sf::sleep(sleep_time);

            actual_sleep = clock.restart();
            elapsed_time += actual_sleep;

            overslept_time = actual_sleep - sleep_time;
        } else {
            // Slept too long
            excess += sleep_time;
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
    state_manager_.update(delta_time);
    rendering_monitor_.update(delta_time);
}

#include <SFML/Graphics/Text.hpp>
#include <sstream>

void Game::render(){
    window_.clear();

    state_manager_.draw();
    window_.setView(window_.getDefaultView());

    int fps = static_cast<int>(rendering_monitor_.currentFps());
    std::ostringstream os;
    os << fps;

    sf::Text text(os.str(), fonts_.get(Fonts::kDefaultFont), 20);
    text.setPosition(10,10);
    window_.draw(text);

    // Frame-by-frame rendering goes here
    window_.display();
}
