/**
* \file FishMolly.h
*
* \author Charles B. Owen
*
* Class the implements a Molly fish
*/

#pragma once

#include <memory>

#include "Item.h"


class CItemVisitor;


/**
* Implements a Molly fish
*/
class CFishMolly : public CItem
{
public:
    CFishMolly(CAquarium *aquarium);

    /// Default constructor (disabled)
    CFishMolly() = delete;

    /// Copy constructor (disabled)
    CFishMolly(const CFishMolly &) = delete;

    ~CFishMolly();

    virtual void Draw(Gdiplus::Graphics *graphics) override;
    virtual bool HitTest(int x, int y) override;


    virtual void Accept(CItemVisitor* visitor);

private:
    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};