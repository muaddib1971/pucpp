#include "window.h"
#pragma once
namespace draughts
{
    namespace ncview
    {
        class add_player_window : public window
        {
            public:
            virtual void activate(void) override;
            virtual ~add_player_window(void){}
        };
    }
}
