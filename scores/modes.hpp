#pragma once
#include <cstdint>

namespace bancho::scores::modes {
    enum Mode : uint8_t {
        VN_OSU,
        VN_TAIKO,
        VN_CATCH,
        VN_MANIA,
        RX_OSU,
        RX_TAIKO,
        RX_CATCH,
        AP_OSU
    };

    enum CustomMode : uint8_t {
        VANILLA,
        RELAX,
        AUTOPILOT
    };
}

// This looks cursed and idk if it even works. This is the single reason we are not using C++ enums.
#define MODE_AS_VN(mode) mode == bancho::scores::modes::Mode.AP_OSU ? Mode.VN_OSU : (bancho::scores::modes::Mode)((uint8_t)mode % 4)
#define CMODE_FROM_MODE(mode) mode == bancho::scores::modes::Mode.AP_OSU ? CustomMode.AUTOPILOT : (bancho::scores::modes::CustomMode)((uint8_t)mode / 4)
