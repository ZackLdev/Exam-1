/**
 * \file Aquarium.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "Aquarium.h"

#include "FishBeta.h"

using namespace std;
using namespace Gdiplus;


/**
 * Aquarium constructor
 */
CAquarium::CAquarium()
{
    mBackground = unique_ptr<Gdiplus::Bitmap>(
        Bitmap::FromFile(L"images/background1.png"));
    if (mBackground->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/background1.png");
    }

}

/**
 * Draw the aquarium
 * \param graphics The GDI+ graphics context to draw on
 */
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
    graphics->DrawImage(mBackground.get(), 0, 0,
        mBackground->GetWidth(), mBackground->GetHeight());

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 16);

    SolidBrush green(Color(0, 64, 0));
    graphics->DrawString(L"Under the Sea!", -1,
        &font, PointF(2, 2), &green);

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

}


/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}


/** Move an item to the front of the list of items.
*
* Removes item from the list and adds it to the end so it
* will display last.
* \param item The item to move
*/
void CAquarium::MoveToFront(std::shared_ptr<CItem> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }

    mItems.push_back(item);
}

/**
 * Find the closest item in the aquarium to some other item
 * that is also less than the maximum possible distance
 * \param closestTo Pointer to an item we are finding closests items to
 * \param within Only return items closer than within range
 * \return Captured item or nulptr if none.
 */
std::shared_ptr<CItem> CAquarium::ClosestItem(CItem* closestTo, double within)
{
    // Keep track of the closest item we have found
    // and how far away it was.
    shared_ptr<CItem> closest = nullptr;
    double closestDistance = 0;

    // Iterate over all of the items
    for (auto item : mItems)
    {
        // Don't test item against itself
        if (item.get() == closestTo)
        {
            continue;
        }

        double distance = closestTo->Distance(item);

        // Ignore if too far away
        if (distance > within)
        {
            continue;
        }

        // If first thing we found or nearer than what
        // we found before, this is the new closest item
        if (closest == nullptr || distance < closestDistance)
        {
            // We have a new closest item
            closest = item;
            closestDistance = distance;
        }
    }

    return closest;
}

/**
* Accept a visitor for the collection of items
* \param visitor The visitor for the collection
*/
void CAquarium::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}