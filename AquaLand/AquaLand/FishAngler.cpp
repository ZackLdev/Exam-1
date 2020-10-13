/**
* \file FishAngler.cpp
*
* \author Charles B. Owen
*/

#include "pch.h"
#include <string>
#include "FishAngler.h"
#include "Aquarium.h"
#include "ItemVisitor.h"


using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishStinkyImageName = L"images/angler.png";

/// How near a fish must be for use to catch it
const double CatchDistance = 150;

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishAngler::CFishAngler(CAquarium* aquarium) : CItem(aquarium)
{
    mFishImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishStinkyImageName.c_str()));
    if (mFishImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += FishStinkyImageName;
        AfxMessageBox(msg.c_str());
    }
}


/**
* Destructor
*/
CFishAngler::~CFishAngler()
{
}


/**
* Draw this item
* \param graphics Graphics device to draw on
*/
void CFishAngler::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mFishImage->GetWidth();
    double hit = mFishImage->GetHeight();
    graphics->DrawImage(mFishImage.get(),
        float(GetX() - wid / 2), float(GetY() - hit / 2),
        (float)mFishImage->GetWidth(), (float)mFishImage->GetHeight());
}


/**
* Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CFishAngler::HitTest(int x, int y)
{
    double wid = mFishImage->GetWidth();
    double hit = mFishImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mFishImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mFishImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}


/**
 * Set the location of a Fish.
 *
 * \param x X location (pixels)
 * \param y Y location (pixels)
 */
void CFishAngler::SetLocation(double x, double y)
{
    double dx = x - GetX();
    double dy = y - GetY();

    CItem::SetLocation(x, y);

    auto closest = GetAquarium()->ClosestItem(this, CatchDistance);
    if (closest != nullptr)
    {
        mCaught = closest;
    }

    auto caught = mCaught.lock();
    if (caught != nullptr)
    {
        caught->Move(dx, dy);
    }
}

/**
* Accecpt an item visitor
* \param visitor  The visitor
*/
void CFishAngler::Accept(CItemVisitor* visitor)
{
    visitor->VisitFishAngler(this);
}