#ifndef STATE_H_
#define STATE_H_

#include "ResourceHolder.h"
#include "StateManager.h"
#include "Identifier.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

class State {
    public:
        typedef std::unique_ptr<State> Ptr;

        struct Context {
            Context(sf::RenderWindow& window,
                    TextureHolder& textures,
                    FontHolder& fonts);

            sf::RenderWindow* window;
            sf::TextureHolder* textures;
            sf::FontHolder* fonts;
        };

        State(StateManager& manager, Context context);

        virtual void update(sf::Time delta_time) = 0;
        virtual void draw() const = 0;
        virtual void handleEvent(const sf::Event& event) = 0;

        // virtual void onEnter(){}
        // virtual void onExit(){}

        // virtual void onHidden(){}
        // virtual void onRevealed(){}
    protected:
        void requestStatePush(States::ID id);
        void requestClearToState(States::ID id);
        void requestStatePop();

        Context getContext() const;
    private:
        States::ID id_;
        Context context_;
        StateManager* manager_;
};

#endif /* STATE_H_ */
