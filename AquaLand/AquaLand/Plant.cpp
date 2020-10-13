/**
 * \file Plant.cpp
 *
 * \author CSE 335 Course Staff
 */

#include "pch.h"
#include "Plant.h"


/**
* Constructor: Create a new CPlant.
* \param name  The name of the plant
* \param description A description of the plant
*/
CPlant::CPlant(std::wstring name, std::wstring description) 
    : mName(name)
    , mDescription(description)
{
}

/**
* Retrieve the description for the plant
* \return The description for the plant
*/
std::wstring CPlant::DisplayDescription()
{
    return mName + L": " + mDescription;
}


/**
* Retreive which fish are incompatible with the plant
* \returns A string containing a list of incompatible fish
*/
std::wstring CPlant::DisplayIncompatible()
{
    std::wstring result;
    for (auto incompatible : mIncompatible)
    {
        result += incompatible + L" ";
    }

    return result;
}

/**
 * Add an incompatible fish to this plant
 * @param incompatible Name of the incompatible fish.
 */
void CPlant::AddIncompatibleFish(std::wstring incompatible)
{
    mIncompatible.push_back(incompatible);
}
