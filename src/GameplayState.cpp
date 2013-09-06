#include "GameplayState.h"
#include "Utility.h"

GameplayState::GameplayState(StateManager& manager, Context context) : 
    State(manager, context), 
    text_(), 
    circle_(30.f, 50), 
    circle_color_(sf::Color::Cyan),
    circle_vel_(3.0f, 3.0f)
{
    text_.setString("We'll be doing cool game stuff here.\nImagine it.");
    text_.setColor(sf::Color::White);
    text_.setFont(context.fonts->get(Fonts::kDefaultFont));
    Utility::centerOrigin(text_);

    sf::Window& window = *context.window;
    text_.setPosition(window.getSize().x/2u, window.getSize().y/2u);

    Utility::centerOrigin(&circle_);
    circle_.setFillColor(sf::Color::Cyan);
    circle_.setPosition(window.getSize().x/2u, window.getSize().y/2u);
}

bool GameplayState::update(sf::Time delta_time){
    circle_.move(circle_vel_.x, circle_vel_.y);

    sf::Vector2u dimensions = getContext().window->getSize();

    sf::Vector2f new_position_(circle_.getPosition());
    sf::Vector2f new_velocity_(circle_vel_);

    if (circle_.getRadius() + circle_.getPosition().x > dimensions.x){
        new_position_.x = dimensions.x - circle_.getRadius();
        new_velocity_.x = -new_velocity_.x;
    }
    else if (-circle_.getRadius() + circle_.getPosition().x < 0){
        new_position_.x = circle_.getRadius();
        new_velocity_.x = -new_velocity_.x;
    }
    if (circle_.getRadius() + circle_.getPosition().y > dimensions.y){
        new_position_.y = dimensions.y - circle_.getRadius();
        new_velocity_.y = -new_velocity_.y;
    }
    else if (-circle_.getRadius() + circle_.getPosition().y < 0){
        new_position_.y = circle_.getRadius();
        new_velocity_.y = -new_velocity_.y;
    }
    circle_vel_ = new_velocity_;
    circle_.setPosition(new_position_);

    return ALLOW_OTHER_UPDATES;
}

bool GameplayState::handleEvent(const sf::Event& event){
    if (event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::P){
            requestStatePush(States::kPausedState);
        }
        if (event.key.code == sf::Keyboard::BackSpace){
            requestClearToState(States::kTitleState);
        }
    }

    return ALLOW_OTHER_UPDATES;
}

void GameplayState::draw() const {
    sf::RenderWindow& window = *getContext().window;

    window.draw(text_);
    window.draw(circle_);
}
