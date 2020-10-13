/**
 * \file Item.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"


 /** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}


/**
 * Determine the distance from this item to some other item.
 * \param other Other item we are testing
 * \return Distance in pixels
 */
double CItem::Distance(std::shared_ptr<CItem> other)
{
    // Create a vector in the direction we are from the nudger
    double dx = mX - other->mX;
    double dy = mY - other->mY;

    // Determine how far away we are
    return sqrt(dx * dx + dy * dy);
}


