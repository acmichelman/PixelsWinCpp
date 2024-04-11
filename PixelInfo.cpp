#include "pch.h"
#include "Systemic/Pixels/PixelInfo.h"

#include "Systemic/Pixels/DiceUtils.h"

namespace Systemic::Pixels
{
    int PixelInfo::dieFaceCount()
    {
        return DiceUtils::getFaceCount(dieType());
    }
}
