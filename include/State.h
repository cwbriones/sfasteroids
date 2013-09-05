#ifndef STATE_H_
#define STATE_H_

#include "ResourceHolder.h"
#include "Identifier.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

class StateManager;

class State {
    public:
        typedef std::unique_ptr<State> Ptr;

        struct Context {
            Context(sf::RenderWindow& window,
                    TextureHolder& textures,
                    FontHolder& fonts);

            sf::RenderWindow* window;
            TextureHolder* textures;
            FontHolder* fonts;
        };

        State(StateManager& manager, Context context);

        virtual bool update(sf::Time delta_time) = 0;
        virtual bool handleEvent(const sf::Event& event) = 0;
        virtual void draw() const = 0;

        // Not including these because any work that needs to be done
        // in these cases can be done in the constructor/destructor
        //
        // virtual void onEnter(){}
        // virtual void onExit(){}

        virtual void onHidden(){}
        virtual void onRevealed(){}
    protected:
        void requestStatePush(States::ID id);
        void requestClearToState(States::ID id);
        void requestStatePop();
        void requestClearAll();

        Context getContext() const;

        static const bool ALLOW_OTHER_UPDATES = true;
        static const bool SUPRESS_OTHER_UPDATES = false;
    private:
        Context context_;
        StateManager* manager_;
};

#endif /* STATE_H_ */
