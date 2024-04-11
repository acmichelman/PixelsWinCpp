/**
 * @file
 * @brief Some helper functions for Pixels.
 */

#pragma once

#include <cstdint>
#include <chrono>
#include "PixelTypes.h"

namespace Systemic::Pixels::DiceUtils
{
	/**
	 * @brief Try to derive the die type from number of LEDs.
	 * @param ledCount Number of LEDs on Pixels die.
	 * @return The die type for the given number of LEDs.
	 */
	inline PixelDieType estimateDieType(int ledCount)
	{
		switch (ledCount)
		{
		case 4:
			return PixelDieType::D4;
		case 6:
			return PixelDieType::D6;
		case 8:
			return PixelDieType::D8;
		case 10:
			return PixelDieType::D10;
		case 12:
			return PixelDieType::D12;
		case 20:
			return PixelDieType::D20;
		case 21:
			return PixelDieType::D6Pipped;
		default:
			return PixelDieType::Unknown;
		}
	}

	/**
	 * @brief Returns the number of faces based on the die type.
	 * @param dieType The Pixels die type.
	 * @return The number of faces for the given die type.
	 */
	inline int getFaceCount(PixelDieType dieType)
	{
		switch (dieType)
		{
		default:
		case PixelDieType::D20:
			return 20;
		case PixelDieType::D12:
			return 12;
		case PixelDieType::D10:
			return 10;
		case PixelDieType::D8:
			return 8;
		case PixelDieType::D6:
		case PixelDieType::D6Pipped:
		case PixelDieType::D6Fudge:
			return 6;
		case PixelDieType::D4:
			return 4;
		}
	}

	inline int getFaceFromIndex(int faceIndex, PixelDieType dieType)
	{
		switch (dieType)
		{
			case PixelDieType::D10:
				return faceIndex;
			case PixelDieType::D00:
				return faceIndex * 10;
			case PixelDieType::Unknown:
				return faceIndex;
			default:
				return faceIndex + 1;
		}
	}

	/**
	 * @brief
	 * @param batteryState
	 * @return
	 */
	inline bool isPixelChargingOrDone(PixelBatteryState batteryState)
	{
		return batteryState == PixelBatteryState::Charging || batteryState == PixelBatteryState::Done;
	}

	/**
	 * @brief Converts a UNIX timestamp in seconds to a `time_point`.
	 * Use this function to get the date of a Pixels firmware from its timestamp.
	 * @param buildTimestamp UNIX timestamp in seconds.
	 * @return The `time_point` value for the given timestamp.
	 */
	inline std::chrono::system_clock::time_point getFirmwareDate(uint32_t buildTimestamp)
	{
		return std::chrono::system_clock::time_point{ std::chrono::seconds{ buildTimestamp } };
	}
}
