#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

namespace Textures {
    enum Identifier {
        kEmpty
    };
};

namespace Fonts {
    enum Identifier {
        kDefaultFont
    };
};

namespace States {
    enum ID {
        kNullState,
        kTitleState,
        kMainMenuState,
        kGameplayState,
        kLoadingState,
        kPausedState
    };
};

#endif /* IDENTIFIER_H_ */
