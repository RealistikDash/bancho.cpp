#pragma once
#include <cstdint>
#include "../maths/position.hpp"
#include "../scores/modes.hpp"

namespace bancho::user {
    // A class representing the user's current ingame action.
    
    struct Action {
        enum Actions: uint8_t {
            IDLE,
            AFK,
            PLAYING,
            EDITING,
            MODDING,
            MULTIPLAYER,
            WATCHING,
            UNKNOWN,
            TESTING,
            SUBMITTING,
            PAUSED,
            LOBBY,
            MULTIPLAYING,
            OSUDIRECT
        };

        Actions id;
        char* text;
        char* bmap_md5;
        int32_t bmap_id;
        uint32_t mods;
    };

    // A class representing the user's stats for a specific mode.
    struct Stats {
        int64_t total_score;
        int64_t ranked_score;
        uint16_t pp; // It is i16 in packets, but in modes such as rx we can exceed that.
        int32_t play_count;
        float accuracy;
        uint16_t max_combo;
        int32_t rank;
    };

    // A class representing an online user.
    class User {
    public:
        int32_t id;
        char* name;
        char* safe_name;
        char* uuid; // We know the capacity. Maybe make it a char[17]?
        Action action;
        Stats stats[8];
        bancho::maths::Vector2<float> position;
    };
}
