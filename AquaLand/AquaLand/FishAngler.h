/**
* \file FishAngler.h
*
* \author Charles B. Owen
*
* Class the implements an Angler fish
*/

#pragma once
#include "Item.h"
#include <memory>

/**
* Implements an Angler Fish
*/


class CPredatorPreyBalance;

class CFishAngler :
    public CItem
{
public:
    /// Default constructor (disabled)
    CFishAngler() = delete;

    /// Copy constructor (disabled)
    CFishAngler(const CFishAngler&) = delete;

    CFishAngler(CAquarium* aquarium);

    virtual ~CFishAngler();
    virtual void Draw(Gdiplus::Graphics* graphics) override;
    virtual bool HitTest(int x, int y) override;

    virtual void SetLocation(double x, double y) override;

    virtual void Accept(CItemVisitor* visitor) override;

private:
    /// Any currently caught item
    std::weak_ptr<CItem> mCaught;

    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

