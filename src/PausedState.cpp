#include "PausedState.h"
#include "Utility.h"

#include <SFML/Graphics/RectangleShape.hpp>

PausedState::PausedState(StateManager& manager, Context context) :
    State(manager, context)
{
    paused_text_.setString("Game Paused");
    paused_text_.setColor(sf::Color::White);
    paused_text_.setFont(context.fonts->get(Fonts::kDefaultFont));
    paused_text_.setCharacterSize(50);
    Utility::centerOrigin(paused_text_);

    auto size = context.window->getSize();
    paused_text_.setPosition( size.x/2, size.y/2);
}


bool PausedState::update(sf::Time delta_time){
    return SUPRESS_OTHER_UPDATES;
}

bool PausedState::handleEvent(const sf::Event& event){
    if (event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::P){
            requestStatePop();
        }
    }

    return SUPRESS_OTHER_UPDATES;
}

void PausedState::draw() const {
    sf::RenderWindow& window = *getContext().window;

    sf::RectangleShape background;
    background.setFillColor( sf::Color(0, 0, 0, 150) );
    background.setSize(sf::Vector2f(window.getSize()));

    window.draw(background);
    window.draw(paused_text_);
}
