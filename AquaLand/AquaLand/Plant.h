/**
 * \file Plant.h
 *
 * \author CSE 335 Course Staff
 */

#pragma once

#include <string>
#include <vector>

/**
 * This class represents aquatic plants.
 * 
 * Some aquatic plants are not compatible with specific
 * types of fish.  We would like to be able to
 * know which fish are not compatible with them.
 * 
 * You are NOT allowed to change this class!
 */
class CPlant
{
public:
    CPlant() = delete;

    CPlant(std::wstring name, std::wstring description);

    virtual ~CPlant() {}

    // Return the description of the plant
    virtual std::wstring DisplayDescription();

    // Return a string containing fish incompatible with this plant
    virtual std::wstring DisplayIncompatible();

    // Add fish name that is incompatible with the plant
    void AddIncompatibleFish(std::wstring incompatible);

private:
    std::wstring mName;         ///< Name of the plant
    std::wstring mDescription;  ///< Description of the plant

    /// Vector of incompatible fish names
    std::vector<std::wstring> mIncompatible;
};

