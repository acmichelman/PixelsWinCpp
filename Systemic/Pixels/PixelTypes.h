/**
 * @file
 * @brief Common types used across the Systemic::Pixel namespace.
 */

#pragma once

#include <cstdint>

//! \defgroup Pixels
//! @brief A collection of C++ classes and types to scan for and connect to Pixels dice.
//!
//! @see Systemic::Pixels namespace.

/**
 * @brief A collection of C++ classes and types to scan for and connect to Pixels dice.
 *
 * @ingroup Pixels
 */
namespace Systemic::Pixels
{
    /// Type for a Pixel Id.
    using pixel_id_t = uint32_t;

    /// The different types of dice.
    enum class PixelDieType : uint8_t
    {
        Unknown = 0,
        D4,
        D6,
        D8,
        D10,
        D00,
        D12,
        D20,
        D6Pipped,
        D6Fudge,
    };

    /// Available Pixels dice colorways.
    enum class PixelColorway: uint8_t
    {
        Unknown = 0,
        OnyxBlack,
        HematiteGrey,
        MidnightGalaxy,
        AuroraSky,
        Clear,
        Custom = 0xFF,
    };

    /// Pixel roll states.
    enum class PixelRollState : uint8_t
    {
        /// The Pixel roll state could not be determined.
        Unknown = 0,

        /// The Pixel is resting in a position with a face up.
        OnFace,

        /// The Pixel is being handled.
        Handling,

        /// The Pixel is rolling.
        Rolling,

        /// The Pixel is resting in a crooked position.
        Crooked,
    };

    /// The different possible battery charging states.
    enum class PixelBatteryState : uint8_t
    {
        /// Battery looks fine, nothing is happening.
        Ok = 0,

        /// Battery level is low, notify user they should recharge.
        Low,

        /// Battery is currently recharging.
        Charging,

        /// Battery is full and finished charging.
        Done,

        /// Coil voltage is bad, die is probably positioned incorrectly.
        /// Note that currently this state is triggered during transition between charging and not charging...
        BadCharging,

        /// Charge state doesn't make sense (charging but no coil voltage detected for instance).
        Error,
    };
}
